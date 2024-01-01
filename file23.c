#include "shell.h"
/**
 * find_command - a function that finds a command to execute
 * and prepares for forking.
 * @info: Structure contains information about our shell.
 */
void find_command(info_t *info)
{
int i, k;

if (info == NULL || info->argv == NULL || info->argv[0] == NULL || strlen(info->argv[0]) == 0)
{
printf("Invalid argument\n");
return;
}
info->path = info->argv[0];
if (info->line_count == 1)
	info->line_count++;
for (i = 0, k = 0; info->argv[i]; i++)
{
if (!check_delimiter(info->argv[i][0], " \t\n"))
k++;
}
if (!k)
	return;
if ((check_interactive_mode(info) || getenv("PATH") || info->argv[0][0] == '/') && find_builtin(info) == 1)
	fork_command(info);
else if (*(info->argv[0]) != '\n')
	info->status = 127;
}
/**
 * fork_command - a function that forks a child process and
 * executes the command.
 * @info: A structure contains information about our shell prog.
 */
void fork_command(info_t *info)
{
int status;
pid_t child_pid;

child_pid = fork();

if (child_pid == -1)
{
perror("Error:");
return;
}
else if (child_pid == 0)
{
if (execve(info->path, info->argv, environ) == -1)
{
perror("execve Error:");
exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0);
}
}
