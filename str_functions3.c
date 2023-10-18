#include "shell.h"

/**
 * strtow2 - Splits a string into words using a specified delimiter.
 * @d: The delimiter character.
 * @str: The input string to be split.
 * This function takes an 'str' string and splits it into words using the provided 'd' delimiter.
 * It returns a pointer to an array of strings, where each element is a word extracted from 'str.'
 * Return: A pointer to an array of strings or NULL on failure.
 */

char **strtow2(char *str, char d)
{
	int e, f, t, r, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (e = 0; str[e] != '\0'; e++)
		if ((str[e] != d && str[e + 1] == d) ||
		    (str[e] != d && !str[e + 1]) || str[e + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (e = 0, f = 0; f < numwords; f++)
	{
		while (str[e] == d && str[e] != d)
			e++;
		t = 0;
		while (str[e + t] != d && str[e + t] && str[e + t] != d)
			t++;
		s[f] = malloc((t + 1) * sizeof(char));
		if (!s[f])
		{
			for (t = 0; t < f; t++)
				free(s[t]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < t; r++)
			s[f][r] = str[e++];
		s[f][r] = 0;
	}
	s[f] = NULL;
	return (s);
}

/**
 * 
 * strtow - Splits a string into words using a delimiter. Repeated delimiters are ignored.
 * @d: The delimiter string.
 * @str: The input string to be split.
 * This function takes an 'str' string and splits it into words using the provided 'd' delimiter.
 * Repeated delimiters are treated as a single delimiter. It returns a pointer to an array of
 * strings, where each element is a word extracted from 'str.'
 *
 * Return: A pointer to an array of strings or NULL on failure.
 */

char **strtow(char *str, char *d)
{
	int s, y, o, g, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (s = 0; str[s] != '\0'; s++)
		if (!is_delim(str[s], d) && (is_delim(str[s + 1], d) || !str[s + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (s = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[s], d))
			s++;
		o = 0;
		while (!is_delim(str[s + o], d) && str[s + o])
			o++;
		s[y] = malloc((o + 1) * sizeof(char));
		if (!s[y])
		{
			for (o = 0; o < y; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (g = 0; g < o; g++)
			s[y][g] = str[s++];
		s[y][g] = 0;
	}
	s[y] = NULL;
	return (s);
}


