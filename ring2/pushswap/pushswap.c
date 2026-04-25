#include "pushswap.h"

void	norm2(t_node **head)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	if (!head || !*head)
		return ;
	current = *head;
	while (current != NULL)
	{
		count = 0;
		compare = *head;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->norm = count;
		current = current->next;
	}
}

int	get_max_bits(int size)
{
	int	maxnorm;
	int	maxbit;

	maxbit = 0;
	maxnorm = size - 1;
	while ((maxnorm >> maxbit) != 0)
	{
		maxbit++;
	}
	return (maxbit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int		max_bits;
	int		i;
	int		j;
	t_node	*head_a;

	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head_a = *stack_a;
			if (((head_a->norm >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

void	ft_perror(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	main(int argc, char **argv)
{
	t_node	*heada;
	t_node	*headb;
	int		i;

	heada = NULL;
	headb = NULL;
	i = 1;
	if ((alldigit(argv) == 0) || argc < 2)
	{
		ft_perror();
		return (1);
	}
	while (argv[i])
	{
		inserttail(&heada, ft_atoi(argv[i]));
		i++;
	}
	norm2(&heada);
	radix_sort(&heada, &headb, i - 1);
	free_stack(&heada);
	return (0);
}