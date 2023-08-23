#include "simpleshell.h"
/**
 * _myprint - function that helps prints character
 * @str: printed string
 * Return: null
 */
void _myprint(char *str)
{
int lin;
if (!str)
{
return;
}
lin = 0;
while (str[lin] != '\0')
{
lin++;
}
write(1, str, lin);
}
