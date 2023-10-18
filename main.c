#include "shell.h"

/**
 * main - The entry point of the program.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * This is the main function that serves as the entry point for the program. It takes
 * the argument count 'ac' and the argument vector 'av' as parameters. The function returns
 * 0 on successful execution and 1 in case of an error.
 *
 * Return: 0 on success, 1 on error.
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}