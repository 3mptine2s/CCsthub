#include "pushswap.h"

int	get_position(t_node *stack, int t)
{
	int		i;
	t_node	*current;

	if (!stack || t < 0)
		ft_perror(NULL, NULL, "Sroy");
	current = stack;
	i = 0;
	while (current != NULL)
	{
		if (current->norm == t)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	push_t(t_node **stack_a, t_node **stack_b, int t, int size)
{
	int	pos;

	pos = get_position(*stack_a, t);
	if (pos <= (size / 2))
	{
		while ((*stack_a)->norm != t)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->norm != t)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_3(t_node **stack_a)
{
	int	highest;

	highest = (*stack_a)->norm;
	if ((*stack_a)->next->norm > highest)
		highest = (*stack_a)->next->norm;
	if ((*stack_a)->next->next->norm > highest)
		highest = (*stack_a)->next->next->norm;
	if ((*stack_a)->norm == highest)
		ra(stack_a);
	else if ((*stack_a)->next->norm == highest)
		rra(stack_a);
	if ((*stack_a)->norm > (*stack_a)->next->norm)
		sa(stack_a);
}

void	sort_small(t_node **stack_a, t_node **stack_b, int size)
{
	int	pushed;

	if (size == 2)
	{
		if ((*stack_a)->norm > (*stack_a)->next->norm)
			sa(stack_a);
		return ;
	}
	pushed = 0;
	while ((size - pushed) > 3)
	{
		push_t(stack_a, stack_b, pushed, size - pushed);
		pushed++;
	}
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
	}
}

void	execute_sort(t_node **heada, t_node **headb, int size)
{
	norm2(heada);
	if (size <= 5)
	{
		sort_small(heada, headb, size);
	}
	else
	{
		radix_sort(heada, headb, size);
	}
}
