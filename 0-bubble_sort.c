#include "sort.h"
#include <stdio.h>
/**
* swap_ints - Swap two integers in an array.
* @c: The first integer to swap.
* @d: The second integer to swap.
*/
void swap_ints(int *c, int *d)
{
int temp = *c;
*c = *d;
*d = temp;
}
/**
* bubble_sort - fucntion that sort an array of integers in
*               ascending order using bubble algorith
*@array: pointer to int
*@size:  size of the array being provided
* Return: none
*/
void bubble_sort(int *array, size_t size)
{
size_t e, len = size;
bool bubbly = false;

if (array == NULL || size < 2)
return;

while (bubbly == false)
{
bubbly = true;
for (e = 0; e < len - 1; e++)
{
if (array[e] > array[e + 1])
{
swap_ints(&array[e], &array[e + 1]);
print_array(array, size);
bubbly = false;
}
}
len--;
}
}
