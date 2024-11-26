# get_next_line

**Reading a line from a file descriptor is way too tedious—let's fix that!**

---

## Summary

The **get_next_line** project challenges you to implement a function in C that reads and returns a single line from a file descriptor. This project emphasizes efficient buffer handling, dynamic memory management, and the use of static variables to maintain state between function calls.

---

## Features

### Core Functionality

- **Line-by-Line Reading**:
  - Reads and returns a single line from a file descriptor (including the trailing newline, if present).
  - Handles both regular files and standard input.

- **Static Variable**:
  - Uses a static variable to persist data between function calls for seamless reading.

- **Buffer Management**:
  - Efficiently handles varying buffer sizes defined at compile time.

- **Error Handling**:
  - Returns `NULL` on errors or when the end of the file is reached.

### Bonus Features (Optional)

- **Multiple File Descriptors**:
  - Manages multiple file descriptors concurrently without losing state or mixing lines between them.

- **Memory Optimization**:
  - Implements logical handling of edge cases, such as large or very small buffer sizes.

---

## Structure

### Directories and Files

#### `src/`

- **`get_next_line.c`**:
  Implements the main logic for reading and returning lines from a file descriptor.
- **`get_next_line_utils.c`**:
  Utility functions for string manipulation (`ft_strjoin`, `ft_strlen`, etc.) and buffer management.

#### `includes/`

- **`get_next_line.h`**:
  Declares the prototype for `get_next_line` and its helper functions. Defines macros like `BUFFER_SIZE`.

#### Bonus Files (Optional)

- **`get_next_line_bonus.c`**:
  Enhanced functionality to handle multiple file descriptors.
- **`get_next_line_utils_bonus.c`**:
  Utility functions supporting the bonus implementation.
- **`get_next_line_bonus.h`**:
  Header file for the bonus implementation.

### Key Files

- **Makefile**:
  Automates compilation with targets for mandatory and bonus parts:
  - `all`, `clean`, `fclean`, `re`, and `bonus`.

---

## Examples

1. **Basic Usage**:
   ```c
   #include "get_next_line.h"
   #include <fcntl.h>
   #include <stdio.h>

   int main(void)
   {
       int fd = open("example.txt", O_RDONLY);
       char *line;

       while ((line = get_next_line(fd)) != NULL)
       {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return (0);
   }
   ```
Compilation:
```
make
```

## Requirements
**Mandatory Part**
Function Name: get_next_line
Prototype: char *get_next_line(int fd);

**Allowed Functions:** read, malloc, free

**Forbidden:** lseek, global variables, and your libft.

## Bonus Part
Handles multiple file descriptors simultaneously.
Uses a single static variable to manage state per file descriptor.
Compilation and Testing

**Compile the Project:**

```
make
```
Run Tests:

Test with varying buffer sizes:
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c -o gnl_test
./gnl_test
```

Test with:

Small buffer size (BUFFER_SIZE=1).
Large buffer size (BUFFER_SIZE=9999).

Bonus Compilation:

```
make bonus
```

get_next_line – A practical utility to make file reading smoother! 🚀
