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
const char *filename = info->history_file_path;
FILE *fp = fopen(filename, "w");
int success = 0;
list_t *node = info->history;

if (homedir == NULL || filename == NULL || fp == NULL)
{
if (fp != NULL)
fclose(fp);
return (-1);
}
while (node != NULL && success == 0)
{
success = write_history_node(fp, node);
node = node->next;
}
fclose(fp);
return (success == 0 ? 1 : -1);
}
