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
if (info->argv[0] && strcmp(info->argv[0], "exit") == 0)
{
int exit_status = (info->argv[1]) ? atoi(info->argv[1]) : 0;

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
char *path = (info->argv[1]) ? info->argv[1] : getenv("HOME");
char *oldpwd = getenv("PWD");
char *newpwd = realpath(path, NULL);

if (newpwd == NULL)
{
dprintf(STDOUT_FILENO, "cd: %s: No such file or directory\n", path);
return (1);
}
if (chdir(newpwd) == -1)
{
dprintf(STDOUT_FILENO, "cd: %s: Permission denied\n", path);
free(newpwd);
return (1);
}
setenv("OLDPWD", oldpwd, 1);
setenv("PWD", newpwd, 1);
free(newpwd);
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
const char *msg = "Help function called. Function not yet implemented.\n";

if (info->argv && *info->argv)
{
dprintf(STDOUT_FILENO, "%s\n", *info->argv);
}
else
{
write(STDOUT_FILENO, msg, strlen(msg));
}
return (0);
}
