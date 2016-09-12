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

void		mandelgo(t_env *e, double x, double y)
{
	double	i;
	double	c_r;
	double	c_i;
	double 	z_r;
	double	z_i;
	double	tmp;

	c_r = x / WINX * 2 - 2.1;
	c_i = y / WINY * 2 - 1.2;
	z_r = 0;
	z_i = 0;
	i = 0;
	while ((z_r * z_r + z_i * z_i < 4) && (i < 50))
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i + z_i) * tmp + c_i;
		i++;
	}
	if (i == 50)
		my_pixel_put(e, (int)x, (int)y, 0xff0000);
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
