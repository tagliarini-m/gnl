# Get Next Line

This project has been created as part of the 42 curriculum by [tagliarini-m].

## Description
The get_next_line (GNL) project is a fundamental exercise in C programming at 42. The goal is to write a function that reads a line from a file descriptor, ending with a newline character, every time it is called.

This project introduces the concept of static variables in C and requires careful management of memory (using malloc and free) to prevent leaks. The function must work efficiently regardless of the buffer size (BUFFER_SIZE) defined at compilation and must be able to manage multiple file descriptors simultaneously in its bonus version.

## Features
Returns one line at a time from a file descriptor.

Handles both file inputs and standard input (stdin).

Uses a single static variable to manage the "remainder" of the string between calls.

Bonus: Supports multiple file descriptors at once without losing the reading thread of any individual file.

## Compilation

The function is designed to be integrated into other projects. To compile it, you need to include the source files and define a BUFFER_SIZE:


`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c`

## Usage

To use get_next_line in your code, include the header:

```
C

#include "get_next_line.h"
```

Then, you can call it in a loop to read a whole file:

```
C

int fd = open("example.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Technical Choices
Static Variables: Used to store data that persists between function calls, allowing the function to "remember" what it read beyond the first newline.

Memory Management: Every malloc is paired with a free to ensure zero memory leaks, even when the BUFFER_SIZE is extremely large or the file ends abruptly.
