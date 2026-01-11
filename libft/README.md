# Libft

My very own library of C functions, as part of the 42 school curriculum.

## Description

`libft` is a project at 42 that requires us to re-implement a set of standard C library functions, as well as some additional useful ones. This project is a great way to understand the inner workings of these functions and to build a solid foundation for future C projects.

## Functions

### Memory Functions
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### String Manipulation Functions
- `ft_strlen`
- `ft_strdup`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strnstr`
- `ft_strncmp`
- `ft_atoi`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

### Character Functions
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

### File Descriptor Functions
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

## How to Use

1.  **Clone the repository:**
    ```bash
    git clone <repository_url>
    cd C-Systems-Projects/libft
    ```

2.  **Compile the library:**
    Run the `Makefile` to create the static library file `libft.a`.
    ```bash
    make
    ```

3.  **Use it in your project:**
    When compiling your project, you need to tell the compiler where to find the library and its header file.
    ```bash
    cc your_project.c -I./ -L. -lft
    ```
    - `-I./` tells the compiler to look for `libft.h` in the current directory.
    - `-L.` tells the linker to look for the library in the current directory.
    - `-lft` tells the linker to link with the `libft.a` library.

## Example

Here's an example of how to use a function from `libft`:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = "hello world";
    char *sub = ft_substr(str, 6, 5);

    if (sub)
    {
        printf("Substring: %s\n", sub);
        free(sub);
    }
    return (0);
}
```

Compile and run:
```bash
cc main.c -I./ -L. -lft
./a.out
```
Output:
```
Substring: world
```
