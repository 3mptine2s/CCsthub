/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:57 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:05:58 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && big[i + j] != '\0')
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	const char *big = "Hello, this is a simple example.";
// 	const char *little = "is";
// 	size_t len = 30;

// 	char *result = ft_strnstr(big, little, len);
// 	if (result)
// 		printf("Found: %s\n", result); // Expected: "simple example."
// 	else
// 		printf("Not found within the given length.\n");

// 	return 0;
// }