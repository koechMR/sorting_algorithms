#include "sort.h"
#include <stdio.h>
/**
* swap - Swap two integers in an array.
* @c: The first integer to swap.
* @d: The second integer to swap.
*/
void swap(int *c, int *d)
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
size_t x, z;
int temp;
for (x = 0; x < size - 1; x++)
{
for (z = 0; z < size - x - 1; z++)
{
if (array[z] > array[z + 1])
{
temp = array[z];
array[z] = array[z + 1];
array[z + 1] = temp;
}
}
}
}
