#include "simpleshell.h"

/**
 * main - function that calls on the main entry
 * @argc: argument
 * @argv: argument
 * Return: result
 */

int main(int argc, char *argv[])
{
	int descriptor;
	int result;
	char *line;
	size_t line_length;
	ownership file;
	info_t info;
	int built_in_ret;

	line = NULL;
	info.show = 0;
	file.show_flag = 0;
	descriptor = 0;
	line_length = 0;
	built_in_ret = 0;

	if (argc > 1)
	{
		descriptor = open(argv[1], O_RDONLY);
		if (descriptor < 0)
		{
			perror(argv[1]);
			return (1);
		}
	}

	file.explainer = descriptor;
	signal(SIGINT, icontrolC);
	result = shellloopmain(descriptor, argc, argv, line, line_length,
			file, info, built_in_ret);
	return (result);
}

/**
 * icontrolC - blocks ctrl-C and avoid compiler warning
 * @thisway: signal number in the function
 *
 * Return: Nothing
 */
void icontrolC(int thisway)
{
	(void)thisway;
	_printers("\n");
	ishell_printer();
}

