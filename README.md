##get_next_line – Reading a File Line by Line 📄✨


<div align="center">

<a>![42 Badge](https://github.com/elbarry42/elbarry42/blob/main/42_badges/get_next_linem.png)</a>

</div>

*This project has been created as part of the 42 curriculum by elbarry.* 

Welcome to **get_next_line**! 🎉 The goal of this project is to program a function that returns a line read from a file descriptor. It is a key step in learning memory management and the important concept of **static variables** in C programming. 

---

##📝 Description
`get_next_line` is a function designed to read text from a file descriptor (fd) one line at a time. Whether reading from a regular file or from standard input, the function returns the line that was read, including the terminating `\n` character (except if the end of file is reached without a newline). 

**Key Goals:** 

* Implement a robust solution for reading data chunks using a buffer.
* Master the use of **static variables** to preserve data between function calls. 


* Manage dynamic memory allocation (`malloc`/`free`) without leaks. 


* Adhere to the strict coding standards of **The Norm**. 



---

##⚙️ How It Works (Algorithm)
The function uses a buffer of size `BUFFER_SIZE` to read from the file descriptor. 

1. **Read & Accumulate:** It calls `read()` to get data and appends it to a static variable until a newline character (`\n`) is found or the end of the file is reached. 


2. **Extract Line:** Once a newline is found, the function extracts the string up to the `\n` to return it. 


3. **Save Remainder:** Any data read *after* the newline is kept in the **static variable** so it can be processed during the next call to `get_next_line`. 


4. **Cleanup:** If an error occurs or there is nothing left to read, the function returns `NULL`. 



---

##📚 Project Structure
Mandatory Part 

* `get_next_line.c`: Main logic.
* `get_next_line_utils.c`: Helper functions needed for the implementation. 


* `get_next_line.h`: Header file containing the prototype. 



Bonus Part 
The bonus files include the suffix `_bonus`:

* `get_next_line_bonus.c`
* `get_next_line_bonus.h`
* `get_next_line_utils_bonus.c`

---

##🔧 Function Prototype

```c
char *get_next_line(int fd);

```

| Component | Description |
| --- | --- |
| **Prototype** | <br>`char *get_next_line(int fd);` 

 |
| **Parameters** | <br>`fd`: The file descriptor to read from. 

 |
| **Return Value** | The read line (correct behavior) or `NULL` (nothing left to read or error). 

 |
| **External Functions** | <br>`read`, `malloc`, `free`. 

 |

---

##🛠️ Instructions (Compilation)

The project must be compiled with the `-D BUFFER_SIZE=n` flag to define the buffer size for `read()`. 

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

```

> [!IMPORTANT]
> The code must compile with and without the `-D BUFFER_SIZE` flag. It must also handle various buffer sizes, from 1 to 10,000,000. 
> 
> 

---

##⭐ Bonus Features

The bonus part is evaluated only if the mandatory part is perfect.  It requires:

1. **Single Static Variable:** Using only one static variable to manage the state. 


2. **Multiple File Descriptors:** The ability to manage multiple file descriptors at the same time (e.g., reading from fd 3, then 4, then 5, then back to 3) without losing the reading state of any of them. 



---

##📖 Resources
**Classic References:**

* C Programming: Static Variables.
* File Descriptors and the `read()` function.
* Memory management in C.

---

##🚀 Learning Outcomes* 
**Foundational Tech:** Deep understanding of file I/O and memory allocation. 


* **Problem Solving:** Developed the ability to find solutions through reasoning rather than shortcuts. 


* **Peer Learning:** Exchanging ideas with peers to improve divergent thinking and interpersonal skills. 
