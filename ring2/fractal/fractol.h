/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:31:38 by sthubthi          #+#    #+#             */
/*   Updated: 2026/04/01 14:35:52 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>

# define MAXW 	800
# define MAXH		800

typedef struct svar
{
	void	*mlx_con;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
}	t_var;

typedef struct dvar
{
	void	*mlx_con;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	r;
	double	i;
}	t_jvar;

typedef struct scomplex
{
	double	real;
	double	imag;
}	t_complex;

double			xtocoord(int pix, int ss, double min, double max);
t_complex		complex_square(t_complex z);
int				stresstestmendel(t_complex C);		
int				ft_strncmp(const char *s1, const char *s2);
void			createmendel(void);
int				mmouse_event_handler(int keyid, int x, int y, t_var *var);
int				key_event_handler(int keyid, t_var *var);
int				createjulia(double num1, double num2);
void			fast_pixel_put(t_var *data, int x, int y, int color);
double			ft_atoi(const char *nptr);
int				jmouse_event_handler(int keyid, int x, int y, t_jvar *var);
void			fast_pixel_putj(t_jvar *data, int x, int y, int color);
void			renderjulia(t_jvar *mlx);
void			rendermendel(t_var *mlx);
const char		*parse_space_lines(const char *nptr, double *sign);
int				jkey_event_handler(int keyid, t_jvar *var);
int				ft_printf(const char *inp, ...);
int				close_programj(t_jvar *var);
int				close_programm(t_var *var);

#endif