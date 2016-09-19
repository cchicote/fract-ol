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

void		prep_julia(t_env *e, double x, double y)
{
	if (e->x1 == 0 && e->x2 == 0 && e->y1 == 0 && e->y2 == 0)
	{
		e->x1 = -1;
		e->x2 = 1;
		e->y1 = -1.2;
		e->y2 = 1.2;
	}
	julia(e, x, y);
}

void		julia(t_env *e, double x, double y)
{
	double	i;
	double	tmp;

	e->c_r = 0.285;
	e->c_i = 0.01;
	e->z_r = x / WINX / 2 * e->zoom + e->x1;
	e->z_i = y / WINY / 2 * e->zoom + e->y1;
	i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i < 4) && (i < e->prof))
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = (e->z_i + e->z_i) * tmp + e->c_i;
		i++;
	}
	if (i == e->prof)
		my_pixel_put(e, (int)x, (int)y, e->color);
}

void		prep_mandelbrot(t_env *e, double x, double y)
{
	if (e->x1 == 0 && e->x2 == 0 && e->y1 == 0 && e->y2 == 0)
	{
		e->x1 = -2.1;
		e->y1 = 0.6;
		e->x2 = -1.2;
		e->y2 = 1.2;
	}
	mandelbrot(e, x, y);
}

void		mandelbrot(t_env *e, double x, double y)
{
	double	i;
	double	tmp;

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
		my_pixel_put(e, (int)x, (int)y, e->color);
}

void		navigante(t_env *e)
{
	double	x;
	double 	y;

	x = -1;
	y = -1;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
		{
			if (ft_strcmp(e->proj, "julia") == 0)
				prep_julia(e, x, y);
			else
				prep_mandelbrot(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_putendl("let's draw");
}
