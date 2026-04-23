#include "pushswap.h"

t_node *startNode(int   val)
{
	t_node *node;
	
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
	{
		return (NULL);
	}
	node->value = val;
	node->norm = -1;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

t_node *getLast(t_node **head)
{
	t_node	*last;

	if (!head || !*head)
		return (NULL);
	
	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	insertTail(t_node** head, int value)
{
	t_node	*newNode;
	t_node 	*current;

	if (head == NULL)
		return;
	newNode = startNode(value);
	if (!(newNode))
		return;
	current = *head;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newNode;
	newNode->prev = current;
	newNode->norm = -1;
}

void free_stack(t_node **stack)
{
    t_node *current;
    t_node *temp;

    if (!stack || !*stack)
        return;
    
    current = *stack;
    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}
