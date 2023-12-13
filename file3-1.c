#include "shell.h"
/**
 * print_list - a function that prints contents of a linked list.
 * @head: A pointer to a head of a linked list.
 */
void print_list(list_t *head)
{
list_t *current = head;

while (current != NULL)
{
printf("%s\n", current->str);
current = current->next;
}
}
/**
 * *_strchr - a function that returns a pointer to a first
 * occurrence of a character in a string.
 * @s: A pointer to a string to be searched.
 * @c: A character to be found.
 * Return: A pointer to a first occurrence of a character in
 * a string, otherwise NULL if not found.
 */
char *_strchr(const char *s, int c)
{
while (*s != '\0')
{
if (*s == c)
	return ((char *)s);
s++;
}
return (NULL);
}
/**
 * _putchar - a function that prints a character to a standard     output.
 * @c: A character to be printed.
 */
void _putchar(char c)
{
ssize_t bytes_written = write(1, &c, 1);

if (bytes_written == -1)
{
/* Handle the error as desired */
/* For example, you can print an error message to stderr */
fprintf(stderr, "Error writing character to standard output\n");
}
}
/**
 * _puts - a function that prints a string to a standard output
 * followed by a newline character.
 * @s: A pointer to the string to be printed.
 */
void _puts(const char *s)
{
size_t len = strlen(s);
ssize_t bytes_written = write(1, s, len);
ssize_t newline_written = write(1, "\n", 1);

if (bytes_written == -1)
{
/* Handle the error as desired */
/* For example, printing an error message to stderr */
fprintf(stderr, "Error writing string to standard output\n");
}
if (newline_written == -1)
{
/* Handle the error as desired */
/* printing an error message to stderr */
fprintf(stderr, "Error writing newline character to standard output\n");
}
}
