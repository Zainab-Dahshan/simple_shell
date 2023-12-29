#include "shell.h"
/**
* bufferInput - a function that buffers chained commands
* @info: Information structure
* @inputBuffer: Buffer address
* Return: bytes that read
*/
ssize_t bufferInput(info_t *info, char **inputBuffer)
{
ssize_t readBytes;
size_t len_p;
(void)info;

free(*inputBuffer);
*inputBuffer = NULL;
signal(SIGINT, signalInterruptHandler);
readBytes = getline(inputBuffer, &len_p, stdin);
if (readBytes == -1)
{
/* Handle error or return -1 as appropriate */
perror("getline");
}
return (readBytes);
}
/**
* retrieveInput - a function that gets a line minus a newline
* @info: An information structure
* Return: bytes that read
*/
char *retrieveInput(info_t *info)
{
char buffer[READ_BUFFER_SIZE];
ssize_t bytesRead = 0;
size_t totalBytesRead = 0;
size_t bufferSize = MAXIMUM_BUFFER_SIZE;
char *inputBuffer = malloc(bufferSize);

if (!inputBuffer)
{
/* Handle error or return NULL as appropriate */
perror("malloc");
return (NULL);
}
memset(inputBuffer, BUFFER_FLUSH, bufferSize);
while ((bytesRead = bufferInput(info, &inputBuffer)) > 0)
{
if (totalBytesRead + bytesRead >= bufferSize - 1)
{
bufferSize *= 2;
inputBuffer = realloc(inputBuffer, bufferSize);

if (!inputBuffer)
	return (NULL);

memset(inputBuffer + totalBytesRead, BUFFER_FLUSH,
		bufferSize - totalBytesRead);
}

memcpy(inputBuffer + totalBytesRead, buffer, bytesRead);
totalBytesRead += bytesRead;

if (buffer[bytesRead - 1] == '\n')
	break;
}
if (totalBytesRead == 0 && bytesRead == -1)
{
free(inputBuffer);
return (NULL);
}
return (inputBuffer);
}
/**
* readBuffer - a function that reads a buffer
* @info: An information structure
* @buffer: buffer
* @index: size
* Return: r
*/
ssize_t readBuffer(info_t *info, char *buffer, size_t *index)
{
ssize_t readBytes = 0;

if (*index)
	return (0);
readBytes = read(info->readfd, buffer, READ_BUFFER_SIZE);
if (readBytes >= 0)
	*index = readBytes;
return (readBytes);
}
/**
* getLine - a function that gets a next line of input from STDIN
* @info: An information structure
* @pointer: address of pointer to buffer, preallocated or NULL
* @length: size of preallocated pointer buffer if not NULL
* Return: s
*/
int getLine(info_t *info, char **pointer, size_t *length)
{
static char buf[READ_BUFFER_SIZE];
static size_t index, len;
size_t position;
ssize_t readBytes = 0, size = 0;
char *p = NULL, *newPointer = NULL, *character;
p = *pointer;

if (p && length)
	size = *length;
if (index == len)
	index = len = 0;
readBytes = readBuffer(info, buf, &len);
if (readBytes == -1 || (readBytes == 0 && len == 0))
	return (-1);
character = strchr(buf + index, '\n');
position = character ? 1 + (unsigned int)(character - buf) : len;
newPointer = realloc(p, size ? size + position : position + 1);
if (!newPointer) /* MALLOC FAILURE! */
	return (p ? free(p), -1 : -1);
if (size)
	strncat(newPointer, buf + index, position - index);
else
strncpy(newPointer, buf + index, position - index + 1);
size += position - index;
index = position;
p = newPointer;
if (length)
*length = size;
*pointer = p;
return (size);
}
/**
* signalInterruptHandler - blocks ctrl-C
* @signalNumber: the signal number
* Return: void
*/
void signalInterruptHandler(__attribute__((unused))int signalNumber)
{
puts("\n");
puts("$ ");
putchar(BUFFER_FLUSH);
}
