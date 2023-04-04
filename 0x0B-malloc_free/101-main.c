#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* print_tab - Prints an array of string
* @tab: The array to print
*
* Return: nothing
*/
void print_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i)
    {
        printf("%s\n", tab[i]);
    }
}

/**
* strtow - Splits a string into words
* @str: The string to split
*
* Return: A pointer to an array of strings
*/
char **strtow(char *str)
{
    char **tab;
    char *token;
    char *delim = " \t\n#";
    int i = 0;
    int j;
    int count = 0;

    /* Count the number of words in the string */
    for (j = 0; str[j] != '\0'; ++j)
    {
        if (str[j] != delim[0] && str[j] != delim[1] &&
            str[j] != delim[2] && str[j] != delim[3])
        {
            if (j == 0 || str[j - 1] == delim[0] || str[j - 1] == delim[1] ||
                str[j - 1] == delim[2] || str[j - 1] == delim[3])
            {
                ++count;
            }
        }
    }

    /* Allocate memory for the array of strings */
    tab = malloc(sizeof(char *) * (count + 1));
    if (tab == NULL)
    {
        return (NULL);
    }

    /* Split the string into tokens and store them in the array */
    token = strtok(str, delim);
    while (token != NULL)
    {
        tab[i] = token;
        ++i;
        token = strtok(NULL, delim);
    }
    tab[i] = NULL;

    return (tab);
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
    char **tab;
    char *str = "      ALX School         #cisfun      ";

    /* Split the string into words */
    tab = strtow(str);
    if (tab == NULL)
    {
        printf("Failed to split the string\n");
        return (1);
    }

    /* Print the array of strings */
    print_tab(tab);

    /* Free the memory allocated for the array of strings */
    free(tab);

    return (0);
}

