#include "sort.h"
/**
* selection_sort - function that use selection sort algorithm
* @array: array to sort
* @size: size of the array
* Return: none
*/
void selection_sort(int *array, size_t size)
{
int mx = 0;
size_t a = 0, c = 0, lg = 0;

if (array == NULL || size == 0)
return;

for (; a < size - 1; a++)
{
lg = a;
for (c = a + 1; c < size; c++)
{
if (array[c] < array[lg])
lg = c;
}
if (lg != a)
{
mx = array[a];
array[a] = array[lg];
array[lg] = mx;
print_array(array, size);
}
}
}
