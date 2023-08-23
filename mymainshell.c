#include "simpleshell.h"
/**
 * main - function that contains the mainfunction
 * @argc: argument
 * @argv: argument
 * Return: 1
 */
int main(int argc, char *argv[])
{
int description;
int solution;
char *line;
size_t line_len;
ownership file;
info_t info;
int built_in_ret;
line = NULL;
info.show = 0;
file.show_flag = 0;
description = 0;
line_len = 0;
built_in_ret = 0;
if (argc > 1)
{
description = open(argv[1], O_RDONLY);
if (description < 0)
{
perror(argv[1]);
return (1);
}
}
file.explainer = description;
signal(SIGINT, ctrlCno);
solution = loopshellmain(description, argc, argv, line, line_len,
file, info, built_in_ret);
return (solution);
}
/**
 * ctrlCno - blocks control c
 * @thisway: signal number in the function
 * Return: null
 */
void ctrlCno(int thisway)
{
(void)thisway;
_printer("\n");
shell_printer();
}
