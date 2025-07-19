#!/usr/bin/env bash
if ! ( [ -e "raylib-source.tar.gz" ] || [ -e "raylib-5.5" ] ); then
  curl -L https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz --output raylib-source.tar.gz
  tar -xzf raylib-source.tar.gz
fi
cd src
dyalogscript "convert_pointerArgs.apls"
cd ..
cd raylib-5.5/src
make clean
echo '#include "../../src/temp-c-raylib.c"' >> rcore.c
echo $@
make RAYLIB_LIBTYPE=SHARED $@
sed -i.backup '$ d' rcore.c
cp -f libraylib.550.dylib ../../libtemp-c-raylib.dylib
cd ../../
