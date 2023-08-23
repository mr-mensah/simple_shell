#include "simpleshell.h"
/**
 * error_fan - function that shows errors
 * @info: argument
 * @message: message
 * Return: null
 */
void error_fan(info_t *info, const char *message)
{
char *reveal;
int message_len;
int argv_leng;
int shell_leng;
int line_leng;
char *error_message;
ssize_t bytes_written;
reveal = intchanger(info->reveal, 10, 0);
message_len = stringlength(message);
argv_leng = stringlength(info->argv[0]);
shell_leng = stringlength(info->shell);
line_leng = stringlength(reveal);
error_message = (char *)malloc(message_len
+line_leng + argv_leng + shell_leng + 7);
if (info == NULL)
return;
if (error_message == NULL)
{
perror("Error: Memory allocation failure");
exit(EXIT_FAILURE);
}
copystring(error_message, info->shell);
appendstring(error_message, ": ");
appendstring(error_message, reveal);
appendstring(error_message, ": ");
appendstring(error_message, info->argv[0]);
appendstring(error_message, ": ");
appendstring(error_message, message);
bytes_written = write(STDERR_FILENO,
error_message, stringlength(error_message));
if (bytes_written == -1)
{
perror("Error: Write failure");
free(error_message);
exit(EXIT_FAILURE);
}
free(error_message);
}
/**
 * intchanger - function that changes integers
 * @number:  number
 * @base: base
 * @flags: flags
 * Return: null
 */
char *intchanger(long int number, int base, int flags)
{
static char *charArray;
static char buffer[50];
char sign = 0;
char *chagstr;
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
chagstr = &buffer[49];
*chagstr = '\0';
do {
*--chagstr = charArray[quotient % base];
quotient /= base;
} while (quotient != 0);
if (sign)
*--chagstr = sign;
return (chagstr);
}
