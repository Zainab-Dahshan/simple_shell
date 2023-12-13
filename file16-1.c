#include "shell.h"
/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
int z = 1;
list_t *node = info->history;
while (node != NULL)
{
z++;
node = node->next;
}
info->line_count = z - 1;
return (0);
}
/**
 * add_history - Adds a new entry to the history list.
 * @info: Pointer to the info_t struct.
 * @line: The command line to add to the history.
 * Return: 0 on success, -1 on failure.
*/
int add_history(info_t *info, const char *line)
{
list_t *node = malloc(sizeof(list_t));

if (node == NULL)
	return (-1);

node->str = strdup(line);
node->next = info->history;
info->history = node;

renumber_history(info);
return (0);
}
/**
 * free_history - Frees the memory used by the history list.
 * @head: Pointer to the head of the history list.
*/
void free_history(list_t **head)
{
list_t *node = *head;
list_t *temp = node->next;

while (node != NULL)
{
free(node->str);
free(node);
node = temp;
}
*head = NULL;
}
