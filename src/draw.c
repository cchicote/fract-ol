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
				julia(e, x, y);
			else if (ft_strcmp(e->proj, "burningship") == 0)
				burningship(e, x, y);
			else
				mandelbrot(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void		mandelbrot(t_env *e, double x, double y)
{
	double	i;
	double	tmp;

	e->c_r = (x - WINX / 2) / e->zoom + e->pos_x;
	e->c_i = (y - WINY / 2) / e->zoom + e->pos_y;
	e->z_r = e->mouse_param_x;
	e->z_i = e->mouse_param_y;
	i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i < 4) && (i < e->prof))
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = (e->z_i + e->z_i) * tmp + e->c_i;
		i++;
	}
	my_pixel_put(e, (int)x, (int)y, choose_color(e, i));
}

void		julia(t_env *e, double x, double y)
{
	double	i;
	double	tmp;

	e->c_r = e->mouse_param_x;
	e->c_i = e->mouse_param_y;
	e->z_r = (x - WINX / 2) / e->zoom + e->pos_x;
	e->z_i = (y - WINY / 2) / e->zoom + e->pos_y;
	i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i < 4) && (i < e->prof))
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = (e->z_i + e->z_i) * tmp + e->c_i;
		i++;
	}
	my_pixel_put(e, (int)x, (int)y, choose_color(e, i));
}

void		burningship(t_env *e, double x, double y)
{
	double i;
	double tmp;

	e->z_r = e->mouse_param_x;
	e->z_i = e->mouse_param_y;
	e->c_r = (x - WINX / 2) / e->zoom + e->pos_x;
	e->c_i = (y - WINY / 2) / e->zoom + e->pos_y;
	i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i < 4) && (i < e->prof))
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * fabs(e->z_i) * fabs(tmp) + e->c_i;
		i++;
	}
	my_pixel_put(e, (int)x, (int)y, choose_color(e, i));
}
