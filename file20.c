#include "shell.h"
/**
* is_chain - a function that checks if a current command
* buffer contains a command chain.
 * @info: A pointer to an info_t structure.
 * Return: An integer value represent type of command chain found:
 * - 1 for "COMMAND_OR"
 * - 2 for "COMMAND_AND"
 * - 3 for "COMMAND_CHAIN"
 * - 0 if no command chain is found
 */
int is_chain(info_t *info)
{
if (strcmp(*info->command_buffer, "COMMAND_OR") == 0)
{
return (1);
}
else if (strcmp(*info->command_buffer, "COMMAND_AND") == 0)
{
return (2);
}
else if (strcmp(*info->command_buffer, "COMMAND_CHAIN") == 0)
{
return (3);
}
return (0);
}
/**
 * check_chain - a function that checks a command buffer
 * for a command chain.
 * @info: A pointer to an info_t structure.
 * Return: An integer value represent type of command chain found:
 * - 1 for "COMMAND_OR"
 * - 2 for "COMMAND_AND"
 * - 0 if no command chain is found
 */
int check_chain(info_t *info)
{
if (strcmp(*info->command_buffer, "COMMAND_OR") == 0)
{
return (1);
}
else if (strcmp(*info->command_buffer, "COMMAND_AND") == 0)
{
return (2);
}
return (0);
}
/**
 * node_starts_with - a function that finds a node in a linked
 * list that starts with a given prefix.
 * @head: A pointer to a head of a linked list.
 * @prefix: A pointer to a prefix string.
 * @delimiter: Delimiter character that follows prefix in
 * each node's string.
 * Return: A pointer to a first node that matches a prefix and
 * delimiter combination, or NULL if no such node is found.
 * Description: This function traverses a linked list start from
 * a head node and checks each node's string to see if it starts
 * with a given prefix and is followed by a specified delimiter
 * character. If a matching node is found, a pointer to that
 * node is returned. If there is no matching node, return to NULL.
 */
list_t *node_starts_with(list_t *head, const char *prefix, char delimiter)
{
list_t *node = head;

while (node != NULL)
{
if (strncmp(node->str, prefix, strlen(prefix)) == 0 &&
		node->str[strlen(prefix)] == delimiter)
	return (node);
node = node->next;
}
return (NULL);
}
/**
* replace_vars - this is a dunction that replaces vars in
* the tokenized string
* @info: the parameter struct
* Return: 1 if replaced, 0 otherwise
*/
void replace_vars(info_t *info)
{
int i = 0;
char *var_start = strchr(info->argv[i], '$');
char *var_end = strchr(var_start, ' ');
char var_name[65];

while (info->argv[i] != NULL)
{
while (var_start != NULL)
{
if (var_end != NULL)
{
strncpy(var_name, var_start + 1, sizeof(var_name) - 1);
var_name[sizeof(var_name) - 1] = '\0';
/*
 * Replace variable with its value using
 * info->env_head or appropriate variable
 */
}
var_start = strchr(var_end, '$');
}
i++;
}
}
/**
* replace_string - a function that replaces string
* @old: An address of old string
* @new: A new string
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
if (*old != NULL)
{
free(*old);
}
*old = malloc(strlen(new) + 1); /* Allocate memory for the new string */
if (*old == NULL)
{
return (0); /* Memory allocation failed */
}
strcpy(*old, new); /* Copy the new string into the old string */
return (1);
}
