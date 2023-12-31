#include "shell.h"
/**
 * execute_external_command - a function that executes an external command.
 * @info: pointer to a struct contains information about my shell program.
 * Description: This function checks if a command is provided in an argument
 * vector of an info structure. If a command is provided,
 * it attempts to execute the command using the system() function.
 * If the command execution is successful, the function returns 0.
 * If no command is provided or if the command execution fails, the function
 * prints an error message and returns -1.
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
/**
 * tokenize_and_print - This function takes a string as input and splits it
 * into tokens using space as a delimiter.
 * Each token is then printed on a new line.
 * @input: The string to be tokenized. It should contain words separated by
 * spaces.
 * Return: void.
 * Description: The function does not return any value. Instead, it prints
 * the tokens directly.
 */
void tokenize_and_print(const char *input)
{
char *command = strtok((char *)input, " ");

while (command != NULL)
{
printf("%s\n", command);
command = strtok(NULL, " ");
}
}
/**
 * parse_input - this function parses input and splits it
 * into separate commands and handles quoted strings and escaped characters.
 * @input: The input string to be parsed.
 *
 * This function takes a string as input and parses it into separate commands.
 * It handles quoted strings and escaped characters. A quoted string is defined
 * as any sequence of characters enclosed in double quotes. Characters inside a
 * quoted string are treated as a single command, even if they include spaces.
 * An escaped character is defined as a backslash followed by any character.
 * The backslash causes the next character to be treated literally,
 * even if it's a space or a quote.
 *
 * The function uses a state machine to keep track of whether it's currently
 * inside a quoted string or not. It iterates through each character in
 * the input string. If it encounters a space outside of a quoted string,
 * it treats it as a delimiter and adds the current command to the list of
 * commands. If it encounters a double quote, it toggles the inside_quote flag.
 * If it encounters a backslash, it treats the next character as a literal
 * character. Otherwise, it adds the character to the current command.
 *
 * At the end of the function, it prints all the commands it has parsed.
 * It also frees the memory allocated for the command string.
 */
void parse_input(char *input)
{
char *command = malloc(BUFFER_SIZE);
int index = 0;
bool inside_quote = false;
int i = 0;

for (i = 0; input[i] != '\0'; ++i)
{
switch (input[i])
{
case ' ':
if (!inside_quote && index > 0)
{
command[index++] = '\0';
printf("%s\n", command);
index = 0;
}
else
{
command[index++] = input[i];
}
break;
case '"':
inside_quote = !inside_quote;
break;
case '\\':
if (input[i + 1] != '\0')
{
command[index++] = input[++i];
}
break;
default:
command[index++] = input[i];
break;
}
}
if (index > 0)
	command[index] = '\0';
printf("%s\n", command);
free(command);
}
