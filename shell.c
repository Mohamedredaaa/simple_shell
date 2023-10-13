#include "holberton.h"

/** 
 * @argc:  count argument
 * @argv:  vector argument
 * @env: the environment variable
 * main - it is the simple UNIX command interpreter
 * Return: zero
 */
int main(int argc, char **argv, char **env)
{
	char *prompt = "##--->";
	char *line = NULL;
	char **args = NULL;
	int h = 0, sta = 0, arg_num = 0;
	static int exit_stat, tally;
	size_t len = 0;
	ssize_t read = 0;
	(void)argc, (void)**argv;
	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, 6);

		read = getline(&line, &len, stdin);
		++tally;
		if (special_char(line, read, &exit_stat) == 127)
			continue;

		no_nl(line);
		args = parser(line);
		for (h = 0; args[h]; h++)
			arg_num++;

		builtins(line, args, env, &exit_stat);
		sta = _path(args[0], args, env, &exit_stat);
		_execute(sta, args, &exit_stat, &tally);
		fflush(stdin);
	}
	free(line);
	return (0);
}
