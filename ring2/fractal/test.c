#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>
//gcc test.c -Lmlx_linux -l:libmlx.a -o process -lX11 -lXext
typedef struct svar
{
	void	*mlx_con; //free mlx_destroy_display free prio (img, win, dis) or small to big
	void	*mlx_win; //free mlx_destroy_window
	void	*img; //free mlx_destroy_image
	char	*addr;
	int	 	bpp; //bit per pix
	int	 	line_len; //bytes per one horizontal line
	int	 	endian; // how the cpu read (no need to bother)
} xvar;

int event_handler(int keyid, xvar *var) // for key hook
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

void fast_pixel_put(xvar *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_len) + (x * (data->bpp)/8);
	dst = data->addr + offset;
	*(unsigned int *) dst = color;

}

int main()
{
	xvar mlx;

	mlx.mlx_con = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_con,500,500,"Test");
	mlx.img = mlx_new_image(mlx.mlx_con,500,500);
	mlx.addr = mlx_get_data_addr(mlx.img,&mlx.bpp,&mlx.line_len,&mlx.endian);
	if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
	{
		return(0);
	}

	int x = 0;
	int y = 0;

	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			fast_pixel_put(&mlx,x,y,0x0000FF);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(mlx.mlx_con,mlx.mlx_win,mlx.img,0,0);
	mlx_key_hook(mlx.mlx_win,event_handler,&mlx);
	mlx_loop(mlx.mlx_con);
}