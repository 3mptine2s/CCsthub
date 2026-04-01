/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:31:29 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 14:32:39 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rendermendel(t_var *mlx)
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
			c.imag = xtocoord(y, MAXH, (-2 * mlx->zoom), (2 * mlx->zoom));
			c.real = xtocoord(x, MAXW, (-2 * mlx->zoom), (2 * mlx->zoom));
			fast_pixel_put(mlx, x, y, stresstestmendel(c));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con, mlx->mlx_win, mlx->img, 0, 0);
}

void	createmendel(void)
{
	t_var	mlx;

	mlx.mlx_con = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_con, MAXW, MAXH, "Test");
	if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
	{
		free(mlx.mlx_con);
		free(mlx.mlx_win);
		exit (0);
	}
	mlx.img = mlx_new_image(mlx.mlx_con, MAXW, MAXH);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	mlx.zoom = 1;
	rendermendel(&mlx);
	mlx_key_hook(mlx.mlx_win, key_event_handler, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_programm, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mmouse_event_handler, &mlx);
	mlx_loop(mlx.mlx_con);
}

int	stresstestjulia(t_complex pixcord, double c_real, double c_imag)
{
	t_complex	z;
	int			i;

	z.real = pixcord.real;
	z.imag = pixcord.imag;
	i = 0;
	while (i < 100)
	{
		z = complex_square(z);
		z.real += c_real;
		z.imag += c_imag;
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return ((i + 3) * 0x09f4f1);
		i++;
	}
	return (0x000000);
}

void	renderjulia(t_jvar *mlx)
{
	t_complex	c;
	int			x;
	int			y;

	y = 0;
	while (y < MAXH)
	{
		x = 0;
		while (x < MAXW)
		{
			c.imag = xtocoord(y, MAXH, (2 * mlx->zoom), (-2 * mlx->zoom));
			c.real = xtocoord(x, MAXW, (-2 * mlx->zoom), (2 * mlx->zoom));
			fast_pixel_putj(mlx, x, y, stresstestjulia(c, mlx->r, mlx->i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con, mlx->mlx_win, mlx->img, 0, 0);
}

int	createjulia(double num1, double num2)
{
	t_jvar	mlx;

	mlx.r = num1;
	mlx.i = num2;
	mlx.mlx_con = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_con, MAXW, MAXH, "Test");
	if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
		return (0);
	mlx.img = mlx_new_image(mlx.mlx_con, MAXW, MAXH);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	mlx.zoom = 1;
	renderjulia(&mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_programj, &mlx);
	mlx_key_hook(mlx.mlx_win, jkey_event_handler, &mlx);
	mlx_mouse_hook(mlx.mlx_win, jmouse_event_handler, &mlx);
	mlx_loop(mlx.mlx_con);
	return (1);
}
