/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 15:09:33 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 15:09:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		my_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	biscolor;

	biscolor = mlx_get_color_value(e->mlx, color);
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (biscolor & 0x0000ff);
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (biscolor & 0x00ff00) >> 8;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (biscolor & 0xff0000) >> 16;
	}
}

// quand on zoom, pour zoomer au milieu il faut rajouter la position (WINX / 2) aux coordonnees

void		mandelgo(t_env *e, double x, double y)
{
	double	i;
	double	tmp;

	e->zoom_x = WINX / (e->x2 - e->x1);
	e->zoom_y = 
	e->c_r = x / WINX / 2 * e->zoom + e->x1;
	e->c_i = y / WINY / 2 * e->zoom + e->x2;
	e->z_r = 0;
	e->z_i = 0;
	i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i < 4) && (i < e->prof))
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = (e->z_i + e->z_i) * tmp + e->c_i;
		i++;
	}
	if (i == e->prof)
		my_pixel_put(e, (int)x, (int)y, 0x5F9EA0);
}

void		mandelbrot(t_env *e)
{
	double	x;
	double 	y;

	x = -1;
	y = -1;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
			mandelgo(e, x, y);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_putendl("let's draw");
}
