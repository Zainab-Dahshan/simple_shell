#include "shell.h"
/**
 * _count_words - this is a helper function that counts
 * number of words in a string.
 * @str: The input string.
 * @d: The delimiter string.
 * Return: The number of words.
 */
int _count_words(char *str, char *d)
{
int count = 0;
int is_word = 0;

while (*str)
{
if (!check_delimiter(*str, d))
{
if (!is_word)
{
count++;
is_word = 1;
}
}
else
{
is_word = 0;
}
str++;
}
return (count);
}
/**
 * _copy_word - this a helper function that copies a word from
 * an input string to a new dynamically allocated string.
 * @str: The input string.
 * @d: The delimiter string.
 * Return: The dynamically allocated string containing the word.
 */
char *_copy_word(char *str, char *d)
{
char *word;
int len = 0;
int i = 0;

while (str[len] && !check_delimiter(str[len], d))
	len++;
word = malloc((len + 1) * sizeof(char));
if (word == NULL)
	return (NULL);
for (i = 0; i < len; i++)
word[i] = str[i];
word[len] = '\0';
return (word);
}
/**
 * _strtow - this is a function that splits a string into words.
 * @str: An input string.
 * @d: A delimiter string.
 * Return: The pointer to an array of strings, or NULL on failure.
 */
char **_strtow(char *str, char *d)
{
int number_words = 0;
int i = 0;
char **s;

if (str == NULL || str[0] == '\0')
	return (NULL);
if (!d)
	d = " ";
number_words = _count_words(str, d);
if (number_words == 0)
	return (NULL);
s = malloc((number_words + 1) * sizeof(char *));
if (!s)
	return (NULL);
while (*str)
{
if (!check_delimiter(*str, d))
{
s[i] = _copy_word(str, d);
if (s[i] == NULL)
{
/* free previously allocated memory on error */
while (i > 0)
	free(s[--i]);
free(s);
return (NULL);
}
i++;
while (*str && !check_delimiter(*str, d))
str++;
}
else
{
str++;
}
}
s[i] = NULL;
return (s);
}
