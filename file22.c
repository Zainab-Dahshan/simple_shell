#include "shell.h"
/**
 * _strtow2 - A function that splits a string into words.
 * @str: An input string.
 * @delimiter: A delimiter.
 * Return: A pointer to an array of strings on success, or NULL on failure.
 */
char **_strtow2(char *str, char delimiter)
{
int w = 0, x = 0, y = 0, z = 0, numberwords = 0;
char **s;

if (str == NULL || str[0] == '\0')
	return (NULL);

while (str[w] != '\0')
{
if (str[w] != delimiter && str[w + 1] == delimiter)
numberwords++;
w++;
}
if (numberwords == 0)
	return (NULL);

s = malloc((1 + numberwords) * sizeof(char *));
if (!s)
	return (NULL);

w = 0;
x = 0;
while (x < numberwords)
{
while (str[w] == delimiter)
w++;

y = 0;
while (str[w + y] != delimiter && str[w + y])
y++;
s[x] = malloc((y + 1) * sizeof(char));
if (!s[x])
{
y = 0;
while (y < x)
free(s[y++]);
free(s);
return (NULL);
}
z = 0;
while (z < y)
{
s[x][z] = str[w++];
z++;
}
s[x][z] = '\0';
x++;
}
s[x] = NULL;
return (s);
}

