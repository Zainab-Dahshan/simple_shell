#include "shell.h"
/**
 * execute_external_command - a function that executes an external command.
 * @info: pointer to a struct contains information about my shell program.
 * Description: This function checks if a command is provided in an argument
 * vector of an info structure. If a command is provided, it attempts to execute
 * the command using the system() function.
 * If the command execution is successful, the function returns 0.
 * If no command is provided or if the command execution fails, the function prints
 * an error message and returns -1.
 * Return: 0 if the command is successfully executed, -1 otherwise.
 */
int execute_external_command(info_t *info)
{
int result = system(info->argv[0]);

/* Check if the command is provided */
if (info->argv[0] == NULL)
{
printf("No command provided.\n");
return (-1);
}
/* Check if the command was successful */
if (result != 0)
{
printf("Command failed.\n");
return (-1);
}
return (0);
}
