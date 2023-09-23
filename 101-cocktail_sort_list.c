#include "sort.h"
#include <stdbool.h>

void swap_nodes(listint_t *node_1, listint_t *node_2, listint_t **list);

/**
 * cocktail_sort_list - sort a linked list in ascending order using
 *                      Cocktail Sort algrothim
 * @list: a pointer to the linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL, *temp = NULL;
	bool swaped = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	while (swaped)
	{
		swaped = false;
		while (node->next != NULL)
		{
			temp = node->next;
			if (node->n > node->next->n)
			{
				swaped = true;
				swap_nodes(node, node->next, list);
				print_list(*list);
			}
			node = temp;
		}

		if (!swaped)
			break;

		while (node->prev != NULL)
		{
			temp = node->prev;
			if (node->n < node->prev->n)
			{
				swap_nodes(node->prev, node, list);
				print_list(*list);
			}
			node = temp;
		}
	}
}

/**
 * swap_nodes - swap two doubly linked list nodes
 * @node_1: the first node
 * @node_2: the seconde node
 * @list: pointer to the linked list head
 */

void swap_nodes(listint_t *node_1, listint_t *node_2, listint_t **list)
{
	node_1->next = node_2->next;
	node_2->prev = node_1->prev;
	if (node_1->prev)
		node_1->prev->next = node_2;
	else
		*list = node_2;
	if (node_2->next)
		node_2->next->prev = node_1;
	node_2->next = node_1;
	node_1->prev = node_2;
}
