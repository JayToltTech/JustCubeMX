#!/bin/bash

clang-format -i *.c *.h

# Recursive, see https://stackoverflow.com/questions/28896909/how-to-call-clang-format-over-a-cpp-project-folder
# find . -iname *.h -o -iname *.c | xargs clang-format -i
# clang-format -i **/*.c **/*.h