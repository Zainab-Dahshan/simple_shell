#include "shell.h"
/**
 * get_environment_strings - a function that retrieves an environment
 * strings from an information structure.
 * @info: A pointer to an information structure.
 * Return: An array of strings represent environment variables.
 */
char **get_environment_strings(info_t *info)
{
if (info->env_changed)
{
info->env_changed = 0;
}
return (info->environ);
}
/**
 * remove_environment_variable - a function that removes an environment
 * variable from an information structure.
 * @info: A pointer to an information structure.
 * @variableName: Name of an environment variable to remove.
 * Return: 1 if a variable was successfully removed, 0 otherwise.
 */
int remove_environment_variable(info_t *info, char *variableName)
{
list_t *node = info->env_head;
size_t z = 0;
char *p;

if (!node || !variableName)
	return (1);
while (node)
{
p = node->str;

if (p && strncmp(p, variableName, strlen(variableName)) == 0)
{
info->env_changed = delete_node_at_index(&(info->env_head), z);
z = 0;
node = info->env_head;
continue;
}
node = node->next;
z++;
}
return (info->env_changed ? 0 : 1);
}
/**
 * set_environment_variable - a function that sets an environment
 * variable in an information structure.
 * @info: A pointer to an information structure.
 * @variableName: Name of an environment variable to set.
 * @variableValue: Value of an environment variable to set.
 * Return: 0 on success, otherwise 1 on failure.
 */
int set_environment_variable(info_t *info, char *variableName,
		char *variableValue)
{
char *buffer = NULL;
list_t *node;
char *p = NULL;

if (!variableName || !variableValue)
	return (1);
buffer = malloc(strlen(variableName) + strlen(variableValue) + 2);
if (!buffer)
	return (1);
strcpy(buffer, variableName);
strcat(buffer, "=");
strcat(buffer, variableValue);
node = info->env_head;
while (node)
{
p = node->str;
if (p && strncmp(p, variableName, strlen(variableName)) == 0)
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
node = node->next;
}
free(buffer);
info->env_changed = 1;
return (1);
}
