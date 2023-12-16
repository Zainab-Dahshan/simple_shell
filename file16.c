#include "shell.h"
/**
 * open_history_file - Opens the history file for writing
 * @filename: the name of the history file
 * Return: FILE pointer to the opened file, or NULL on failure
 */
FILE *open_history_file(const char *filename)
{
FILE *fp = fopen(filename, "w");

if (fp == NULL)
{
perror("Error opening history file");
}
return (fp);
}
/**
 * write_history - writes the command history to a file
 * @info: the parameter struct
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
char *homedir = getenv("HOME");
char *filename = get_history_file(homedir);
FILE *fp = open_history_file(filename);
int success = 0;
list_t *node = info->history;

if (homedir == NULL || filename == NULL || fp == NULL)
{
free(filename); /* Free the filename in case of failure */
return (-1);
}
while (node != NULL && success == 0)
{
success = write_history_node(fp, node);
node = node->next;
}
close_history_file(fp);
free(filename); /* Free the filename after usage */
return (success == 0 ? 1 : -1);
}
