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
 */
void close_history_file(FILE *fp)
{
fclose(fp);
}
