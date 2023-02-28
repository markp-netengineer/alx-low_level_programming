#include "main.h"
/**
 *
 *
 *
 */
void puts2(char *str)
{

	int i;
	int j = 0;
	while (ste[j] != '\0')
	{j++;
	}
	for (i = 0; i < j; i +=2)
	{
		_Putchar(str[i]);
	}
	_putchar('\n');
}
