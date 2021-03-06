# grammar-analyzer

This project implements a bottom-up grammar analyzer using an automaton.
It aims at analysing and executing the arithmetic grammar, thus supporting simple mathematics operations such as additions (+), subtractions (-), multiplication (*) and parentheses priority

## Executable

You can run the executable in 2 different ways :

### `./main`

Runs the analyzer. You just have to enter if you want to evaluate the negative numbers or not as well as the expression to analyze.

### `./main "18+19" [-neg]`

Run the analyzer only once. The analyzer evaluates the expression in parameter and considers negative integer if -neg is defined.

## Makefile 

### `make`

Compiles source files, generates binary files and creates the project executable.

### `make map`

Compiles source files, generates binary files and creates the project executable with debug mod.

### `make run`

Runs the executable

### `make memcheck`

Executes the .exe with valgrind to check the use of memory

### `make clean`

Deletes compiled files

## Tests

In order to run the tests access the Tests folder with the command `cd ./Tests`

Run all tests with the command `./mktest.sh`

All these tests were performed and validated during development.