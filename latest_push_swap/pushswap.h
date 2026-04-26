/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:29:54 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 20:41:17 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct snode
{
	int				norm;
	int				value;
	struct snode	*next;
	struct snode	*prev;
}	t_node;

void	ft_find_dup(char **a, int s);
int		ps_atoi(const char *nptr, char **arg, t_node **head);
t_node	*startnode(int val);
void	inserttail(t_node **head, int value);
t_node	*getlast(t_node **head);
void	ra(t_node **aHead);
void	pa(t_node **stackA, t_node **stackB);
void	pb(t_node **stackA, t_node **stackB);
void	free_stack(t_node **stack);
void	is_sorted(char **args, int start);
void	alldigit(char **args, int start);
void	ft_perror(char **arr, t_node **head);
void	radix_sort(t_node **stack_a, t_node **stack_b, int size);
void	norm2(t_node **head);
void	sort_long(char *str);

#endif
