#include "shell.h"

/**
 * string_duplicate - Dthis is a function that duplicates a string.
 * @s: the String to duplicate.
 * Return: the Pointer to a duplicated string.
 */
char *string_duplicate(const char *s)
{
int length = 0, i = 0;
char *result = malloc(sizeof(char) * (length + 1));

if (s == NULL)
	return (NULL);
while (s[length] != '\0')
	length++;

if (result == NULL)
	return (NULL);
for (i = 0; i < length; i++)
	result[i] = s[i];
result[length] = '\0'; /* Null-terminate the duplicated string */
return (result);
}
