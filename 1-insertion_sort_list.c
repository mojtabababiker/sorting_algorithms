#include "sort.h"

void swaps(listint_t **list, listint_t *temps, listint_t *current);


/**
 * insertion_sort_list - sort a doubleyLinked list of integer in
 *                       ascending prder using insertion sort
 * @list: pointer to the head of the linkedList
 */

void insertion_sort_list(listint_t **list){

  /* defind *current, *temps; */
  listint_t *current, *temps;
  
  /* check if list is null, *list is null, (*list)->next is null */
  if (list == NULL || *list == NULL || (*list)->next == NULL)
  /* if the above is true ( return ) */
    return;

  /* assine next from (*list) to current */
  current = (*list)->next;

  /* get into the while loop with checking the current is not null */
  while(current != NULL){

    /* assinge prev from current to temps */
    temps = current->prev;

    /* get into the while loop with checking the temps is not null and n from temp is > n from current */
    while (temps != NULL && temps->n > current->n){

      /* swap temps and current by calling swaps() */
      swaps(list, temps, current);

      temps = current->prev;
      
      /* print the list */
      print_list(*list);

    }

    current = current->next;


  }
  

}

/**
 * swaps - compires the current node value with all its prevouses and
 *          swap between them if thire order incorrect
 * @current: pointer to the current node
 * @list: a pointer to the head of the nodes list
 */

void swaps(listint_t **list, listint_t *temps, listint_t *current){

  /* from temps [prev] & from current [next] */

  /* check if the temps prev is not null then assinge the temps prev next to current */
  if (temps->prev != NULL){
    temps->prev->next = current;
  }

  if (current->next != NULL){
    current->next->prev = temps;
  }


  /* swap temps next to current next */
  temps->next = current->next;

  /* swap current prev to temp prev */
  current->prev = temps->prev;

  /* assinge the current to temps preve */
  temps->prev = current;
  current->next = temps;

  if (current->prev == NULL){
    *list = current;
  }
  
}
