#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       using the insertion sort algorithm.
* @list: A pointer to the head of a doubly-linked list of integers.
*
* Description: Prints the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *iter;
listint_t *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (iter = (*list)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;

while (iter->prev != NULL && iter->n < iter->prev->n)
{
if (iter->prev->prev != NULL)
iter->prev->prev->next = iter;

if (iter->next != NULL)
iter->next->prev = iter->prev;

iter->prev->next = iter->next;
iter->next = iter->prev;
iter->prev = iter->next->prev;
iter->next->prev = iter;

if (iter->prev == NULL)
*list = iter;

print_list((const listint_t *)*list);
}
}
}
