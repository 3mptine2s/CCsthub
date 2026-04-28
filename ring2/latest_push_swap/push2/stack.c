/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:29:58 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 17:11:08 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	last = getlast(aHead);
	second->prev = NULL;
	first->next = NULL;
	first->prev = last;
	*aHead = second;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
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

void	is_sorted(char **args, int start)
{
	int	i;

	if (!args || !args[start] || !args[start + 1])
		return ;
	i = start;
	while (args[i + 1] != NULL)
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
		{
			return ;
		}
		i++;
	}
	exit(1);
}

void	alldigit(char **args, int start)
{
	int	i;
	int	j;

	i = start;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		if (!args[i][j] && start == 1)
			ft_perror(NULL);
		if (!args[i][j] && start == 0)
			ft_perror(args);
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])) && start == 1)
				ft_perror(NULL);
			if (!(ft_isdigit(args[i][j])) && start == 0)
				ft_perror(args);
			j++;
		}
		i++;
	}
}
