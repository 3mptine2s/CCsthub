/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:46 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:05:47 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static int	int_length(int n)
{
	int	length;

	length = 0;
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int	get_digit(int n, int digit)
{
	int	i;

	i = 0;
	while (i < digit)
	{
		n /= 10;
		i++;
	}
	return (n % 10);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	length;
	int	i;

	if (nb == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd);
		nb *= -1;
	}
	else if (nb == 0)
	{
		ft_putchar('0', fd);
	}
	length = int_length(nb);
	i = 0;
	while (i < length)
	{
		ft_putchar(get_digit(nb, length - i - 1) + '0', fd);
		i++;
	}
}

// int main()
// {
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putchar('\n', 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	ft_putchar('\n', 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putchar('\n', 1);
// 	ft_putnbr_fd(12345, 1);
// 	ft_putchar('\n', 1);
// 	ft_putnbr_fd(-67890, 1);
// 	ft_putchar('\n', 1);
// 	return (0);
// }