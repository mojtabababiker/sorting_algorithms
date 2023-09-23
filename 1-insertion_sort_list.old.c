#include "sort.h"

/**
 * insert - compires the current node value with all its prevouses and
 *          swap between them if thire order incorrect
 * @crnt_node: pointer to the current node
 * @list: a pointer to the head of the nodes list
 */

void insert(listint_t *crnt_node, listint_t **list)
{
  listint_t *prv_node, *temp_2;
  
  while(crnt_node->prev != NULL)
    {
      prv_node = crnt_node->prev;
      /*check if the crnt value is < prev value*/
      /*then swap them togther*/
      if (crnt_node->n < prv_node->n)
	{
	  /*swap them togther*/
	  prv_node->next = crnt_node->next;
	  crnt_node->prev = prv_node->prev;
	  if (prv_node->prev)
	    prv_node->prev->next = crnt_node;
	  else
	    *list = crnt_node;
	  if (crnt_node->next)
	    crnt_node->next->prev = prv_node;
	  crnt_node->next = prv_node;
	  prv_node->prev = crnt_node;
	  temp_2 = prv_node;
	  prv_node = crnt_node;
	  crnt_node = temp_2;
	}/*if (crnt_node->n < prv_node->n)*/
      crnt_node = crnt_node->prev;
    }/*second while*/
}


/**
 * insertion_sort_list - sort a doubleyLinked list of integer in
 *                       ascending prder using insertion sort
 * @list: pointer to the head of the linkedList
 */

void insertion_sort_list(listint_t **list)
{
  listint_t *crnt_node, *temp_1, *nxt_node;

  crnt_node = *list;

  if (list == NULL || *list == NULL)
    return;

  while(crnt_node->next != NULL)
    {
      /*if the crnt value is > the next value*/
      nxt_node = crnt_node->next;
      temp_1 = crnt_node->next;
      if (crnt_node->n > nxt_node->n)
	{
	  /*swap them togther*/
	  crnt_node->next = nxt_node->next;
	  nxt_node->prev = crnt_node->prev;
	  if (crnt_node->prev)
	    crnt_node->prev->next = nxt_node;
	  else
	    *list = nxt_node;
	  if (nxt_node->next)
	    nxt_node->next->prev = crnt_node;
	  nxt_node->next = crnt_node;
	  crnt_node->prev = nxt_node;
	  insert(crnt_node, list);
	  print_list(*list);
	  crnt_node = temp_1;
	}/*if (crnt_node->n > nxt_node->n)*/
      crnt_node = temp_1;
      /*crnt_node = crnt_node->next;*/
    }/*first while*/
}/*insertion_sort_list*/
