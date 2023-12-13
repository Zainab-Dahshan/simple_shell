#include "shell.h"
/**
 * get_history_file - this function is responsible for getting the history file
 * @homedir: the home directory path
 * Return: allocated string containing history file
 */
char *get_history_file(const char *homedir)
{
char *buffer =
	malloc(sizeof(char) * (strlen(homedir) + strlen(HIST_FILE) + 2));

if (buffer == NULL)
	return (NULL);
sprintf(buffer, "%s/%s", homedir, HIST_FILE);
return (buffer);
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
FILE *fp = fopen(filename, "w");
list_t *node = info->history;

if (homedir == NULL)
	return (-1);
if (filename == NULL)
	return (-1);
if (fp == NULL)
{
free(filename);
return (-1);
}
while (node != NULL)
{
fprintf(fp, "%s\n", node->str);
node = node->next;
}
fprintf(fp, "\n");
fclose(fp);
free(filename);
return (0);
}
/**
 * read_history_list - reads history from file into the parameter struct
 * @info: the parameter struct
 * Return: histcount on success, or 0 otherwise
 */
int read_history_list(info_t *info)
{
char *homedir = getenv("HOME");
FILE *fp = fopen(get_history_file(homedir), "r");
char buffer[MAXIMUM_BUFFER_SIZE];
int line_count = 0;
size_t len = strlen(buffer);
list_t *node = malloc(sizeof(list_t));

if (homedir == NULL)
	return (-1);
if (fp == NULL)
	return (-1);
while (fgets(buffer, MAXIMUM_BUFFER_SIZE, fp) != NULL &&
		line_count < HIST_MAX)
{
if (len > 0 && buffer[len - 1] == '\n')
	buffer[len - 1] = '\0';
if (len > 1 || (len == 1 && buffer[0] != '\n'))
{
if (node == NULL)
	return (-1);
node->str = strdup(buffer);
node->next = info->history;
info->history = node;
line_count++;
}
}
fclose(fp);
info->line_count = line_count;
return (0);
}
