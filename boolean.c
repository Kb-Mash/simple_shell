#include "header.h"

/**
 * print_message - write the message to the specified file descriptor
 * @fd: file descriptor
 * @message: message printed
 *
 * Return: bytes written, otherwise -1
 */
ssize_t print_message(int fd, const char *message)
{
size_t len = strlen(message);
ssize_t bytes_written = write(fd, message, len);

if (bytes_written == -1)
{
	perror("write");
	return (-1);
}
return (bytes_written);
}

/**
 * main2 - entry point
 *
 * Return: void
 */
int main2(void)
{
bool condition1 = true;
bool condition2 = false;
int fd = STDOUT_FILENO;

if (condition1 && condition2)
{
	print_message(fd, "Both conditions are true\n");
}
else
{
	print_message(fd, "At least one condition is false\n");
}
if (condition1 || condition2)
{
	print_message(fd, "At least one condition is true\n");
}
else
{
	print_message(fd, "Both conditions are false\n");
}
return (0);
}
