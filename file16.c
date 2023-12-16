#include "shell.h"
/**
 * get_history_file - this function is responsible
 * for getting the history file
 * @homedir: the home directory path
 * Return: allocated string containing history file
 */
char *get_history_file(const char *homedir)
{
char *buffer = malloc(sizeof(char) * (strlen(homedir) +
			strlen(HIST_FILE) + 2));

if (buffer == NULL)
	return (NULL);
sprintf(buffer, "%s/%s", homedir, HIST_FILE);
return (buffer); /* Return the allocated buffer */
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

if (homedir == NULL || filename == NULL || fp == NULL)
{
free(filename); /* Free the filename in case of failure */
return (-1);
}
while (node != NULL)
{
fprintf(fp, "%s\n", node->str);
node = node->next;
}
fprintf(fp, "\n");
fclose(fp);
free(filename); /* Free the filename after usage */
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
char *filename = get_history_file(homedir); /* Store the filename */
FILE *fp = fopen(filename, "r");
char buffer[MAXIMUM_BUFFER_SIZE];
size_t len;
int line_count = 0;
list_t *head = NULL; /* Declare a pointer to the head of the list */
list_t *node;

if (homedir == NULL || fp == NULL || filename == NULL)
{
free(filename); /* Free the filename in case of failure */
return (-1);
}
while (fgets(buffer, MAXIMUM_BUFFER_SIZE, fp) != NULL && line_count < HIST_MAX)
{
len = strlen(buffer);
if (len > 0 && buffer[len - 1] == '\n')
	buffer[len - 1] = '\0';
if (len > 1 || (len == 1 && buffer[0] != '\n'))
{
node = malloc(sizeof(list_t));
if (node == NULL)
{
fclose(fp);
free(filename); /* Free the filename in case of failure */
free_history(&(info->history));
/* Free the allocated nodes before returning */
return (-1);
}
node->str = strdup(buffer);
node->next = head;
head = node;
line_count++;
}
}
fclose(fp);
free(filename); /* Free the filename after usage */
free_history(&(info->history));
info->history = head;
info->line_count = line_count;
return (0);
}
