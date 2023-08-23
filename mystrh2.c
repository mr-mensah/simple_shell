#include "simpleshell.h"

/**
 * stringduplicates - function that makes copies of strings
 * @str: argument
 * Return: ret
 */

char *stringduplicates(char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * stringcompare_num - function that compares strings
 * @str1: string number 1
 * @str2: string number 2
 * @n: argument
 * Return: 0
 */

int stringcompare_num(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
	{
		return (str1[i] - str2[i]);
	}
	if (str1[i] == '\0')
	{
		return (0);
	}
	i++;
	}

	return (0);
}

/**
 * file_writers - function that checks for file writers
 * @c: argument
 * @stream: file
 * Return: null
 */

void file_writers(char c, FILE *stream)
{
	if (stream == stdout || stream == stderr)
	{
	write(fileno(stream), &c, 1);
	}
}

