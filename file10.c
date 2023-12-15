#include "shell.h"
/**
* string_duplicate - a main function that duplicates a string
* @s: String to duplicate
* Return: Pointer to a duplicated string
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
