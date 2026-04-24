#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct snode
{
	int				norm;
	int				value;
	struct snode*	next;
	struct snode*	prev;
} t_node;

t_node *startNode(int   val);
void	insertTail(t_node** head, int value);
int		ft_atoi(const char *nptr);
t_node *getLast(t_node **head);
void 	ra(t_node **aHead);
void	pa(t_node **stackA, t_node **stackB);
void	pb(t_node **stackA, t_node **stackB);
void 	free_stack(t_node **stack);
int 	is_sorted(t_node **stack);
int 	alldigit(char **args);
#endif
