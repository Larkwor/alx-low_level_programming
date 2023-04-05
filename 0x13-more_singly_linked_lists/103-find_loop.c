#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p3;
	listint_t *prev;

	p3 = head;
	prev = head;
	while (head && p3 && p3->next)
	{
		head = head->next;
		p3 = p3->next->next;

		if (head == p3)
		{
			head = prev;
			prev =  p3;
			while (1)
			{
				p3 = prev;
				while (p3->next != head && p3->next != prev)
				{
					p3 = p3->next;
				}
				if (p3->next == head)
					break;

				head = head->next;
			}
			return (p3->next);
		}
	}

	return (NULL);
}

