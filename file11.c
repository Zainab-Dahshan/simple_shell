#include "shell.h"
/**
* string_length - a function that returns a length of a string
* @str: A string whose length to check
* Return: An integer length of string
*/
int string_length(char *str)
{
int z = 0;
if (!str)
return (0);
while (*str++)
z++;
return (z);
}
/**
* string_compare - a function that performs lexicogarphic
* comparison of two strings.
* @str1: First string
* @str2: Second string
* Return: negative if str1 < str2, positive if str1 > str2,
* zero if str1 == str2
*/
int string_compare(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
* begins_with - a function that checks if needle
* starts with haystack
* @haystack: A string to search
* @needle: A substring to find
* Return: An address of next char of haystack or NULL.
*/
char *begins_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
* string_concat - a function that concatenates two strings
* @destination: A destination buffer
* @source: A source buffer
* Return: A pointer to destination buffer
*/
char *string_concat(char *destination, char *source)
{
char *ret = destination;
while (*destination)
destination++;
while (*source)
*destination++ = *source++;
*destination = *source;
return (ret);
}

