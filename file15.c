#include "shell.h"
/**
 * initialize_info_struct - initializes the information structure
 * @info: the info_t struct
 */
void initialize_info_struct(info_t *info)
{
info->argc = 0;
info->argv = NULL;
info->path = NULL;
info->status = 0;
}
/**
 * populate_info_struct - initializes shell information struct
 * @info: the info_t struct
 * @argc: An argument count
 * @argv: An argument vector
 */
void populate_info_struct(info_t *info, int argc, char **argv)
{
int z = 0;
info->argc = argc;
info->argv = malloc((argc + 1) * sizeof(char *));

if (info->argv == NULL)
{
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
while (z < argc)
{
info->argv[z] = strdup(argv[z]);
if (info->argv[z] == NULL)
{
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
z++;
}
info->argv[argc] = NULL;
}
/**
 * release_info_struct - frees shell Info structure fields
 * @info: the info_t struct
 */
void release_info_struct(info_t *info)
{
int i = 0;

if (info->argv != NULL)
{
for (i = 0; i < info->argc; i++)
{
free(info->argv[i]);
}
free(info->argv);
info->argv = NULL;
}
/* Check if info->path is dynamically allocated before freeing */
if (info->path != NULL)
{
free(info->path);
info->path = NULL; /* Set to NULL after freeing */
}
}
