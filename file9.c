#include "shell.h"
/**
* memory_free - a function that deallocates a memory
* spaces and sets the pointer to NULL
* @memory: An address of a pointer to deallocate
* Return: True if deallocated, otherwise False.
*/
bool memory_free(void **memory)
{
if (memory && *memory)
{
free(*memory);
*memory = NULL;
return (true);
}
return (false);
}
