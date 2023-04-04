#include "main.h"
#include "wildcmp.h"
/**
 * wildcmp - compares two strings and returns 1 if they can be considered identical
 * @s1: the first string to compare
 * @s2: the second string to compare (may contain wildcard characters '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    if (*s2 == '*')
    {
        /**
	 * If the second string starts with a '*', try matching the first string
	 * with and without the first character of the second string (i.e., '*')
	 */
        return (*s1 && wildcmp(s1 + 1, s2)) || wildcmp(s1, s2 + 1);
    }
    else if (*s1 == *s2)
    {
        /*If the current characters match, continue comparing the rest of the strings*/
        if (*s1 == '\0')
            return 1; /* end of strings, match*/
        else
            return wildcmp(s1 + 1, s2 + 1); /* continue matching*/
    }
    else
    {
        /*If the characters don't match and there's no wildcard, the strings are not identical*/
        return 0;
    }
}

