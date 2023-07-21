#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Cocktail shaker sort algorithm.
 *
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = NULL;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (listint_t *current = *list; current->next != end; current = current->next)
        {
            if (current->n > current->next->n)
            {
                if (current->prev)
                    current->prev->next = current->next;
                else
                    *list = current->next;
                if (current->next->next)
                    current->next->next->prev = current;
                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                swapped = 1;
                print_list(*list);
            }
        }
        end = (*list)->prev;
        if (!swapped)
            break;
        swapped = 0;
        for (listint_t *current = end; current->prev != start; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                if (current->next)
                    current->next->prev = current->prev;
                else
                    end = current->prev;
                if (current->prev->prev)
                    current->prev->prev->next = current;
                current->next = current->prev;
                current->prev = current->prev->prev;
                current->next->prev = current;
                if (!current->prev)
                    *list = current;
                swapped = 1;
                print_list(*list);
            }
        }
        start = (*list)->next;
    } while (swapped);
}
