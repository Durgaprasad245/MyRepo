# File System Traversal Tool

This program is a simple file system traversal tool implemented in C. It allows users to recursively traverse directories, applying various filters and performing actions on files based on command-line arguments.

## Features

- Traverse directories recursively.
- Filter files based on size, filename substring, and file type.
- Print information about files that meet specified criteria.
- Option to control verbosity level.

## Usage

Compile the program using a C compiler such as gcc:

gcc -o dnuthala_HW02 dnuthala_HW02.c


Run the program with optional command-line arguments:

./dnuthala_HW02 [OPTIONS] [DIRECTORY]

Traverse the current directory without any filters:

./dnuthala_HW02

Traverse a specific directory with verbose mode and filter files by size:

./dnuthala_HW02 -v -L 1000 /path/to/directory

Traverse directories with filename substring filter:

./dnuthala_HW02 -s "example" 2 /path/to/directory

Traverse directories with file type filter:

./dnuthala_HW02 -t f /path/to/directory

