#include "shell.h"
/**
* string_duplicate - a function that duplicates a string
* @s: A string to duplicate
* Return: A pointer to A duplicated string
*/
char *string_duplicate(const char *s)
{
int length = 0;
char *result;
if (s == NULL)
	return (NULL);
while (*s++)
length++;
result = malloc(sizeof(char) * (length + 1));
if (!result)
	return (NULL);
for (length++; length--;)
result[length] = *--s;
return (result);
}
