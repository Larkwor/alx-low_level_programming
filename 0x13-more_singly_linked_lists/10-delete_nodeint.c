#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t linked list.
 * @head: pointer to the pointer to the head node.
 * @index: index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (*head == NULL) /* empty list */
		return (-1);

	if (index == 0) /* delete first node */
	{
		current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}

	/* delete node at index > 0 */
	previous = *head;
	for (i = 0; i < index - 1 && previous != NULL; i++)
		previous = previous->next;

	if (previous == NULL || previous->next == NULL) /* index out of range */
		return (-1);

	current = previous->next;
	previous->next = current->next;
	free(current);

	return (1);
}
