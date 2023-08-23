#include "simpleshell.h"
/**
 * cust_print - function that prints custom arguments
 * Return: null
 */
void cust_print(void)
{
char cwd[1024];
char hostname[1024];
time_t rwtime;
struct tm *info;
char time_buffer[80];
if (getcwd(cwd, sizeof(cwd)) == NULL)
{
perror("getcwd");
exit(EXIT_FAILURE);
}
if (gethostname(hostname, sizeof(hostname)) != 0)
{
perror("gethostname");
exit(EXIT_FAILURE);
}
time(&rwtime);
info = localtime(&rwtime);
strftime(time_buffer, sizeof(time_buffer), "%Y/%m/%d", info);
_printer("$");
if (stringcompare(cwd, "/") == 0)
{
_printer("$ ");
}
else
{
_printer(":~");
_printer(cwd);
_printer("$ ");
}
}
