# Gaussian Elemination

An implementation of the Gauss-Jordan Algorithmn for computing linear systems of equations. It's main purpose is to show the solving steps while solving the system. The programm can also identify free variables and add handle them normally. At the end the affine space is printed.

## Building
To build the project you only need GNU Make installed.
```sh
$ mkdir obj/ bin/
$ make build
```

## Running
Build and run the programm:
```sh
$ ./bin/main
```

## Testing
The Makefile builds the programm and runs the programm on all the files in `./test_data`.
```sh
$ make test
```

**Warning: This project was created with educational purpose in mind. So any bugs may never be fixed.**
