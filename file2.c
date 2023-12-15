#include "shell.h"
#include <unistd.h>
/**
 * handle_exit - a function that exits the shell program
 * @info: A structure contains a potential arguments. Used to maintain
 * constant function prototype.
 * Return: Exits with a given exit status
 * (0) if info->argv[0] != "exit"
 */
int handle_exit(info_t *info)
{
if (info->argv[1]) /* If there is an exit argument */
{
int exit_status = atoi(info->argv[1]);

exit(exit_status);
}
return (0);
}
/**
 * handle_cd - a function that changes the current directory of a process
 * @info: A structure contains potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 on success.
 */
int handle_cd(info_t *info)
{
char *path = info->argv[1];
char *oldpwd = getenv("PWD");
char *newpwd = NULL;

if (path == NULL || strlen(path) == 0)
{
path = getenv("HOME");
}
else
{
newpwd = realpath(path, NULL);
if (newpwd == NULL)
{
write(STDOUT_FILENO, "cd: ", 4);
write(STDOUT_FILENO, path, strlen(path));
write(STDOUT_FILENO, ": No such file or directory\n", 28);
return (1);
}
}
if (chdir(newpwd) == -1)
{
write(STDOUT_FILENO, "cd: ", 4);
write(STDOUT_FILENO, path, strlen(path));
write(STDOUT_FILENO, ": Permission denied\n", 20);
free(newpwd);
return (1);
}

setenv("OLDPWD", oldpwd, 1);
setenv("PWD", newpwd, 1);
free(newpwd); /* Free an allocated memory for newpwd */
return (0);
}
/**
 * check_help - a function that displays help information
 * @info: A structure contains potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 on success.
 */
int check_help(info_t *info)
{
char **arg_array = info->argv;

write(STDOUT_FILENO,
	"Help function called. Function not yet implemented.\n", 51);
if (arg_array && *arg_array)
{
write(STDOUT_FILENO, *arg_array, strlen(*arg_array));
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}
