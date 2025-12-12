# SafeString Library

## Overview

SafeString is a lightweight C library that provides a safer, more flexible string implementation than traditional C strings. It manages string data with an embedded length counter, preventing common buffer overflow issues and making string operations more efficient.

## Features

- **Automatic memory management**: Strings grow dynamically as needed
- **Length tracking**: Built-in count of characters (excluding null terminator)
- **Bounds safety**: Operations respect allocated memory bounds
- **Simple API**: Easy-to-use functions for common string operations
- **Zero overhead access**: Direct data access when needed via `fold()`

## Data Structure

```c
struct s_string {
    unsigned int count;    // Number of characters (excluding null terminator)
    char data[0];          // Flexible array member for string data
};
```

## API Reference

### String Creation and Destruction

#### `String *init(const char *str)`
Creates a new SafeString from a C string.

**Parameters:**
- `str`: Null-terminated C string to initialize with

**Returns:**
- Pointer to newly allocated String, or NULL on failure

#### `uninit(String *str)`
Frees a SafeString and all its resources.

**Note:** `uninit` is a macro that expands to `free(str)`.

### String Operations

#### `bool concat(String *dst, const char *src)`
Appends a C string to a SafeString.

**Parameters:**
- `dst`: Destination SafeString (will be resized if needed)
- `src`: Source C string to append

**Returns:**
- `true` on success, `false` on memory allocation failure

#### `char *fold(String *str)`
Provides direct access to the underlying C string data.

**Parameters:**
- `str`: SafeString to access

**Returns:**
- Pointer to null-terminated character array

### Utility Functions

#### `unsigned int length(const char *str)`
Calculates the length of a C string.

**Parameters:**
- `str`: Null-terminated C string

**Returns:**
- Number of characters in the string (excluding null terminator)

#### `void copy(void *dst, const void *src, const unsigned int n)`
Copies `n` bytes from source to destination.

**Parameters:**
- `dst`: Destination buffer
- `src`: Source buffer
- `n`: Number of bytes to copy

## Usage Example

```c
#include "safestr.h"
#include <stdio.h>

int main() {
    // Create a new SafeString
    String *str = init("Hello ");
    
    // Print the string
    printf("'%s'\n", str->data);
    
    // Append to the string
    concat(str, "World!");
    
    // Access and print using fold()
    printf("%s\n", fold(str));
    
    // Clean up
    uninit(str);
    
    return 0;
}
```

## Compilation

Compile with any standard C compiler:

```bash
gcc -o safestr_test safestr.c -std=c99 -Wall -Wextra
```

## Memory Management

- All strings are heap-allocated
- `concat()` automatically reallocates memory when needed
- All allocated strings must be freed with `uninit()`
- The library uses `realloc()` for growth, which may move the string in memory

## Safety Considerations

1. Always check return values from `init()` and `concat()`
2. Use `fold()` when you need to pass the string to functions expecting C strings
3. The `data` field is always null-terminated
4. `count` represents the actual character count (excluding null terminator)

## Limitations

- Not thread-safe (calls to `concat()` on the same String from multiple threads require external synchronization)
- No Unicode support (works with single-byte characters only)
- No built-in search or replace functions
- Maximum string size limited by available memory and `unsigned int` range

## Dependencies

- Standard C library (stdlib.h, string.h, stdio.h)
- C99 or later (for flexible array members and designated initializers)

## Error Handling

- Memory allocation failures return NULL (`init()`) or false (`concat()`)
- `assert()` is used for programming errors (compiled out in release with NDEBUG)
- No global error state - check individual function returns

## License
For Educational purpose only
