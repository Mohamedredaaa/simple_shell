#include "shell.h"

/**
 * non_interactive - handles non_interactive mode
 * Return: void
 */
void non_interactive(void)
{
	char **current_command = NULL;
	int e, type = 0;
	size_t w = 0;
	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &w, stdin) != -1)
		{
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");
			for (e = 0; commands[e] != NULL; e++)
			{
				current_command = tokenizer(commands[e], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}type = parse_command(current_command[0]);
				initializer(current_command, type);
				free(current_command);
			}free(commands);
		}free(line);
		exit(status);
	}
}
