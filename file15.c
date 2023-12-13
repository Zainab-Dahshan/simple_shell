#include "shell.h"
/**
 * initialize_info_struct - initializes ShellInfo struct
 * @info: struct address
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
 * @shellInfo: struct address
 * @argumentVector: argument vector
 */
void populate_info_struct(info_t *info, int argc, char **argv)
{
int i = 0;
info->argc = argc;
info->argv = malloc((argc + 1) * sizeof(char *));
if (info->argv == NULL) {
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
for (i = 0; i < argc; i++) {
info->argv[i] = strdup(argv[i]);
if (info->argv[i] == NULL) {
/* Handle memory allocation error */
exit(EXIT_FAILURE);
}
}
info->argv[argc] = NULL;
}
/**
 * release_info_struct - frees ShellInfo struct fields
 * @shellInfo: struct address
 * @freeAllFields: true if freeing all fields
 */
void release_info_struct(info_t *info)
{
free(info->argv);
info->argv = NULL;
info->path = '\0';
}
