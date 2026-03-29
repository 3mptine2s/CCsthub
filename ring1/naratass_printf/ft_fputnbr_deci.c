/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:45:45 by naratass          #+#    #+#             */
/*   Updated: 2025/10/13 00:16:47 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputnbr_deci(long n)
{
	int			cnt;
	int			is_neg;
	char		buf[32];

	if (n == 0)
		return (ft_fputchar('0'));
	is_neg = 0;
	cnt = 0;
	if (n < 0)
	{
		ft_fputchar('-');
		is_neg = 1;
		n = -n;
	}
	while (n > 0)
	{
		buf[cnt] = (n % 10) + '0';
		n /= 10;
		cnt++;
	}
	ft_fprint_nbr(buf, cnt, 'd');
	return (cnt + is_neg);
}
