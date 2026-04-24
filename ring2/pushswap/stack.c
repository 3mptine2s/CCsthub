#include "pushswap.h"

void ra(t_node **aHead)
{
	t_node 	*first;
	t_node	*second;
	t_node	*last;

	if (!aHead || !*aHead || !(*aHead)->next)
		return;
	first = *aHead;
	second = first->next;
	last = getLast(aHead);

	second->prev = NULL;
	first->next = NULL;
	first->prev = last;

	*aHead = second;

	last->next = first;
	ft_putstr_fd("ra\n",1);
}

void pa(t_node **stackA, t_node **stackB)
{
    t_node  *node_to_move;

    if (!stackB || !*stackB)
        return;
    node_to_move = *stackB;
    *stackB = node_to_move->next;
    if (*stackB != NULL)
        (*stackB)->prev = NULL;
    node_to_move->next = *stackA;
    if (*stackA != NULL)
        (*stackA)->prev = node_to_move;
    node_to_move->prev = NULL;
    *stackA = node_to_move;
	ft_putstr_fd("pa\n",1);
}


void pb(t_node **stackA, t_node **stackB)
{
	t_node  *node_to_move;

    if (!stackA || !*stackA)
        return;
    node_to_move = *stackA;
    *stackA = node_to_move->next;
    if (*stackA != NULL)
        (*stackA)->prev = NULL;
    node_to_move->next = *stackB;
    if (*stackB != NULL)
        (*stackB)->prev = node_to_move;
    node_to_move->prev = NULL;
    *stackB = node_to_move;
	ft_putstr_fd("pb\n",1);
}

int is_sorted(t_node **stack)
{
    t_node *current;

    if (!stack || !*stack)
        return (1);
    current = *stack;
    while (current->next != NULL)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int alldigit(char **args)
{
	int i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}