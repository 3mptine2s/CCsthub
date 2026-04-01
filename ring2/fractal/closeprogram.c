/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeprogram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:29:40 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 14:35:36 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_programm(t_var *var)
{
	mlx_destroy_image(var->mlx_con, var->img);
	mlx_destroy_window(var->mlx_con, var->mlx_win);
	mlx_destroy_display(var->mlx_con);
	free(var->mlx_con);
	exit(1);
}

int	close_programj(t_jvar *var)
{
	mlx_destroy_image(var->mlx_con, var->img);
	mlx_destroy_window(var->mlx_con, var->mlx_win);
	mlx_destroy_display(var->mlx_con);
	free(var->mlx_con);
	exit(1);
}
