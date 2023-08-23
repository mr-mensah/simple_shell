#include "simpleshell.h"
/**
 * e_constructer - function that finds error
 * @info: argument
 * @message: argument
 * Return: null
 */

void e_constructer(info_t *info, const char *message)
{
	char *show;
	int message_length;
	int argv_length;
	int shell_length;
	int line_length;
	char *error_message;
	ssize_t bytes_written;

	show = numbconverter(info->show, 10, 0);
	message_length = stringlength(message);
	argv_length = stringlength(info->argv[0]);
	shell_length = stringlength(info->shell);
	line_length = stringlength(show);
	error_message = (char *)malloc(message_length
			+ line_length + argv_length + shell_length + 7);
	if (info == NULL)
		return;

	if (error_message == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	copystring(error_message, info->shell);
	appendstring(error_message, ": ");
	appendstring(error_message, show);
	appendstring(error_message, ": ");
	appendstring(error_message, info->argv[0]);
	appendstring(error_message, ": ");
	appendstring(error_message, message);
	bytes_written = write(STDERR_FILENO,
			error_message, stringlength(error_message));
	if (bytes_written == -1)
	{
		perror("Error: Write failed");
		free(error_message);
		exit(EXIT_FAILURE);
	}
	free(error_message);
}

/**
 * numbconverter - function that converts number to words
 * @number:  argument
 * @base: argument
 * @flags: argument
 * Return: changed
 */

char *numbconverter(long int number, int base, int flags)
{
	static char *charArray;
	static char buffer[50];
	char sign = 0;
	char *strPtr;
	unsigned long int quotient;

	if (!(flags) && number < 0)
	{
		quotient = -number;
		sign = '-';
	}
	else
	{
	quotient = number;
	}
	charArray = "0123456789ABCDEF";
	strPtr = &buffer[49];
	*strPtr = '\0';
	do {
		*--strPtr = charArray[quotient % base];
		quotient /= base;
	} while (quotient != 0);

	if (sign)
	*--strPtr = sign;
	return (strPtr);
}

