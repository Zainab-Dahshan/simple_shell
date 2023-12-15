#include <stdlib.h>
#include "shell.h"
/**
 * _strtow2 - this is a function that splits a string into words.
 * @str: An input string.
 * @delimiter: A delimiter.
 * Return: A pointer to an array of strings on success,
 * or NULL on failure.
 */
char **_strtow2(char *str, char delimiter)
{
int number_words = count_words(str, delimiter);
char **s = allocate_memory(number_words);

if (number_words == 0)
	return (NULL);
if (!s)
	return (NULL);
copy_words(s, str, delimiter, number_words);
return (s);
}
/**
 * count_words - this is a helper function to count
 * number of words in a string.
 * @str: An input string.
 * @delimiter: A delimiter.
 * Return: The number of words in the string.
 */
int count_words(char *str, char delimiter)
{
int w = 0, number_words = 0;

while (str[w] != '\0')
{
if (str[w] != delimiter && str[w + 1] == delimiter)
	number_words++;
w++;
}
return (number_words);
}
/**
 * allocate_memory - this is a helper function to allocate
 * memory for the array of strings.
 * @number_words: The number of words to be stored in the array.
 * Return: A pointer to the allocated memory.
 */
char **allocate_memory(int number_words)
{
char **s = malloc((1 + number_words) * sizeof(char *));
return (s);
}
/**
 * copy_words - this is a helper function to copy words from
 * an input string to the allocated memory.
 * @s: The array of strings.
 * @str: An input string.
 * @delimiter: A delimiter.
 * @number_words: The number of words in the string.
 */
void copy_words(char **s, char *str, char delimiter, int number_words)
{
int w = 0, x = 0, y = 0, z = 0;

while (x < number_words)
{
while (str[w] == delimiter)
	w++;
while (str[w + y] != delimiter && str[w + y])
	y++;
s[x] = malloc((y + 1) * sizeof(char));
if (!s[x])
{
while (y < x)
	free(s[y++]);
free(s);
return;
}
while (z < y)
{
s[x][z] = str[w++];
z++;
}
s[x][z] = '\0';
x++;
}
s[x] = NULL;
}
