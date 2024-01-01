#include "shell.h"
/**
 * read_history_list - a function that reads history list from 
 * a specified file path in an info_t structure.
 * @info: A pointer to info_t struct that contains history list file path.
 * Return: void
 */
void read_history_list(info_t *info)
{
FILE *file = fopen(info->history_list_file_path, "r");
char buffer[100];

if (file != NULL)
{
while (fgets(buffer, sizeof(buffer), file) != NULL)
{
printf("%s", buffer);
}
if (fclose(file) != 0)
{
perror("Error closing file");
}
}
else
{
printf("Error: Unable to open history list file\n");
}
}
/**
 * get_history_file - a function that reads a history file from
 * a specified file path in the info_t structure.
 * @info: A pointer to info_t struct that contains a history file path.
 * Return: void
 */
void get_history_file(info_t *info)
{
FILE *file = fopen(info->history_file_path, "r");
char buffer[100];

if (file != NULL)
{
while (fgets(buffer, sizeof(buffer), file) != NULL)
{
printf("%s", buffer);
}
if (fclose(file) != 0)
{
perror("Error closing file");
}
}
else
{
printf("Error: Unable to open history file\n");
}
}
