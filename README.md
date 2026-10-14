*This project has been created as part of the 42 curriculum by jmunoz-j.*

# Get Next Line

## Description

The goal of this project is to program the `get_next_line` function, which reads from a file descriptor and returns a single line each time it is called, ending with its corresponding newline character (`\n`). If called within a loop, it allows reading an entire file line by line efficiently, managing memory strictly without leaving any leaks.

## Algorithm Explanation and Justification

In order to read text in blocks (defined by `BUFFER_SIZE`) and not lose the remaining characters after a newline, the core of the algorithm relies on the use of a **static variable** (`static char *stor`). This variable "remembers" the leftover text between one function call and the next.

In the *Bonus* part, this variable is transformed into an array of pointers (`static char *stor[1024]`), using the `fd` itself as an index to allow reading from multiple files simultaneously without their texts getting mixed up.

The algorithm is logically divided into three main steps or functions:

1. **Reading and Accumulating (`get_line`):**
   We read from the file using `read()` in chunks of `BUFFER_SIZE`. The read data is concatenated to our static variable `stor` using `ft_strjoin`. This process repeats in a loop until a newline character (`\n`) is detected in the accumulated text or until `read` returns 0 (End of File). Special protection has been implemented to properly free memory if `read` returns `-1` (read error).

2. **Extracting the Line (`extract_line`):**
   Once we have the necessary text in `stor`, we iterate through the string until we find the first `\n` (or the end of the string `\0`). We allocate the exact memory required for that line (including the `\n`) using `ft_substr` and return it.

3. **Cleaning the Remainder (`clean_line`):**
   All the text left to the right of the `\n` in our static variable belongs to future lines. We calculate the exact length of this remainder and extract it into a new variable (again, using `ft_substr`). We free the memory of the old `stor` to prevent leaks and update it with this new remainder. If there is no leftover text, the static variable is safely set to `NULL`.

## Compilation and Execution Instructions

To compile the project within your own programs, you must include the source files and define the reading buffer size using the `-D BUFFER_SIZE=n` flag.

**Compilation example (buffer size 42):**

```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

```

**To test the Bonus version (multiple FDs):**

```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c

```

*Note: It is possible to compile without explicitly declaring the `BUFFER_SIZE`, as the `.h` header file includes a safety guard that assigns a default value.*

## Resources and AI Usage

**Learning Resources:**

* [Static Variables in C](https://en.wikipedia.org/wiki/Static_variable) - Fundamental concept for retaining memory state.

* [File Descriptors](https://en.wikipedia.org/wiki/File_descriptor) - Understanding how the OS handles open files.

* Linux Manual Pages (`man read`, `man malloc`, `man free`).

**Artificial Intelligence Usage:**
During the development of this project, AI was used under a strictly pedagogical approach to consolidate knowledge. It was not used to generate direct source code, but rather as a supporting tutor to:

* Understand and interpret tester error messages (e.g., compilation errors).

* Visually trace memory flow to prevent dangling pointers and resolve memory leaks in edge cases like read errors.