#include "shell.h"
/**
 * _strtow - a function that splits a string into words.
 * Repeat delimiters are ignored
 * @str: An input string
 * @d: A delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtow(char *str, char *d)
{
int w, x, y, z, numberwords = 0;
char **s;

if (str == NULL || str[0] == '\0')
	return (NULL);
if (!d)
	d = " ";

for (w = 0; str[w] != '\0'; w++)
{
if (!check_delimiter(str[w], d) && (check_delimiter(str[w + 1], d)
		|| !str[w + 1]))
numberwords++;
}
if (numberwords == 0)
	return (NULL);
s = malloc((1 + numberwords) *sizeof(char *));
if (!s)
	return (NULL);
for (w = 0, x = 0; x < numberwords; x++)
{
while (check_delimiter(str[w], d))
w++;
y = 0;
while (!check_delimiter(str[w + y], d) && str[w + y])
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
