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

int	is_overflow(long int res, int sign, char digit)
{
	if (res > 214748364)
		return (1);
	if (res == 214748364 && sign == 1 && (digit - '0') > 7)
		return (1);
	if (res == 214748364 && sign == -1 && (digit - '0') > 8)
		return (1);
	return (0);
}

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
		if (is_overflow(result, sign, nptr[i]))
			ft_perror(arg, head, "Int cap");
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_find_dup(char **a, int s)
{
	char	**fr;
	int		i;
	int		j;

	fr = NULL;
	if (s == 0)
		fr = a;
	i = s;
	while (a[i] != NULL)
	{
		j = i + 1;
		while (a[j] != NULL)
		{
			if (ps_atoi(a[i], fr, NULL) == ps_atoi(a[j], fr, NULL) && s == 1)
				ft_perror(NULL, NULL, "Duplicate");
			if (ps_atoi(a[i], fr, NULL) == ps_atoi(a[j], fr, NULL) && s == 0)
				ft_perror(a, NULL, "Duplicate");
			j++;
		}
		i++;
	}
}

void	is_sorted(char **args, int start)
{
	int		i;
	char	**fr;

	fr = NULL;
	if (start == 0)
		fr = args;
	if (!args || !args[start] || !args[start + 1])
	{
		if (fr)
			ft_free_split(fr);
		exit(0);
	}
	i = start;
	while (args[i + 1] != NULL)
	{
		if (ps_atoi(args[i], fr, NULL) > ps_atoi(args[i + 1], fr, NULL))
		{
			return ;
		}
		i++;
	}
	if (fr)
		ft_free_split(fr);
	exit(0);
}

void    alldigit(char **args, int start)
{
	int		i;
	int		j;
	char	**fr;

	fr = NULL;
	if (start == 0)
		fr = args;
	i = start;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		if (!args[i][j])
			ft_perror(fr, NULL, "Digit Error");
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])))
				ft_perror(fr, NULL, "Digit Error");
			j++;
		}
		ps_atoi(args[i], fr, NULL); 
		i++;
	}
}
