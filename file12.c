#include "shell.h"
/**
 * hsh - The main function that runs shell program.
 * @info: A structure contains information about shell program.
 * Return: last executed command or -2 to exit shell program.
 */
int hsh(info_t *info)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
_puts("$ ");
_putchar(BUFFER_FLUSH);
if (r != -1)
{
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
find_command(info);
}
_putchar('\n');
}
write_history(info);
if (builtin_ret == -2)
{
if (info->error_number == -1)
	exit(info->status);
exit(info->error_number);
}
exit(info->status);
return (builtin_ret);
}
/**
 * find_builtin - a function that finds if a given command is a built-in
 * command and calls a corresponding function.
 * @info: A structure contains information about shell prog.
 * Return: executed built-in command or -1 if not found.
 */
int find_builtin(info_t *info)
{
int i, built_in_ret = -1;

struct builtintbl
{
const char *type;
int (*func)(info_t *);
} builtintbl[] = {
	{"exit", handle_exit},
	{"env", current_os_environment},
	{"help", check_help},
	{"history", display_history},
	{"setenv", set_environment},
	{"unsetenv", unset_environment},
	{"cd", handle_cd},
	{"alias", display_alias},
	{NULL, NULL}
};
for (i = 0; builtintbl[i].type; i++)
{
if (strcmp(info->argv[0], builtintbl[i].type) == 0)
{
info->line_count++;
built_in_ret = builtintbl[i].func(info);
break;
}
}
return (built_in_ret);
}
