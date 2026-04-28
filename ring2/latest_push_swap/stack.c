/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:29:58 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 20:42:48 by sthubthi         ###   ########.fr       */
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

void	sa(t_node **stacka)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	second = first->next;
	third = second->next;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stacka = second;
	ft_putstr_fd("sa\n", 1);
}

void	rra(t_node **stacka)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	last = getlast(stacka);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stacka = last;
	ft_putstr_fd("rra\n", 1);
}
