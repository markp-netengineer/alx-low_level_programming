#include <stdio.h>
/**
 *swap_int - swaps the values of two integers.
 *
 *
 */
void swap_int(int *a ,int *b)
/*the function that swaps values of integers*/
{
int temp = *a;
    *a = *b;
    *b = temp;
}
