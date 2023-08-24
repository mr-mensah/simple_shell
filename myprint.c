#include "simpleshell.h"

/**
 * ishell_printer - function that prints arguments
 * Return: null
 */

void ishell_printer(void)
{
	char cwd[1024];
	char hostname[1024];
	time_t rawtime;
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

	time(&rawtime);
	info = localtime(&rawtime);
	strftime(time_buffer, sizeof(time_buffer), "%Y/%m/%d", info);
	_printers("$");
	if (astringcompare(cwd, "/") == 0)
	{
		_printers("$ ");
	}
	else
	{
		_printers(":~");
		_printers(cwd);
		_printers("$ ");
	}
}

