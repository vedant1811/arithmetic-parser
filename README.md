# Arithmetic Parser

Evaluates simple arithmethic expressions. Reads only single digit numbers, 4 binary
operators (`+ - * -`) and brackets `()`. Additionally, the `space` char is ignored.

*See the [ValidInputsTest](test/parser/ValidInputsTest.cpp) file for examples*

## Dependencies

1. Boost Unit Test Framework

## Installation

Install as a standard cmake project:

```
mkdir build
cd build
cmake ..
make
```


## Usage

From the `build` dir:

```
$ ../bin/parse "3 + 1"
```

## Testing

After Installing, run the tests by

```
make test
```

OR

```
ctest --verbose
```
