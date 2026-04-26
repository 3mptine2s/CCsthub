/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:29:46 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 20:42:59 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*startnode(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
	{
		return (NULL);
	}
	node->value = val;
	node->norm = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*getlast(t_node **head)
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

void	inserttail(t_node **head, int value)
{
	t_node	*newnode;
	t_node	*current;

	if (head == NULL)
		return ;
	newnode = startnode(value);
	if (!(newnode))
		return ;
	current = *head;
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	newnode->prev = current;
	newnode->norm = -1;
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	sort_long(char *str)
{
	t_node	*heada;
	t_node	*headb;
	int		i;
	char	**spltstr;

	heada = NULL;
	headb = NULL;
	i = 0;
	spltstr = ft_split(str, ' ');
	if (!spltstr || !spltstr[0])
		ft_perror(spltstr, NULL);
	ft_find_dup(spltstr, 0);
	alldigit(spltstr, 0);
	while (spltstr[i])
	{
		inserttail(&heada, ps_atoi(spltstr[i], spltstr, &heada));
		i++;
	}
	norm2(&heada);
	radix_sort(&heada, &headb, i);
	ft_free_split(spltstr);
	free_stack(&heada);
	exit(0);
}
