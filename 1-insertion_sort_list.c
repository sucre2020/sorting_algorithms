#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: the doubly linked list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tail = NULL;
	listint_t *b_i = NULL, *ins = NULL;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	tail = (*list)->next;
	while (tail != NULL)
	{
		ins = tail;
		b_i = tail->prev;
		while (b_i != NULL)
		{
			if (ins->n < b_i->n)
			{
				ins->prev = b_i->prev;
				b_i->next = ins->next;
				b_i->prev = ins;
				ins->next = b_i;
				if (ins->prev != NULL)
					ins->prev->next = ins;
				else
					*list = ins;
				if (b_i->next != NULL)
					b_i->next->prev = b_i;
				b_i = ins->prev;
				print_list(*list);
			}
			else
				break;
		}
		tail = tail->next;
	}
}
