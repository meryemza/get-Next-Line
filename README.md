# Get Next Line

*This project has been created as part of the 42 curriculum .*

## 1. Description:

`Get Next Line` is a C project that consists of implementing a function capable of reading and returning a file one line at a time.

The function reads from a file descriptor and returns the next line each time it is called, while correctly handling different buffer sizes and preserving the remaining data between successive calls.

The project provides a deeper understanding of file descriptors, static variables, and buffered input in C.

## 2. Instructions:

### - Compilation :

Build the project:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and the executable/library:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```
## 3. Additional sections:
### **Key concepts:**

This project strengthened my understanding of:

* File descriptors
* `read()`
* Buffer management
* Static variables
* Dynamic memory allocation
* String manipulation
* Multiple file descriptors
* `BUFFER_SIZE`

### **File descriptors:**

A file descriptor is an integer used by the operating system to identify an open file or input/output resource.

`get_next_line` uses a file descriptor to determine which file or input stream should be read.

### **Reading with `read()`:**

The `read()` function is used to retrieve a specific amount of data from the file descriptor.

The amount of data read at each call depends on `BUFFER_SIZE`.

```c
read(fd, buffer, BUFFER_SIZE);
```

### **Static variables:**

A static variable allows the function to preserve its value between successive calls.

This is useful for storing data that has been read but does not yet belong to the current line.

### **Line extraction:**

The function searches for the newline character `\n`.

When a complete line is found, it is returned to the caller while the remaining data is preserved for the next call.


