#include "fractol.h"

void	rendermendel(xvar *mlx)
{
	tcomplex	C;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < MAX_WIN_H)
	{
		x = 0;
		while (x < MAX_WIN_WID)
		{
			C.imag = xtocoord(y,MAX_WIN_H,(-2 * mlx->zoom),(2 * mlx->zoom));
			C.real = xtocoord(x,MAX_WIN_WID,(-2 * mlx->zoom),(2 * mlx->zoom));
			fast_pixel_put(mlx,x,y,stresstestmendel(C));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con,mlx->mlx_win,mlx->img,0,0);
}

int createmendel()
{
	xvar 	mlx;

	mlx.mlx_con = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_con, MAX_WIN_WID,MAX_WIN_H, "Test");
	if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
		return (0);
	mlx.img = mlx_new_image(mlx.mlx_con, MAX_WIN_WID, MAX_WIN_H);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	mlx.zoom = 1;
	rendermendel(&mlx);
	mlx_key_hook(mlx.mlx_win,key_event_handler,&mlx);
	mlx_mouse_hook(mlx.mlx_win,mmouse_event_handler,&mlx);
	mlx_loop(mlx.mlx_con);
	return (1);
}

int	stresstestjulia(tcomplex pixcord, double c_real, double c_imag)
{
	tcomplex	z;
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
	return(0x000000);
}

void	renderjulia(jvar *mlx)
{
	tcomplex	C;
	int			x;
	int			y;

	y = 0;
	while (y < MAX_WIN_H)
	{
		x = 0;
		while (x < MAX_WIN_WID)
		{	
			C.imag = xtocoord(y, MAX_WIN_H,(2 * mlx->zoom), (-2 * mlx->zoom));
			C.real = xtocoord(x, MAX_WIN_WID,(-2 * mlx->zoom), (2 * mlx->zoom));
			fast_pixel_putj(mlx,x,y,stresstestjulia(C, mlx->real, mlx->imag));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con, mlx->mlx_win, mlx->img,0,0);
}

int createjulia(double num1, double num2)
{
	jvar	mlx;

	mlx.real = num1;
	mlx.imag = num2;
	mlx.mlx_con = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_con, MAX_WIN_WID,MAX_WIN_H, "Test");
	if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
		return (0);
	mlx.img = mlx_new_image(mlx.mlx_con, MAX_WIN_WID, MAX_WIN_H);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	mlx.zoom = 1;
	renderjulia(&mlx);
	mlx_key_hook(mlx.mlx_win,jkey_event_handler,&mlx);
	mlx_mouse_hook(mlx.mlx_win,jmouse_event_handler,&mlx);
	mlx_loop(mlx.mlx_con);
	return (1);
}
