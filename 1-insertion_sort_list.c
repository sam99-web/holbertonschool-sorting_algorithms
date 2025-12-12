#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node
 * @node2: Second node (must be node1->prev)
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node2->prev)
		node2->prev->next = node1;
	else
		*list = node1;

	if (node1->next)
		node1->next->prev = node2;

	node2->next = node1->next;
	node1->prev = node2->prev;

	node1->next = node2;
	node2->prev = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: Pointer to the head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp, temp->prev);
			print_list(*list);
		}
	}
}

