#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "shell.h"
/**
* main - entry point
* @argc: arg count
* @argv: arg vector
* Return: 0 on success, 1 on error
*/
int main(int argc, char **argv)
{
info_t info[] = { { 0 } };
int fd = 2;
list_t *env_head = NULL;

asm volatile ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));
if (argc == 2)
{
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
	exit(126);
if (errno == ENOENT)
{
puts(argv[0]);
puts(": 0: Can't open ");
puts(argv[1]);
putchar('\n');
putchar(BUFFER_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info[0].readfd = fd;
}
populate_environment_list(&env_head);
read_history_list(info);
hsh(info);
return (0);
}
