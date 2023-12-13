#include "shell.h"
/**
 * _strtow2 - a function that splits a string into words
 * @str: An input string
 * @delimiter: A delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtow2(char *str, char delimiter)
{
int w, x, y, z, numberwords = 0;
char **s;

if (str == NULL || str[0] == '\0')
	return (NULL);

for (w = 0; str[w] != '\0'; w++)
{
if (str[w] != delimiter && str[w + 1] == delimiter)
	numberwords++;
}
if (numberwords == 0)
	return (NULL);
s = malloc((1 + numberwords) * sizeof(char *));

if (!s)
	return (NULL);

for (w = 0, x = 0; x < numberwords; x++)
{
while (str[w] == delimiter)
w++;
y = 0;
while (str[w + y] != delimiter && str[w + y])
y++;
s[x] = malloc((y + 1) * sizeof(char));

if (!s[x])
{
for (y = 0; y < x; y++)
free(s[y]);
free(s);
return (NULL);
}
for (z = 0; z < y; z++)
s[x][z] = str[w++];
s[x][z] = '\0';
}
s[x] = NULL;
return (s);
}
