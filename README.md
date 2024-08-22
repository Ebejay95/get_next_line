# get_next_line

**A function to read a line from a file descriptor in C.**

This project implements the `get_next_line` function, which reads and returns a line from a file descriptor, handling multiple file descriptors and large files efficiently. It demonstrates a strong understanding of dynamic memory management and buffer handling.

## Structure

### src/

The `src` directory contains the core implementation files:

- **get_next_line.c**: Contains the main function `get_next_line`, responsible for reading characters from a file descriptor until a newline or EOF is found.
- **get_next_line_utils.c**: Includes utility functions such as `ft_strjoin`, `ft_strlen`, and others, which support the main function in managing buffers and strings.

### get_next_line.h

The header file declares the prototypes for `get_next_line` and its helper functions. It also defines necessary macros like `BUFFER_SIZE`.

### Makefile

The Makefile automates the compilation process, creating the necessary object files and executable for testing the `get_next_line` function.

## Features

- **Line Reading**: Efficiently reads one line at a time from a file descriptor, supporting both regular files and standard input.
- **Multiple File Descriptors**: Handles multiple file descriptors concurrently without mixing up data.
- **Buffer Management**: Implements robust buffer handling to ensure optimal memory usage and performance.

## Usage

To compile the project, use the following command:

```
make
```
