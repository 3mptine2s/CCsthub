#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>
//gcc main.c -Lmlx_linux -l:libmlx.a -o process -lX11 -lXext
typedef struct svar
{
    void *mlx_con;
    void *mlx_win;
} xvar;

int event_handler(int keyid, xvar *var)
{
    if (keyid == XK_Escape)
    {
        mlx_destroy_window(var->mlx_con,var->mlx_win);
        mlx_destroy_display(var->mlx_con);
        free(var->mlx_con);
        exit(1);
    }
}

int main()
{
    xvar mlx;

    mlx.mlx_con = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx_con,500,500,"Test");
    if (mlx.mlx_con == NULL || mlx.mlx_win == NULL)
    {
        return(0);
    }

    mlx_key_hook(mlx.mlx_win,event_handler,&mlx);
    mlx_loop(mlx.mlx_con);
}