#include "shell.h"
/**
 * current_os_environment - a function that prints the current
 * Environment or operating system.
 * @info: A structure contains potential arguments.
 * Return: 0 on success, otherwise 1 on failure.
 */
int current_os_environment(info_t *info)
{
print_list(info->env_head);
return (0);
}
/**
 * *get_environment - a function that retrieves the value of
 * an environmental variable.
 * @info: A structure contains potential arguments.
 * @name: Environment variable name.
 * Return: Value of an environment variable, or NULL if not found.
 */
char *get_environment(info_t *info, const char *name)
{
list_t *node = info->env_head;

while (node != NULL)
{
if (node_starts_with(node, name, '=') != NULL)
{
/* found environment variable, return its value */
return (node->str + strlen(name) + 1);
}
node = node->next;
}
return (NULL);
}
/**
 * set_environment - a function that sets environment variables.
 * @info: A structure contains potential arguments.
 * Return: 0 on success, otherwise 1 on failure.
 */
int set_environment(info_t *info)
{
list_t *head = NULL;
char buffer[1024] = {0};
const char *name = "example_name";
const char *value = "example_value";

if (name == NULL || value == NULL || info == NULL)
{
fprintf(stderr, "Invalid input to set_environment\n");
return (0);
}
snprintf(buffer, sizeof(buffer), "%s=%s", name, value);
add_node_end(&info->env_head, buffer);
add_node_end(&head, "some_string");
print_list(head);
return (0);
}
/**
 * unset_environment - a function that unsets environment variables.
 * @info: A structure contains potential arguments.
 * Return: 0 on success, otherwise 1 on failure
 */
int unset_environment(info_t *info)
{
int z;

if (info->argc == 1)
{
_puts("Too few arguments.\n");
return (1);
}
for (z = 1; z < info->argc; z++)
{
if (unsetenv(info->argv[z]) != 0)
{
perror("unsetenv failed");
return (1);
}
/* Assuming info->argv[z] was dynamically allocated */
free(info->argv[z]);
}
return (0);
}
/**
 * populate_environment_list - a function that populates
 * an environment linked list
 * @head: A pointer to a head of a linked list.
 * Return: 0 on success, otherwise 1 on failure.
 */
void populate_environment_list(list_t **head)
{
int x = 0;

for (x = 0; environ[x] != NULL; x++)
{
add_node_end(head, environ[x]);
}
}
