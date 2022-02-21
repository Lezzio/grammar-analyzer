# grammar-analyzer

TODO :: Description ...

## Executable

You can run the executable in 2 different ways :

### `./main`

Run the analyzer. You just have to enter if you want to evaluate the negative numbers or not as well as the expression to analyze.

### `./main "18+19" [NEGATIVE=TRUE]`

Run the analyzer only once. The analyzer evaluates the expression in parameter and considers negative integer if NEGATIVE=TRUE is defined.

## Makefile 

### `make`

Compiles source files, generates binary files and creates the project executable.

### `make map`

Compiles source files, generates binary files and creates the project executable with debug mod.

### `make run`

Run the executable

### `make memcheck`

Executes the .exe with valgrind to check the use of memory

### `make clean`

Delete compiled files

## Tests

In order to run the tests access the Tests folder with the command `cd ./Tests`

Run all tests with the command `./mktest.sh`

All these tests were performed and validated during development.