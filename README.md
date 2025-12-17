*This project has been created as part of the 42 curriculum by elbarry.*

# get_next_line – Reading a File Line by Line 📄✨

<div align="center">

![42 Badge](https://github.com/elbarry42/elbarry42/blob/main/42_badges/get_next_linem.png)

</div>

Welcome to **get_next_line**! 🎉
This project consists of implementing a C function capable of reading a file **line by line** from a file descriptor, regardless of the buffer size.

It is a core project of the **42 curriculum**, designed to strengthen your understanding of memory management, static variables, and low-level file I/O.

---

## 📝 Description

The goal of **get_next_line** is to write a function that returns a single line from a file descriptor each time it is called.

The returned line:

* Includes the terminating `\n` character if present
* Is dynamically allocated
* Returns `NULL` when there is nothing left to read or when an error occurs

This project focuses on:

* Proper use of **static variables**
* Safe and efficient **memory allocation and deallocation**
* Handling unpredictable input sizes
* Writing clean, modular, and norm-compliant C code

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

* **fd**: file descriptor to read from

### Return Value

* A string containing the next line read
* `NULL` if the end of file is reached or an error occurs

---

## ⚙️ How It Works

Each call to `get_next_line(fd)`:

1. Reads data from `fd` using `read()` with a buffer of size `BUFFER_SIZE`
2. Stores data until a `\n` is found
3. Extracts and returns the line
4. Keeps the remaining data in a **static variable** for the next call

The function must:

* Work with files and standard input
* Handle very small and very large `BUFFER_SIZE` values
* Read as little as possible on each call

---

## 📁 Project Structure

### Mandatory Part

```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

* Helper functions must be placed in `get_next_line_utils.c`
* The header file must contain at least the function prototype

### Bonus Part

```
get_next_line_bonus.c
get_next_line_utils_bonus.c
get_next_line_bonus.h
```

---

## 🛠️ Compilation

The project must compile with or without a defined buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

You may choose any default value for `BUFFER_SIZE`.

---

## 🧪 Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
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

---

## 🚫 Forbidden

* Using **libft**
* Using `lseek()`
* Using **global variables**

Undefined behavior includes:

* Reading from modified files before reaching EOF
* Reading binary files

---

## ⭐ Bonus Requirements

The bonus part must:

* Use **only one static variable**
* Handle **multiple file descriptors simultaneously**

Example:

```
get_next_line(fd3)
get_next_line(fd4)
get_next_line(fd5)
get_next_line(fd3)
```

Each file descriptor must keep its own reading state.

⚠️ The bonus part is evaluated **only if the mandatory part is perfect**.

---

## 🧠 Algorithm Explanation

The algorithm is based on:

* A static buffer to store leftover data
* Repeated reads until a newline is found or EOF is reached
* Splitting the buffer into:

  * The line to return
  * The remaining content for the next call

This approach ensures:

* Minimal reads
* No data loss
* Correct handling of partial lines

---

## 📚 Resources

* Linux `read()` manual
* Static variables in C
* File descriptors and low-level I/O
* Wikipedia: Static variable

### 🤖 AI Usage

AI tools were used **only for documentation assistance and README structuring**.
All algorithm design, logic, and code implementation were done manually, in accordance with the **42 AI policy**.

---

## 📦 Submission

* All required files must be present in the Git repository
* File names must be exact
* Only repository content is evaluated during defense

After validation, this function can be added to **libft**.

---

✨ Thanks for checking out my **get_next_line** project! 🚀
