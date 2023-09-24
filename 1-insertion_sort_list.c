#include "sort.h"
/**
 * insertion_sort_list - Sorts array of int
 * @list: Array to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			swap_nodes(list, temp, current);

			temp = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
/**
 * swap_nodes - Swaps two nodes in list
 * @list: list
 * @node1: pointer to first node
 * @node2: pointer to second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
	if (node2->prev == NULL)
		*list = node2;
}
