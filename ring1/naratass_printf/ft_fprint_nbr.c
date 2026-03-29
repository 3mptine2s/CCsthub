/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:13:56 by naratass          #+#    #+#             */
/*   Updated: 2025/10/30 13:14:08 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fprint_nbr(char *buf, int cnt, char format)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (format == 'X')
			buf[cnt - i - 1] = ft_toupper(buf[cnt - i - 1]);
		write(1, &buf[cnt - i - 1], 1);
		i++;
	}
}
