#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at the given index
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @index: Index of the node to delete
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		/* Remove the first node */
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse the list to the node at the specified index */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	if (current == NULL)
		return (-1);

	/* Update the previous node's next pointer */
	if (current->prev != NULL)
		current->prev->next = current->next;

	/* Update the next node's previous pointer */
	if (current->next != NULL)
		current->next->prev = current->prev;

	/* Free the node */
	free(current);

	return (1);
}
