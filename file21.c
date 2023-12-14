#include "shell.h"
/**
 * _strtow - A function that splits a string into words.
 * Repeat delimiters are ignored.
 * @str: An input string.
 * @d: A delimiter string.
 * Return: The pointer to an array of strings, or NULL on failure.
 */
char **_strtow(char *str, char *d)
{
int w = 0, x = 0, y = 0, z = 0, numberwords = 0;
char **s;

if (str == NULL || str[0] == '\0')
	return (NULL);
if (!d)
	d = " ";

while (str[w] != '\0')
{
if (!check_delimiter(str[w], d) && (check_delimiter(str[w + 1], d) || !str[w +1]))
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
