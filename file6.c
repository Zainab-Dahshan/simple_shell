#include "shell.h"
/**
* print_character - a function that writes a character c to stderr
* @character: A character to print
* Return: On success 1. otherwise -1 On error, -1 is returned.
*/
int print_character(char character)
{
static char buffer[MAXIMUM_BUFFER_SIZE];
int index = 0;

if (character == BUFFER_FLUSH || index >= MAXIMUM_BUFFER_SIZE)
{
if (write(1, buffer, index) == -1)
	return (-1);
index = 0;
}
buffer[index++] = character;
return (0);
}
/**
* print_string - prints an input string
* @input: the string to be printed
* Return: Nothing
*/
int print_string(const char *input)
{
int x;

if (!input)
	return (0);
for (x = 0; input[x] != '\0'; x++)
{
if (print_character(input[x]) == -1)
	return (-1);
}
return (0);
}
/**
* write_character - a function that writes a character c to a given fd
* @character: A character to print
* @file_descriptor: A filedescriptor to write to
* Return: On success 1. otherwise -1 on error.
*/
int write_character(char character, int file_descriptor)
{
static char buffer[MAXIMUM_BUFFER_SIZE];
int index = 0;

if (character == BUFFER_FLUSH || index >= MAXIMUM_BUFFER_SIZE)
{
if (write(file_descriptor, buffer, index) == -1)
	return (-1);
index = 0;
}
buffer[index++] = character;
return (0);
}
/**
* print_string_fd - prints an input string
* @input: the string to be printed
* @file_descriptor: the filedescriptor to write to*
* Return: the number of chars put
*/
int print_string_fd(const char *input, int file_descriptor)
{
int x;

if (!input)
	return (0);
for (x = 0; input[x] != '\0'; x++)
{
if (write_character(input[x], file_descriptor) == -1)
	return (-1);
}
return (0);
}
