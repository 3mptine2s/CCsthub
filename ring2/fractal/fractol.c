#include "fractol.h"


void fast_pixel_put(xvar *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_len) + (x * (data->bpp)/8); //offset calc
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}

int		key_event_handler(int keyid, xvar *var) // for key hook
{
	if (keyid == XK_Escape) // close program
	{
		mlx_destroy_image(var->mlx_con,var->img);
		mlx_destroy_window(var->mlx_con,var->mlx_win);
		mlx_destroy_display(var->mlx_con);
		free(var->mlx_con);
		exit(1);
	}
	return (0);
}

void	render(xvar *mlx)
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
			C.imag = xtocoord(y,MAX_WIN_WID,(-2 * mlx->zoom),(2 * mlx->zoom));
			C.real = xtocoord(x,MAX_WIN_WID,(-2 * mlx->zoom),(2 * mlx->zoom));
			fast_pixel_put(mlx,x,y,stresstestmendel(C));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_con,mlx->mlx_win,mlx->img,0,0);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && ft_strncmp("mandelbrot", argv[1]) == 0)
    {
		createmendel();
		return (1);
    }
	else if (argc == 4 && ft_strncmp("julia", argv[1]) == 0)
	{
		createjulia(ft_atoi(argv[2]), ft_atoi(argv[3]));
		return (1);
	}
	ft_printf("Usage : \n ./fractol mandelbrot\n ");
	ft_printf("./fractol julia double1 double2");
	exit(1);
}
