/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:34:52 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 17:50:26 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_atoi(const char *nptr, char **arg, t_node **head)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
		if ((result * sign) > __INT_MAX__ || (result * sign) < -2147483647)
			ft_perror(arg, head);
	}
	result *= sign;
	return (result);
}

void	ft_find_dup(char **a, int s)
{
	char	**fr;
	int		i;
	int		j;

	if (s == 0)
		fr = a;
	i = s;
	while (a[i] != NULL)
	{
		j = i + 1;
		while (a[j] != NULL)
		{
			if (ps_atoi(a[i], fr, NULL) == ps_atoi(a[i], fr, NULL) && s == 1)
				ft_perror(NULL, NULL);
			if (ps_atoi(a[i], fr, NULL) == ps_atoi(a[i], fr, NULL) && s == 0)
				ft_perror(a, NULL);
			j++;
		}
		i++;
	}
}
