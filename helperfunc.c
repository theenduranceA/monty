#include "monty.h"

/*maybe create _exit here, if ever we feel the need for it*/

/* these function do not take # into account yet*/

/**
 * m_strlen - The string length
 * @s: string
 * Return: length
 */

int m_strlen(char *s)
{
	int x;

	for (x = 0; *(s + x); x++)
		;

	return (x);
}


/**
 * m_omit - To skip whitespaces
 * @s: a string
 *
 * Return: pointer to where is the first non space char or NULL
 */

char *m_omit(char *s)
{
	if (!s)
		return (NULL);

	while (*s && (*s == ' ' || *s == '\t' || *s == '\v'))
		s++;
	if (*s == '\0' || *s == '\n' || *s == '#')
		return (NULL);
	return (s);
}


/**
 * m_val - Function to find the first number in a string
 * @s:
 * the string should contain only spaces and a valid opcode before
 * Return: a pointer to where the number (and a number is not 4e) is or NULL
 */

char *m_val(char *s)
{
	char *c;
	int x, y = 0;
	int z = 1;

	if (!s)
		return (NULL);

	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			z = -1;
		y++;
		s++;
	}

	if (*s == '\0')
		return (NULL);
	c = s;
	while (*c && *c >= '0' && *c <= '9')
		c++;

	if (!(*c == '\0' || *c == '\n' || *c == ' ' || *c == '\t'))
	return (NULL);

	x = atoi(s) * z;
	if (x < 0)
	{
		s[y - 1] = '-';
		return (s - 1);
	}
	return (s);
}

/**
 * m_strcmp - Function that compares 2 strings.
 * @s1: First string
 * @s2: Second string
 * Return: The difference in both strings.
*/

int m_strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (*(s1 + x) == *(s2 + x) && *(s1 + x) != '\0' && *(s2 + x) != '\0')
		x++;
	return (*(s1 + x) - *(s2 + x));
}

/**
 * m_strncmp - Function that compare 2 strings.
 * @s1: string to compare
 * @s2: opcode
 * @n: length of opcode to be compared
 * Return: 0 on Success
*/

int m_strncmp(char *s1, char *s2, int n)
{
	int x;

	x = 0;
	while (*(s1 + x) != '\0' && *(s2 + x) != '\0' && x < n)
	{
		if (*(s1 + x) == *(s2 + x))
		{
			x++;
		}
		else
		{
			return (*(s1 + x) - *(s2 + x));
		}
	}
	if (x == n && (*(s1 + x) == ' ' || *(s1 + x) == '\t' ||
		       *(s1 + x) == '\0' || *(s1 + x) == '\n'))
		return (0);

	return (EXIT_FAILURE);
}
