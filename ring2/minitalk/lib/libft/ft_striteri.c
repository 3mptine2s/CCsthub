/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:08:46 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 15:32:24 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*func)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	while (string[index])
	{
		(*func)(index, &string[index]);
		index++;
	}
}
