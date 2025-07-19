param(
    [switch]$GHDyalog = $false
)

if (!((Test-Path "raylib-source.zip") -or (Test-Path "raylib-5.5"))) {
  Write-Output "Downloading raylib-source.zip"
  $ProgressPreference = 'SilentlyContinue'
  Invoke-WebRequest "https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip" -OutFile "raylib-source.zip"
  tar -xf "raylib-source.zip" -o "raylib-5.5"
}
if (!(Test-Path "raylib-5.5")) {
  Write-Output "Re-unpacking already downloaded raylib-source.zip"
  tar -xf "raylib-source.zip" -o "raylib-5.5"
}

if (!$GHDyalog) {
  cd src
  # Assumes dyalog is installed
  .\convert_pointerArgs.apls
  cd ..
} else {
  cd src
  & "C:\Program Files\Dyalog\Dyalog APL-64 19.0 Unicode\scriptbin\dyalogscript2.ps1" .\convert_pointerArgs.apls
  cd ..
}

cd raylib-5.5/src
make clean
Add-Content -Path "rcore.c" -Value '#include "../../src/temp-c-raylib.c"'
make CC="zig cc -target x86_64-windows" RAYLIB_LIBTYPE=SHARED -s # -Erroraction disables error messages, Since this erroring is intentional.

# Sadly I am copying files, i don't understand why the linker wants .o files and make produces .obj
Copy-Item -Path "rcore.obj" -Destination "rcore.o"
Copy-Item -Path "rshapes.obj" -Destination "rshapes.o"
Copy-Item -Path "rtextures.obj" -Destination "rtextures.o"
Copy-Item -Path "rtext.obj" -Destination "rtext.o"
Copy-Item -Path "utils.obj" -Destination "utils.o"
Copy-Item -Path "rglfw.obj" -Destination "rglfw.o"
Copy-Item -Path "rmodels.obj" -Destination "rmodels.o"
Copy-Item -Path "raudio.obj" -Destination "raudio.o"

make CC="zig cc -target x86_64-windows" RAYLIB_LIBTYPE=SHARED RAYLIB_RES_FILE=""
$content = Get-Content "rcore.c"
$content[0..($content.Length-2)] | Set-Content "rcore.c"
Copy-Item -Force raylib.dll ../../temp-c-raylib.dll
cd ../../
