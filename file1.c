#include "shell.h"
/**
* check_interactive_mode - a function that returns true
* if shell is interactive mode
* @info: struct address
* Return: 1 if interactive mode, or 0 otherwise
*/
int check_interactive_mode(info_t *info)
{
(void)info;

return (isatty(STDIN_FILENO) ? 1 : 0);
}
/**
* check_delimiter - a function that checks if character
* is a delimiter.
* @c: Character to check.
* @delimiter: Delimiter string.
* Return: 1 if true, 0 if false.
*/
int check_delimiter(char c, char *delimiter)
{
while (*delimiter)
{
if (*delimiter++ == c)
return (1);
}
return (0);
}
/**
* check_alpha - a function that checks
* for alphabetic character.
* @c: Character to input.
* Return: 1 if c is alphabetical, or 0 otherwise.
*/
int check_alpha(int c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}
/**
 * string_to_integer - a function that converts a string to an integer.
 * Description: a function takes a string as input and converts it to
 * an integer. It supports positive and negative numbers. If conversion
 * fails or no digits are found in a string, it returns 0. If a converted
 * value exceeds a range of an integer, it returns INT_MIN or INT_MAX
 * depending on a sign.
 * @s: An input string to be converted.
 * Return: A converted integer value.
 */
int string_to_integer(char *s)
{
int sign = 1, output = 0;
unsigned long int result = 0;

if (*s == '-')
{
sign = -1;
s++;
}
else if (*s == '+')
{
s++;
}
while (*s != '\0')
{
if (*s >= '0' && *s <= '9')
{
result *= 10;
result += (*s - '0');
if (result > INT_MAX)
{
return ((sign == -1) ? INT_MIN : INT_MAX);
}
}
else
{
return (0); /* Signal an error for non-digit characters */
}
s++;
}
output = (int)result *sign;
return (output);
}
