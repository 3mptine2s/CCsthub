/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:31:23 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 12:54:03 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fast_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_len) + (x * (data->bpp) / 8);
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}

int	key_event_handler(int keyid, t_var *var)
{
	if (keyid == XK_Escape)
	{
		mlx_destroy_image(var->mlx_con, var->img);
		mlx_destroy_window(var->mlx_con, var->mlx_win);
		mlx_destroy_display(var->mlx_con);
		free(var->mlx_con);
		exit(1);
	}
	return (0);
}

void	render(t_var *mlx)
{
	t_complex	c;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < MAXH)
	{
		x = 0;
		while (x < MAXW)
		{
			c.imag = xtocoord(y, MAXW, (-2 * mlx->zoom), (2 * mlx->zoom));
			c.real = xtocoord(x, MAXW, (-2 * mlx->zoom), (2 * mlx->zoom));
			fast_pixel_put(mlx, x, y, stresstestmendel(c));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con, mlx->mlx_win, mlx->img, 0, 0);
}

int	ft_isdigit(const char *c)
{
	while ((*c >= '0' && *c <= '9') || *c == '.' || *c == '-' || *c == '+')
	{
		c++;
	}
	if ((*c >= '0' && *c <= '9') || *c == '\0')
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_strncmp("mandelbrot", argv[1]) == 0)
	{
		createmendel();
		return (1);
	}
	else if (argc == 4 && ft_strncmp("julia", argv[1]) == 0)
	{
		if ((ft_isdigit(argv[2]) == 1) && (ft_isdigit(argv[3]) == 1))
		{
			createjulia(ft_atoi(argv[2]), ft_atoi(argv[3]));
			return (1);
		}
	}
	ft_printf("Usage : \n ./fractol mandelbrot\n ");
	ft_printf("./fractol julia double1 double2");
	exit(1);
}
