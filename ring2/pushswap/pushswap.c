#include "pushswap.h"

void norm2(t_node **head)
{
	t_node  *current;
	t_node  *compare;
	int     count;
	// Safety check to ensure the list exists
	if (!head || !*head)
		return;

	current = *head;

	// Outer Loop: Select the target node to be ranked
	while (current != NULL)
	{
		count = 0;
		compare = *head;
		
		// Inner Loop: Compare the target against every node in the list
		while (compare != NULL)
		{
			// If we find a number strictly smaller, increment our rank counter
			if (compare->value < current->value)
			{
				count++;
			}
			compare = compare->next;
		}
		
		// Assign the final count as the normalized norm
		current->norm = count;
		
		// Move to the next target node
		current = current->next;
	}
}

int get_max_bits(int size)
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

void radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int		max_bits;
	int		i;
	int		j;
	t_node	*head_a;

	max_bits = get_max_bits(size);

	i = 0;
	// OUTER LOOP: Iterate through each bit, starting from the 0th bit (right-most)
	while (i < max_bits)
	{
		j = 0;
		// INNER LOOP: Process every single node currently in Stack A
		while (j < size)
		{
			head_a = *stack_a;
			
			// Shift the index 'i' places to the right, and use bitwise AND (& 1)
			// If the bit is 1, keep it in A. If 0, toss it to B.
			if (((head_a->norm >> i) & 1) == 1)
			{
				ra(stack_a);
			}
			else
			{
				pb(stack_a, stack_b);
			}
			j++;
		}
		
		// REASSEMBLY: Push everything from B back to A before the next bit pass
		while (*stack_b != NULL)
		{
			pa(stack_a, stack_b);
		}
		
		i++;
	}
}

void ft_perror()
{
	ft_putstr_fd("Error\n",2);
}

int main(int argc, char **argv)
{
	t_node  *headA;
	t_node	*headB;
	int     i;

	headA = NULL;
	headB = NULL;
	i = 1;
	if ((alldigit(argv) == 0) || argc < 2)
	{
		ft_perror();
		return (1);
	}
	while (argv[i])
	{
		insertTail(&headA, ft_atoi(argv[i]));
		i++;
	}
	norm2(&headA);
	radix_sort(&headA, &headB, i - 1);
	free_stack(&headA);
	return (0);
}