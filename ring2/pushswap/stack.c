#include "pushswap.h"

void	ra(t_node **aHead)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!aHead || !*aHead || !(*aHead)->next)
		return ;
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

void	pa(t_node **stacka, t_node **stackb)
{
	t_node	*node_to_move;

	if (!stackb || !*stackb)
		return ;
	node_to_move = *stackb;
	*stackb = node_to_move->next;
	if (*stackb != NULL)
		(*stackb)->prev = NULL;
	node_to_move->next = *stacka;
	if (*stacka != NULL)
		(*stacka)->prev = node_to_move;
	node_to_move->prev = NULL;
	*stacka = node_to_move;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stacka, t_node **stackb)
{
	t_node	*node_to_move;

	if (!stacka || !*stacka)
		return ;
	node_to_move = *stacka;
	*stacka = node_to_move->next;
	if (*stacka != NULL)
		(*stacka)->prev = NULL;
	node_to_move->next = *stackb;
	if (*stackb != NULL)
		(*stackb)->prev = node_to_move;
	node_to_move->prev = NULL;
	*stackb = node_to_move;
	ft_putstr_fd("pb\n", 1);
}

int	is_sorted(t_node **stack)
{
	t_node	*current;

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

int	alldigit(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] == '+' || args[i][j] == '-')
		{
			j++;
		}
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
