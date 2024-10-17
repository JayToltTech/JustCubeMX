#!/bin/bash
cd "${0%/*}" # Change to cwd of script
mkdir -p ../build && cd ../build

cmake -S .. -B . -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON --trace-source=CMakeLists.txt --trace-expand
ninja -C . -j 10

if [ $? -ne 0 ]; then
    exit $status
fi

arm-none-eabi-objcopy -O ihex JustCubeMX.elf JustCubeMX.hex
arm-none-eabi-objcopy -O binary JustCubeMX.elf JustCubeMX.bin

# jlinkexe -CommandFile ../admin/flash.jlink

cd ..