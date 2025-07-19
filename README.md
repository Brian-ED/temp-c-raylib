# Temp-c-raylib for Dyalog ⎕NA
Temp-c-raylib is for temporary raylib changes to be able to use ⎕NA with less issues in Dyalog APL. Currently only targets raylib 5.0, though with some modifications can target other versions.

This library is intended for use with [raylib-apl](https://github.com/Brian-ED/raylib-apl).

# Download
For the latest pre-built library files, visit the [Releases page](https://github.com/Brian-ED/temp-c-raylib/releases) and download the appropriate file for your platform:
- **Linux**: `libtemp-c-raylib.so`
- **macOS**: `libtemp-c-raylib.dylib`
- **Windows**: `temp-c-raylib.dll`

# Compile
On Linux run `runNewMakeRaylib.bash`.

On Windows run `runNewMakeRaylib.ps1`. It assumes you're using `zig cc` as your compiler. If you want to use another one, look in the script and copy the args given to `zig cc` and give it to `Clang`, since `zig cc` is pretty much clang. I have no idea about gcc.

On macOS run `runNewMakeRaylibMac.bash`.

# GitHub Actions
This repository includes a GitHub Actions workflow that automatically builds the library for all three platforms (Linux, macOS, and Windows) on every push and pull request. The workflow is located at `.github/workflows/build.yml`.

The workflow includes:
- **Automatic builds**: Builds are triggered on pushes to master, pull requests, and manual workflow dispatch
- **Release creation**: Can create releases with build artifacts when manually triggered with the `create_release` input (requires updating the VERSION file first)
- **Dyalog APL installation**: Automatically downloads and installs Dyalog APL 19.0 on each platform
- **Artifact collection**: Collects and uploads build artifacts for each platform

The workflow automatically downloads and installs Dyalog APL on each platform.

The APL conversion scripts (`convert_pointerArgs.apls`) run properly during the build process to generate the necessary C code.
