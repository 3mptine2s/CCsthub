/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:33:54 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 16:14:26 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *string, int fd)
{
	size_t	index;

	index = 0;
	while (string[index])
	{
		write(fd, &string[index], 1);
		index++;
	}
	write(fd, "\n", 1);
}
