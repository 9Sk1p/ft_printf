*This project has been created as part of the 42 curriculum by yhubaren.*
 
# ft_printf
 
## Description
 
`ft_printf` is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`va_list`, `va_start`, `va_arg`, `va_end`) and to write clean, extensible code.
 
The project builds a static library, `libftprintf.a`, containing `ft_printf()`
with the prototype:
 
```c
int ft_printf(const char *format, ...);
```
 
Supported conversions: `c` `s` `p` `d` `i` `u` `x` `X` `%`
 
| Conversion | Output                                   |
|------------|------------------------------------------|
| `%c`       | a single character                       |
| `%s`       | a string (`(null)` if the pointer is NULL) |
| `%p`       | a pointer in hexadecimal (`(nil)` if NULL) |
| `%d` `%i`  | a signed decimal integer                 |
| `%u`       | an unsigned decimal integer              |
| `%x` `%X`  | hexadecimal, lowercase / uppercase       |
| `%%`       | a percent sign                           |
 
The function returns the number of characters printed. The project uses my own
**libft** (in the `libft/` folder) for `ft_putchar_fd`.
 
## Instructions
 
**Compilation** (the Makefile builds `libft` first, then the library, using `cc -Wall -Wextra -Werror`):
 
```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes object files
make fclean # removes object files and the library
make re     # rebuilds everything
```
 
**Usage:**
 
```c
#include "ft_printf.h"
 
int main(void)
{
	ft_printf("Hello %s! %d in hex is %x\n", "world", 255, 255);
	return (0);
}
```
 
```bash
cc main.c -L. -lftprintf -o test
./test
```
 
## Algorithm and design choices
 
`ft_printf` walks through the format string one character at a time:
 
- A normal character is written directly and counted.
- On `%`, the next character is passed to a dispatcher (`ft_check_type`),
  which reads the matching argument with `va_arg` and calls the right
  printing function. Every function **returns the number of characters it
  printed**, so the total is simply accumulated in a counter.
Why this approach:
 
- **Dispatcher + one small function per conversion** keeps the code readable
  and easy to extend: a new conversion (or a bonus flag) is just a new branch
  and a new function.
- **Recursion for numbers.** `ft_print_nbr`, `ft_print_unsigned` and
  `ft_print_hex` divide the number by the base and print the higher digits
  first, so no buffer or `malloc` is needed.
- **`long` for signed numbers.** `INT_MIN` is converted to `long` before
  negation to avoid overflow.
- **One hex function for `x`, `X` and `p`.** It takes the base string
  (lowercase or uppercase) depending on the format; `%p` prints `0x` followed
  by the address as `unsigned long`.
- **No buffer management**, as required by the subject: characters are written
  immediately with `write` (through `ft_putchar_fd`).
### Project structure
 
| File                 | Content                                |
|----------------------|----------------------------------------|
| `ft_printf.c`        | main function and conversion dispatcher |
| `ft_print_chars.c`   | `%c` and `%s`                          |
| `ft_print_numbers.c` | `%d`, `%i` and `%u`                    |
| `ft_print_hex.c`     | `%x`, `%X` and `%p`                    |
| `ft_printf.h`        | prototypes                             |
 
## Resources
 
- `man 3 printf`, `man 3 stdarg`
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- 42 `ft_printf` subject (version 12.1)
- Discussions with peers at 42
**Use of AI:** AI (Claude) was used only to help draft and structure this
README file. The code of the project was written by me.
 