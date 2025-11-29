# get_next_line – Reading a File Line by Line 📄✨

<div align="center">

<a href="https://github.com/elbarry42/get_next_line">![42 Badge](https://github.com/elbarry42/elbarry42/blob/main/42_badges/get_next_linem.png)</a>

</div>

Welcome to **get_next_line**! 🎉  Its goal is to implement a function in C that reads a file **one line at a time**, no matter the buffer size.

It’s a key step in learning how to manage memory properly, handle static variables, and work efficiently with low-level file operations.

---

## 📝 Project Description

`get_next_line` is a function that returns the next line from a file descriptor each time it is called.
It must handle **any buffer size**, manage memory safely, and work correctly even on very long lines or standard input.

This project teaches:

* how to use **static variables**,
* how to split and reorganize data efficiently,
* how to deal with unpredictable input from files or stdin,
* and how to write clean, robust, modular C code.

---

## ⚙️ How It Works

Each call to `get_next_line(fd)` returns **one full line** from the given file descriptor, **including** the `\n` when present.

When there is nothing left to read, or if an error occurs, it returns **NULL**.

The idea:

1. Read small chunks (`BUFFER_SIZE`) from the file.
2. Accumulate the data until a `\n` is found.
3. Return the line.
4. Save the rest using a static variable for the next call.

---

## 📚 Project Structure

### Mandatory Part

Files included:

```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### Bonus Part

Additional files for multi-FD support:

```
get_next_line_bonus.c
get_next_line_utils_bonus.c
get_next_line_bonus.h
```

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

* **fd** — file descriptor to read from
* **Returns** — a dynamically allocated string containing the next line

---

## 🛠️ Compilation

You can compile the project using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

You must support compilation **with or without** `-D BUFFER_SIZE`.

---

## 🧪 Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int   fd = open("file.txt", O_RDONLY);
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

## ⭐ Bonus Features

The bonus part expands the logic to support:

### ✔️ Only **one static variable**

### ✔️ Handling **multiple file descriptors at the same time**

This means you can alternate:

```
get_next_line(fd1)
get_next_line(fd2)
get_next_line(fd3)
...
```

without losing the reading state for any file descriptor.

---

## 🚀 Learning Outcomes

Through this project, I learned how to:

✅ Manage memory dynamically and avoid leaks <br>
✅ Use static variables safely <br>
✅ Understand how `read()` works at a low level <br>
✅ Split a problem into reusable helper functions <br>
✅ Handle multiple file descriptors <br>
✅ Produce clean, stable code respecting the 42 Norm

---

## 🤝 Contributions

This project was completed as part of the **42 curriculum**.
Suggestions and improvements are always welcome!

---

## 🛡️ License

Project created for educational purposes at **42 Lyon**.
Feel free to reuse or modify the code as part of your learning journey.

---

✨ Thanks for checking out my get_next_line project! 🚀
