#include "shell.h"
/**
* _memset - fills memory with a constant byte
* @s: the pointer to the memory area
* @b: the byte to fill *s with
* @n: the bytes to be filled
* Return: (s) a pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int z;/* Declare z before the loop */
/* Check if n is within the bounds of the memory block */
if (n > sizeof(s))
{
printf("Error: n is out of bounds.\n");
return (NULL);
}
for (z = 0; z < n; z++)
s[z] = b;
return (s);
}
/**
* ffree - this function is responsible for freeing a string of strings
* @pp: string of strings
*/
void ffree(char ***pp)
{
char **p = *pp;

if (!pp || !*pp)
	return;
while (*p)
{
free(*p);
p++;
}
free(*pp);
*pp = NULL;
}
/**
* _realloc - this function is specific to reallocate a block of memory
* @ptr: pointer to previous malloc'ated block
* @old_size: byte size of previous block
* @new_size: byte size of new block
* Return: pointer to da ol'block nameen.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p = malloc(new_size);
unsigned int min_size = old_size < new_size ? old_size : new_size;
unsigned int i;/* Declare i before the loop */

if (!ptr)
	return (malloc(new_size));

if (!new_size)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
	return (ptr);
if (!p)
	return (NULL);
for (i = 0; i < min_size; i++)
p[i] = ((char *)ptr)[i];
free(ptr);
return (p);
}
