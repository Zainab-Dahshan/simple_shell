#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <memory.h>

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 100
#define INFO_INIT \
{0, 0, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, \
	NULL, 0, 0, NULL, NULL, 0, NULL}
#define READ_BUFFER_SIZE 1024
#define MAXIMUM_BUFFER_SIZE 1024
#define BUFFER_FLUSH '\n'
#define MAXIMUM_PATH_SIZE 1024
#define MAXIMUM_COMMAND_LENGTH 1024
#define MAXIMUM_ARGUMENTS 100
#define MAXIMUM_COMMANDS 100
#define MAXIMUM_ARGUMENTS 100
#define MAXIMUM_HISTORY_SIZE 100
#define STDERR_FILENO 2
#define CONVERT_UNSIGNED 1
#define STDOUT_FILENO 1
#define CONVERT_LOWERCASE 2
/**
 * struct list_s - A structure to represent a linked list node.
 * @str: A pointer to a string stored in a node.
 * @next: A pointer to a next node in a linked list.
 * Description: `list_t` structure used to represent
 * a node in a linked list. Each node contains a pointer to
 * a string and a pointer to a next node.
 * A linked list can be traversed by following `next` pointers
 * from one node to another.
 */
typedef struct list_s
{
char *str;
struct list_s *next;
} list_t;
/**
 * struct info_s - A structure to hold information about
 * execution of a program.
 * @env_head: A pointer to linked list represents environment variables.
 * @history: A pointer to linked list represents a command history.
 * @alias: A pointer to linked list represents a command aliases.
 * @status: Status of command execution where zero status
 * indicates success, and a non-zero status indicates an error.
 * @error_number: Error number if an error occurred at
 * command execution.
 * @fname: A string represents a file name.
 * @line_count: An integer represent a line count.
 * @readfd: An integer represents a file descriptor for reading input.
 * @writefd: An integer represent write file descriptor.
 * @result: A result of an input read operation
 * @builtin_ret: A return value of A builtin command execution
 * @command_buffer: A pointer to a pointer to string represents
 * a command buffer.
 * @histcount: An integer that represents command history count.
 * @tokens: A pointer to an array of strings representing the command tokens.
 * @argc: Number of arguments passed to our program.
 * @argv: An array of pointers to strings represents arguments
 * that passed to our program.
 * @environ: An array of strings that represents environment variables.
 * @env_changed: A flag indicates whether environment variables have changed.
 * @path: The path to executable files.
 * Description:`info_t` struct is used to store information
 * about a program execution. It contains pointers to linked lists for
 * command history and aliases, as well as number of arguments passed
 * to program and an array of pointers to strings represents arguments.
 */
typedef struct info_s
{
int status;
int error_number;
list_t *history;
list_t *env_head;
list_t *alias;
char *fname;        /* File name */
int readfd;
int writefd;
int line_count;     /* Line count */
ssize_t result;
int builtin_ret;
char **command_buffer;
int histcount;
int argc;
char **argv;
char **environ;
int env_changed;
char *path;
char *tokens;
} info_t;

/**
 * struct builtin - Structure represent built-in command table
 * @type: Name of a built-in command
 * @func: Pointer to corresponding function for a command
 * Description:
 * This structure represents built-in commands table used for finding
 * and executing built-in commands in my shell program.
 */
typedef struct builtin
{
const char *type;
int (*func)(info_t *);
} builtin_table;

extern char **environ;

	/*file1.c*/
int check_interactive_mode(info_t *info);
int check_delimiter(char c, char *delimeter);
int check_alpha(int c);
int string_to_integer(char *str);
int main(int argc, char **argv);
	/*file2.c*/
int handle_exit(info_t *info);
int handle_cd(info_t *info);
int check_help(info_t *info);
	/*file3.c*/
int display_history(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int display_alias(info_t *info);
void print_list(list_t *head);
int delete_node_at_index(list_t **head, int index);
char *_strchr(const char *s, int c);
void _putchar(char c);
void _puts(const char *s);
list_t *node_starts_with(list_t *head, const char *prefix, char delimiter);
int get_node_index(list_t *head, list_t *node);
	/*file4.c*/
int current_os_environment(info_t *info);
void print_list(list_t *list);
/* void add_node_end(list_t **head, const char *str); */
char *get_environment(info_t *info, const char *name);
int set_environment(info_t *info);
int unset_environment(info_t *info);
void populate_environment_list(list_t **head);
/* file6.c */
int print_character(char character);
int print_string(const char *input);
int write_character(char character, int file_descriptor);
int print_string_fd(const char *input, int file_descriptor);
/* file7.c */
void print_decimal(int input, int fd);
char *number_converter(long int num, int base, int flags);
void comment_remover(char *buffer);
void display_error(info_t *info, char *estr);
/* file8.c */
char *our_strncpy(char *dest, const char *src, int n);
char *our_strncat(char *dest, const char *src, int n);
char *our_strchr(const char *s, char c);
/* file9.c */
ssize_t input_buffer(info_t *info, char **buf, size_t *len);
bool memory_free(void **memory);
/* file10.c */
char *string_duplicate(const char *s);
/* Notes */
void read_history(info_t *info);
/* void hsh(info_t *info, char **argv); */
/* file11.c */
char *string_concat(char *destination, char *source);
char *begins_with(const char *haystack, const char *needle);
int string_compare(const char *str1, const char *str2);
int string_length(char *str);
/* file12.c */
int search_builtin(info_t *info);
void search_command(info_t *info);
void execute_command(info_t *info);
/* file12*.c */
int hsh(info_t *info);
int find_builtin(info_t *info);
void find_command(info_t *info);
void fork_command(info_t *info);
/* file13.c */
ssize_t bufferInput(info_t *info, char **inputBuffer);
char *retrieveInput(info_t *info);
ssize_t readBuffer(info_t *info, char *buffer, size_t *index);
int getLine(info_t *info, char **pointer, size_t *length);
void signalInterruptHandler(__attribute__((unused))int signalNumber);
/* file14.c */
char **get_environment_strings(info_t *info);
int remove_environment_variable(info_t *info, char *variableName);
int set_environment_variable(info_t *info, char *variableName,
		char *variableValue);
/* file15.c */
void initialize_info_struct(info_t *info);
void populate_info_struct(info_t *info, int argc, char **argv);
void release_info_struct(info_t *info);
/* file16 */
char *get_history_file(const char *homedir);
int write_history(info_t *info);
int read_history_list(info_t *info);
FILE *open_history_file(const char *filename);
int write_history_node(FILE *fp, const list_t *node);
/* file16-1.c */
int renumber_history(info_t *info);
int add_history(info_t *info, const char *line);
void free_history(list_t **head);
/* file16-2.c */
void close_history_file(FILE *fp);
void free_history_node(list_t *node);
list_t *allocate_history_node(const char *line);
/* file17.c */
int add_node(list_t **head, char *str);
int add_node_end(list_t **head, char *str);
size_t print_list_string(const list_t *h);
int delete_node_at_index(list_t **head, int index);
void free_list(list_t **head_ptr);
/* file19.c */
char *_memset(char *s, char b, unsigned int n);
void ffree(char ***pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* file20.v */
int is_chain(info_t *info);
int check_chain(info_t *info);
list_t *node_starts_with(list_t *head, const char *prefix, char delimiter);
void replace_vars(info_t *info);
/* file21 */
int _count_words(char *str, char *d);
char *_copy_word(char *str, char *d);
/*file22.c */
int count_words(char *str, char delimiter);
char **allocate_memory(int number_words);
void copy_words(char **s, char *str, char delimiter, int number_words);
/* main.c */
int open_file(info_t *info, char *filename);
void initialize_info(info_t *info);

#endif
