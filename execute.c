#include "holberton.h"

/**
 * @tal: tally of commands or attempted commands that were run in the shell
 * @ex_st: the exit status the show status
 * @args: the parsed argument in the shell
 * @status: the status of the path, whether the file found is executable or not
 * _execute -  it is a function execute in the main shell
 * Return: void
 */
void _execute(int status, char **args, int *ex_st, int *tal)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);

			else
				wait(NULL);
			*ex_st = 0;
		}else if (access(args[0], F_OK) != 0)
		{
			print_str("sh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*ex_st = 127;
		}else if (access(args[0], F_OK) == 0 &&
			 access(args[0], X_OK) != 0)
		{
			print_str("sh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*ex_st = 126;
		}
	}free(args);
}
