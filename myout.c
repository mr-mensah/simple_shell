#include "simpleshell.h"

/**
 * _printers - function that brings out
 * @str: argument to be printed
 * Return: null
 */

void _printers(char *str)
{
	int len;

	if (!str)
	{
		return;
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	write(1, str, len);
}

