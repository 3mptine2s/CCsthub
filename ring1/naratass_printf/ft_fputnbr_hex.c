/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputnbr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:13:34 by naratass          #+#    #+#             */
/*   Updated: 2025/10/30 13:13:35 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputnbr_hex(unsigned int n, char format)
{
	int			cnt;
	int			is_neg;
	char		buf[1024];
	const char	*hex = "0123456789abcdef";

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
		buf[cnt] = hex[n % 16];
		n /= 16;
		cnt++;
	}
	ft_fprint_nbr(buf, cnt, format);
	return (cnt + is_neg);
}
