/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:44:58 by naratass          #+#    #+#             */
/*   Updated: 2025/10/12 13:07:52 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputstr(char *str)
{
	int	cnt;

	if (!str)
		return (write(1, "(null)", 6));
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (write(1, str, cnt));
}
