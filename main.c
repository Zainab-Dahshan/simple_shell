#include "shell.h"
/**
 * initialize_info - this is function that
 * initializes the info structure.
 * @info: info_t structure to be initialized.
 */
void initialize_info(info_t *info)
{
info->argv = NULL;
info->line_count = 0;
info->path = NULL;
info->status = 0;
}
/**
 * open_file - a function that Opens the file
 * provided as a command line argument.
 * @info: The info_t structure contains file-related information.
 * @filename: The name of the file to open.
 * Return: 0 on success, or EXIT_FAILURE if an error occurs.
 */
int open_file(info_t *info, char *filename)
{
int fd = open(filename, O_RDONLY);

if (fd == -1)
{
if (errno == EACCES)
	exit(126);
if (errno == ENOENT)
{
puts(info->argv[0]);
puts(": 0: Can't open ");
puts(info->argv[1]);
putchar('\n');
putchar(BUFFER_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fd;
return (0);
}
/**
 * main - the main entry point of the program.
 * @argc: The number of command line arguments.
 * @argv: An array of strings represent the command line arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
info_t *info = malloc(sizeof(info_t));
list_t *env_head = NULL;

if (argc < 2)
{
printf("Usage: %s <filename>\n", argv[0]);
return (EXIT_FAILURE);
}
if (info == NULL)
{
perror("Failed to allocate memory for info");
exit(EXIT_FAILURE);
}
initialize_info(info);
info->argv = argv;
if (argc == 2)
{
if (open_file(info, argv[1]) != 0)
{
free(info);
return (EXIT_FAILURE);
}
}
populate_environment_list(&env_head);
read_history_list(info);
find_command(info);
get_history_file(info);
read_history_list(info);
/* Free the allocated memory */
free(info->argv);
free(info->path);
free(info);
return (0);
}
