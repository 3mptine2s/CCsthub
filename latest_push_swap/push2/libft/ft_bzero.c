/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:20 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:05:21 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*ptr;
	size_t				i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// void	print_buffer(const char *label, unsigned char *buf, size_t size)
// {
// 	printf("%s: [", label);
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		if (buf[i] == 0)
// 			printf("\\0");
// 		else
// 			printf("%c", buf[i]);
// 		if (i < size - 1)
// 			printf(" ");
// 	}
// 	printf("]\n");
// }

// int	main(void)
// {
// 	// 1. Full buffer
// 	char buf1[5] = {'a','b','c','d','e'};
// 	ft_bzero(buf1, 5);
// 	print_buffer("Test1", (unsigned char *)buf1, 5);

// 	// 2. Partial buffer
// 	char buf2[5] = {'a','b','c','d','e'};
// 	ft_bzero(buf2, 3);
// 	print_buffer("Test2", (unsigned char *)buf2, 5);

// 	// 3. Zero length
// 	char buf3[5] = {'a','b','c','d','e'};
// 	ft_bzero(buf3, 0);
// 	print_buffer("Test3", (unsigned char *)buf3, 5);

// 	// 4. Integer array
// 	int arr[3] = {1,2,3};
// 	ft_bzero(arr, sizeof(arr));
// 	printf("Test4: {%d, %d, %d}\n", arr[0], arr[1], arr[2]);

// 	// 5. Struct
// 	struct Point { int x; int y; };
// 	struct Point p = {5, 10};
// 	ft_bzero(&p, sizeof(p));
// 	printf("Test5: {x=%d, y=%d}\n", p.x, p.y);

// 	// 6. Large buffer
// 	char buf6[10];
// 	memset(buf6, 'A', sizeof(buf6));
// 	ft_bzero(buf6, sizeof(buf6));
// 	print_buffer("Test6", (unsigned char *)buf6, 10);

// 	// 7. Partial zero in the middle
// 	char buf7[8] = {'x','y','z','a','b','c','d','e'};
// 	ft_bzero(buf7 + 2, 3);
// 	print_buffer("Test7", (unsigned char *)buf7, 8);

// 	return 0;
// }
