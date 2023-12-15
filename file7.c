#include "shell.h"
/**
 * print_decimal - a function that prints a decimal number.
 * Description: This function takes an integer as input and
 * prints it as a decimal number. It can print to either
 * standard output or standard error.
 * @input: An input integer to be printed.
 * @fd: A file descriptor to print to (STDOUT_FILENO for standard output,
 * STDERR_FILENO for standard error).
 */
void print_decimal(int input, int fd)
{
int (*__putchar)(int);
int x, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
	__putchar = (int (*)(int)) putchar;
else
	__putchar = putchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
{
_abs_ = input;
}
current = _abs_;
for (x = 1000000000; x > 1; x /= 10)
{
if (_abs_ / x)
{
__putchar('0' + current / x);
count++;
}
current %= x;
}
__putchar('0' + current);
count++;
}
/**
 * *number_converter - a function that converts a number to a string.
 * Description: This function takes a number and converts it to a string
 * representation in a specified base. It supports signed and unsigned numbers.
 * @num: An input number to be converted.
 * @base:  A base for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @flags: Additional flags for conversion (e.g., CONVERT_UNSIGNED to
 * convert an unsigned number).
 * Return: A converted string representation of a number.
 */
char *number_converter(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
int number = num;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && number < 0)
{
n = -number;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}
/**
 * comment_remover - a function that removes comments from a string.
 * Description: This function takes a string as input and removes
 * any comments from it. Comments are identified by '#' character
 * and extend until an end of a line.
 * @buffer: An input string to remove comments from.
 */
void comment_remover(char *buffer)
{
int y;
for (y = 0; buffer[y] != '\0'; y++)
{
if (buffer[y] == '#' && (!y || buffer[y - 1] == ' '))
{
buffer[y] = '\0';
break;
}
}
}
/**
 *  display_error - a function that displays an error message.
 * Description: function takes a pointer to an info_t struct and
 * an error string as input and displays an error message using
 * information from the structure.
 * @info: A pointer to an info_t struct contain file information.
 * @estr: An error string to be displayed.
 */
void display_error(info_t *info, char *estr)
{
printf("%s: ", info->fname);
printf("%d: ", info->line_count);
printf("%s: ", info->argv[0]);
printf("%s\n", estr);
}
