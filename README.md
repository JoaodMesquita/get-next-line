*This project has been created as part of the 42 curriculum by **joapedro**.*

# 📄 Get Next Line – 42 Project

## 📖 Description

**Get Next Line (GNL)** is a foundational project from the 42 curriculum that focuses on reading a file line by line.

The goal is to implement a function that returns one line at a time from a file descriptor, handling input efficiently regardless of the file size or buffer size.

Each call to the function should:

* Read from a file descriptor
* Return the next line (including the newline character, if present)
* Preserve the remaining data for the next call

This project introduces:

* Static variables for state persistence
* File descriptor handling
* Memory management and buffer control
* Efficient reading using the `read` system call

---

## ⚙️ Instructions

### 🛠️ Compilation

Clone the repository and compile the project:

```bash id="2l7x9q"
git clone <your-repository-url>
cd get_next_line
make
```

This will generate the necessary object files and library (depending on your setup).

---

### 🚀 Usage

### 📌 Function Prototype

```c id="o6b4nm"
char *get_next_line(int fd);
```

### ▶️ Example

```c id="9d2k1v"
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

## 🔄 How It Works

1. A buffer of size `BUFFER_SIZE` is used to read from the file descriptor.
2. Data is stored in a static variable to persist between function calls.
3. The function extracts a line up to `\n` (or EOF).
4. The remaining data is kept for the next invocation.
5. Memory is allocated dynamically for each returned line.

---

## ⚠️ Notes

* The function must handle multiple file descriptors independently (bonus part).
* Memory leaks must be avoided.
* The returned line must be properly null-terminated.
* Reading should stop as soon as a full line is available.

---

## 📚 Resources

### System Calls

* `man 2 read`
* `man 2 open`
* `man 2 close`

### Memory Management

* `man 3 malloc`
* `man 3 free`

### File Descriptors

* https://en.wikipedia.org/wiki/File_descriptor

### Debugging Tools

* `valgrind`
* `gdb`

---