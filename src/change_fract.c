/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 15:09:33 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 15:09:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		change_fract(t_env *e)
{
	if (e->fractnum > 3)
		e->fractnum = 1;
	else if (e->fractnum < 1)
		e->fractnum = 3;
	free(e->proj);
	if (e->fractnum == 1)
		e->proj = ft_strdup("mandelbrot");
	else if (e->fractnum == 2)
		e->proj = ft_strdup("julia");
	else if (e->fractnum == 3)
		e->proj = ft_strdup("burningship");
	reset_param(e);
	navigante(e);
}

void		find_fractnum(t_env *e)
{
	if (ft_strcmp(e->proj, "julia") == 0)
		e->fractnum = 2;
	else if (ft_strcmp(e->proj, "mandelbrot") == 0)
		e->fractnum = 1;
	else if (ft_strcmp(e->proj, "burningship") == 0)
		e->fractnum = 3;
}

void		rectangle(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y <= 25)
	{
		x = -1;
		while (++x <= 50)
		{
			if (y == 25 || x == 25 || x == 1 || y == 1)
				my_pixel_put(e, x, y, 0xffffff);
			else
				my_pixel_put(e, x, y, 0x000000);
		}
		my_pixel_put(e, x, y, 0xffffff);
	}
}
