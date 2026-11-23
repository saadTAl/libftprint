*This project has been created as part of the 42 curriculum by satalbi.*

# ft_printf

## Description

`ft_printf` is a recreation of the `printf()` function from the C standard library.
The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to write a small, well-structured library
that can be reused in later 42 projects.

The result is a static library, `libftprintf.a`, that provides:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes to the standard output and returns the number of
characters printed. It handles the following conversions:

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a percent sign |

As required by the subject, there is no buffer management: every character is
written immediately with `write()`.

## Instructions

### Compilation

```sh
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean + all
```

The library is compiled with `cc -Wall -Wextra -Werror` and created with `ar rcs`.

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello %s, you are %d years old (%x in hex)\n", "Sam", 42, 42);
    ft_printf("That line was %d characters long\n", n);
    return (0);
}
```

```sh
cc main.c libftprintf.a -o test
./test
```

## Algorithm and data structure

### Main loop (`ft_print.c`)

`ft_printf` walks through the format string once, from left to right, with an
index `i` and a counter `count`:

- If the current character is not `%`, it is printed as is and `count` increases by 1.
- If it is `%`, the index moves to the next character (`str[++i]`), which is the
  conversion specifier. A chain of `if / else if` checks which conversion it is,
  takes the next argument with `va_arg` using the matching type (`int`,
  `unsigned int`, `char *` or `void *`), and calls the matching helper function.
  Each helper returns how many characters it printed, which is added to `count`.
- If the `%` is the last character of the string, the loop stops (`break`). Without
  this check, the index would move past the terminating `'\0'` and read memory
  outside the string. A trailing `%` is undefined behavior in C, so the goal here
  is simply to stop safely without crashing.

At the end, `va_end` is called and `count` is returned, like the real `printf`.

**Why this design:** a single pass with a simple dispatch is the most direct way
to mimic `printf`. Each conversion lives in its own small function, so it is easy
to test separately and easy to add a new conversion later.

### Data structure

No complex data structure is needed. The project only uses:

- a `va_list` to read the variable arguments one by one, in order;
- constant strings `"0123456789abcdef"` and `"0123456789ABCDEF"` used as lookup
  tables: the digit for a value `d` (0 to 15) is simply `base[d]`.

### Printing numbers: recursion

Numbers are printed digit by digit with **recursion**: to print `n`, the function
first prints `n / base` (all the digits except the last one), then prints the
last digit `n % base`. This prints the digits in the correct order without
needing an array or reversing a string.

- **`%d` / `%i` (`ft_putnbr`)**: the number of characters is calculated first with
  `ft_count_digit` (which also counts the `-` sign), then the number is printed.
  `ft_count_digit` takes a `long` so that the calculation never overflows.
  `INT_MIN` (`-2147483648`) is handled separately, because `-INT_MIN` does not fit
  in an `int`.
- **`%u` (`ft_unsigned_decimal`)**: same method, with `ft_count_digit` for the length.
- **`%x` / `%X` (`ft_to_hexa`)**: base 16. The return value is the sum of what every
  recursive call printed.
- **`%p` (`ft_print_adrss`)**: the pointer is converted to `unsigned long` (64 bits)
  and printed in base 16 after `0x`. The helper `ft_hexa` uses a `static` counter:
  all recursive calls share the same variable. The deepest call sets it to 3
  (`0x` + 1 digit) and each call adds 1 when it returns, so the final value is
  `2 + number of digits`.

## Resources

- `man 3 printf` and `man 3 stdarg`: the reference for the expected behavior and for variadic functions
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf): format specifiers and return value
- [cppreference: Variadic arguments](https://en.cppreference.com/w/c/variadic): `va_list`, `va_start`, `va_arg`, `va_end`
- [YouTube: VIDEO TITLE 1](https://www.youtube.com/watch?v=oDC208zvsdg)
- [YouTube: VIDEO TITLE 2](https://www.youtube.com/watch?v=7Sph8JlRo0g)

### How AI was used

I wrote all the code myself. I used an AI assistant (Claude) as a learning aid:

- **Understanding concepts:** the `static` keyword in a recursive function, and why a `%` at the end of the format
  string is undefined behavior.
- **Testing:** I used it to compare my `ft_printf` with the real `printf` and to
  understand why some return values were wrong. I fixed the code myself.
- **README:** it helped me structure this file.