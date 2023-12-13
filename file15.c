#include "shell.h"
/**
 * initialize_info_struct - initializes ShellInfo struct
 * @info: pointer to the info_t struct
 */
void initialize_info_struct(info_t *info)
{
info->argc = 0;
info->argv = NULL;
info->path = '\0';
info->status = 0;
}
/**
 * populate_info_struct - initializes ShellInfo struct
 * @info: pointer to the info_t struct
 * @argc: argument count
 * @argv: argument vector
 */
void populate_info_struct(info_t *info, int argc, char **argv)
{
int i = 0;
info->argc = argc;
info->argv = malloc((argc + 1) * sizeof(char *));

if (info->argv == NULL)
{
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
for (i = 0; i < argc; i++)
{
info->argv[i] = strdup(argv[i]);
if (info->argv[i] == NULL)
{
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
}
info->argv[argc] = NULL;
}
/**
 * release_info_struct - frees ShellInfo struct fields
 * @info: pointer to the info_t struct
 */
void release_info_struct(info_t *info)
{
free(info->argv);
info->argv = NULL;
info->path = '\0';
}
