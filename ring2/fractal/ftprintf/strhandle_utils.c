/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandle_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:32:01 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 12:32:02 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftputc(char c)
{
	write(1, &c, 1);
}

int	pctprint(void)
{
	ftputc('%');
	return (1);
}

int	ftstrlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
