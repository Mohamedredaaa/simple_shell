#include "shell.h"

/**
 * _strcmp - Compares two strings lexicographically.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 
 *   - A negative value if s1 comes before s2 in lexicographic order.
 *   - A positive value if s1 comes after s2 in lexicographic order.
 *   - Zero if s1 is equal to s2 in lexicographic order.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


 /**
 * _strlen - function that returns the length of a string.
 * @s: The string to check the length of.
 * Return: An integer representing the length of the string.
 */

int _strlen(char *s)
{
	int q = 0;
	if (!s)
		return (0);
	while (*s++)
		q++;
	return (q);
}  


/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 * Return: A pointer to the destination buffer after concatenation.
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
  

/**
 * starts_with - Checks if the `haystack` string starts with the `needle` substring.
 * @haystack: The string to search.
 * @needle: The substring to find.
 * Return: 
 *   - The address of the next character in `haystack` after the match if `needle` is found.
 *   - NULL if `needle` is not found at the beginning of `haystack`.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)

		if (*needle++ != *haystack++)
			return (NULL);

	return ((char *)haystack);
}

