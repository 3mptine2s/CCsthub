/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:31:27 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 13:21:26 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	xtocoord(int pix, int ss, double min, double max)
{
	double	range;

	range = max - min;
	return (min + ((double) pix * (range / (double) ss)));
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imag * z.imag);
	result.imag = 2.0 * z.real * z.imag;
	return (result);
}

int	stresstestmendel(t_complex C)
{
	t_complex	z;
	int			i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < 100)
	{
		z = complex_square(z);
		z.real += C.real;
		z.imag += C.imag;
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (i * 0x0A0214);
		i++;
	}
	return (0x000000);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]))
	{
		if ((unsigned char) s1[index] != (unsigned char) s2[index])
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
	}
	return (0);
}

double	ft_atoi(const char *nptr)
{
	double	result;
	double	sign;
	double	divisor;

	result = 0.0;
	sign = 1.0;
	divisor = 1.0;
	nptr = parse_space_lines(nptr, &sign);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10.0) + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		while (*nptr >= '0' && *nptr <= '9')
		{
			result = (result * 10.0) + (*nptr - '0');
			divisor *= 10.0;
			nptr++;
		}
	}
	return ((result * sign) / divisor);
}
