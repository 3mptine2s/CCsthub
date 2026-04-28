/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:36:11 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/25 17:04:20 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "libft.h"

void	ft_find_dup(char **args, int start)
{
	int	i;
	int	j;

	i = start;
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j] != NULL)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]) && start == 1)
				ft_perror(NULL);
			if (ft_atoi(args[i]) == ft_atoi(args[j]) && start == 0)
				ft_perror(args);
			j++;
		}
		i++;
	}
}
