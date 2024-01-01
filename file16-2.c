#include "shell.h"
/**
 * write_history_node - Writes a single history node to history file
 * @fp: FILE pointer to the history file
 * @node: history node to be written
 * Return: 0 on success, -1 on failure
 */
int write_history_node(FILE *fp, const list_t *node)
{
if (fprintf(fp, "%s\n", node->str) < 0)
{
perror("Error writing to history file");
return (-1);
}
return (0);
}
/**
 * close_history_file - Closes the history file
 * @fp: FILE pointer to the history file
 * Return: 0 on success, EOF on failure
 */
int close_history_file(FILE *fp)
{
int result = fclose(fp);

if (result != 0)
{
perror("Error closing history file");
return (EOF);
}
return (0);
}
/**
 * allocate_history_node - Allocates memory for a new history node
 * @line: String to be stored in the history node
 * Return: Pointer to the allocated history node
 */
list_t *allocate_history_node(const char *line)
{
list_t *node = malloc(sizeof(list_t));

if (node == NULL)
{
perror("Error allocating memory for history node");
exit(EXIT_FAILURE);
}
node->str = strdup(line);
if (node->str == NULL)
{
perror("Error duplicating history node string");
free(node);
exit(EXIT_FAILURE);
}
node->next = NULL;
return (node);
}
/**
 * free_history_node - Frees memory allocated for a history node
 * @node: Pointer to the history node to be freed
 */
void free_history_node(list_t *node)
{
free(node->str);
free(node);
}

