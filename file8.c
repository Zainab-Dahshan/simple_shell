#include "shell.h"
/**
 * our_strncpy - a function that copies a string from
 * source to destination up to a specified numbers of characters.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to be copied.
 * Return: A pointer to the destination string.
 */
char *our_strncpy(char *dest, const char *src, int n)
{
int x = 0;

while (src[x] != '\0' && x < n)
{
dest[x] = src[x];
x++;
}
dest[x] = '\0'; /* Ensure null termination */
return (dest);
}
/**
 * our_strncat - a function that concatenates two strings,
 * appending characters from source to the end of destination
 * up to a specified numbers of characters.
 * @dest: First string.
 * @src: Second string.
 * @n: Maximum number of characters to be used.
 * Return: A pointer to a concatenated string.
 */
char *our_strncat(char *dest, const char *src, int n)
{
int x = 0;
int z = 0;

while (dest[x] != '\0')
x++;

while (src[z] != '\0' && z < n)
{
dest[x] = src[z];
x++;
z++;
}
dest[x] = '\0';
return (dest);
}
/**
 * our_strchr - a function that locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to look for.
 * Return: A pointer to first occurrence of a char in a string,
 * otherwise  NULL if the character is not found.
 */
char *our_strchr(const char *s, char c)
{
if (s == NULL) /* Check if source string is not null */
	return (NULL);
while (*s != '\0')
{
if (*s == c)
	return ((char *) s);
s++;
}
return (NULL);
}

