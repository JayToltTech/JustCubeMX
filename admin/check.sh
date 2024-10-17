#!/opt/homebrew/bin/bash
cd "${0%/*}" # Change to cwd of script
shopt -s globstar

# cppcheck -j$(nproc) --enable=portability --enable=style --force --addon=libraries/cppcheck-addons/misra.json main.c


# replace '-fanalyser' with '' in compile_commands.json since clang-tidy can't handle this flag
sed -i'' -e 's/-fanalyzer//g' ../build/compile_commands.json

#!/usr/bin/env bash

cd ..
# clang-tidy -p build *.[ch] libraries/rnbd451/**/*.[ch] libraries/sercom/**/*.[ch] libraries/tt-log/**/*.[ch] libraries/cmsis_usart/*.[ch] libraries/cmsis_usart/Drivers/SAME54/*.[ch]

# libraries/gcc-include excluded as it runs clean except for a code generated error about include path
clang-tidy -p build *.[ch] libraries/embos/**/*.[ch]

