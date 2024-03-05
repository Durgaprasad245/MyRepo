# Directory Search Program

This C program provides functionality to search directories for files based on specified criteria and execute UNIX commands on the matching files.

## Features

- Search for files based on size, name, and depth criteria.
- Execute UNIX commands on matching files using the `-e` option.
- Execute UNIX commands using all matching files as arguments with the `-E` option.
- Supports verbose output with the `-v` option.
- Traverse directories recursively.

### Compilation

Compile the program using the provided Makefile:

make # Compile all the files
make run # Run the compiled program
make run ARGS="<your args here>" # Run the program with custom arguments
make run ARGS="a.txt b.txt" # Run the program with the arguments "a.txt" and "b.txt"


```bash
make

The program supports the following command-line options:

-v  -L  -s  -t  -e  -E 

Examples:

./search -v -L 1000000 -s example 3

./search -v -e "ls -l"

./search -v -E "grep pattern"
