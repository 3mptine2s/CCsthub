/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:42:41 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/16 17:42:19 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((nmemb * size) > __INT_MAX__
		|| size > __INT_MAX__
		|| nmemb > __INT_MAX__)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
