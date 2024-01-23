#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list in ascending order using Insertion sort.
 * @list: A pointer to the doubly linked list.
 *
 * Description: Prints the list after each node swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            /* Swap nodes */
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *list = temp;
            temp->next->prev = temp;

            /* Print the list after each swap */
            print_list(*list);
        }
        current = current->next;
    }
}
