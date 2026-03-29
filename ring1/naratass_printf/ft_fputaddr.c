/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputaddr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:45:30 by naratass          #+#    #+#             */
/*   Updated: 2025/10/12 13:12:20 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fputnbr_addr(uintptr_t n);

int	ft_fputaddr(void *ptr)
{
	int			cnt;
	uintptr_t	n;

	if (ptr == NULL)
		return (ft_fputstr(PTRNULL));
	n = (uintptr_t)ptr;
	cnt = ft_fputstr("0x");
	cnt += ft_fputnbr_addr(n);
	return (cnt);
}

static int	ft_fputnbr_addr(uintptr_t n)
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
	ft_fprint_nbr(buf, cnt, 'p');
	return (cnt + is_neg);
}
