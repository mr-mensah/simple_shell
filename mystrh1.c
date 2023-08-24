#include "simpleshell.h"

/**
 * mystringlength - function that finds the length
 * @str: argument
 * Return: len
 */

int mystringlength(const char *str)
{
	int len;

	len = 0;
	if (!str)
	{
		return (0);
	}

	while (*str != '\0')
	{
		len = len + 1;
		str = str + 1;
	}

	return (len);
}

/**
 * astringcompare - function that watches two strings
 * @str1: string number one
 * @str2: string number two
 * Return: 1
 */

int astringcompare(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
/**
 * findcharacters - function that finds characters
 * @str: argument
 * @character: characters
 * Return: res
 */

char *findcharacters(char *str, char *character)
{
	int len_str, len_char;
	char *res;
	int i;

	len_str = 0;
	len_char = 0;
	while (*(character + len_char) != '\0')
		len_char++;

	while (*(str + len_str) != '\0')
		len_str++;

	for (i = 0; i < len_char; i++)
	{
		if (*(character + i) != *(str + i))
		{
			return ((char *)NULL);
		}
	}

	res = (char *)str;
	return (res);
}

/**
 * appendstrings - function that stops strings
 * @dest: argument
 * @src: argument
 * Return: destination
 */

char *appendstrings(char *dest, const char *src)
{
	int dest_length;
	int i;
	int src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	while (src[src_length] != '\0')
	{
		src_length++;
	}

	for (i = 0; i < src_length; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return (dest);
}

/**
 * copystrings- function used to duplicate strings
 * @dests: arguments
 * @source: arguments
 * Return: destination
 */

char *copystrings(char *dests, char *source)
{
	int i;

	i = 0;

	if (dests == source || source == 0)
	{
		return (dests);
	}

	while (source[i] != '\0')
	{
		dests[i] = source[i];
		i++;
	}

	dests[i] = '\0';

	return (dests);
}

