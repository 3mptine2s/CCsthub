/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:49 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 12:34:52 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int search_str)
{
	int		i;
	char	*temp;

	temp = (char *)str;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)search_str)
		{
			return (&temp[i]);
		}
		i++;
	}
	if (temp[i] == (char)search_str)
	{
		return (&temp[i]);
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	const char *str = "Hello, World!";
// 	char ch = 'H';

// 	char *result = ft_strchr(str, ch);
// 	if (result)
// 		printf("Character '%c' found at position: %d\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", ch);

// 	return 0;
// }