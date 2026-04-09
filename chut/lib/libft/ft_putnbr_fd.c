/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:26:32 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 17:08:02 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	long	nbr;

	nbr = num;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((int)(nbr / 10), fd);
		ft_putnbr_fd((int)(nbr % 10), fd);
	}
	else
		ft_putchar_fd((char)(nbr + '0'), fd);
}
