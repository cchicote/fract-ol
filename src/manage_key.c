/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 15:09:13 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 15:09:23 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		treat_keycode(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("goodbye");
		exit(0);
	}
	ft_bzero(e->data, e->sl * WINY);
	if (keycode == 124)
		e->x1 += 0.01;
	else if (keycode == 125)
		e->x2 += 0.01;
	else if (keycode == 126)
		e->x2 -= 0.01;
	else if (keycode == 123)
		e->x1 -= 0.01;
	else if (keycode == 69)
		e->prof++;
	else if (keycode == 78 && e->prof > 1)
		e->prof--;
	else if (keycode == 47)
	{
		e->x1 += WINX / 2 / e->zoom / 2;
		e->x2 += WINY / 2 / e->zoom / 2;
		e->zoom += 0.05;
	}
	else if (keycode == 43)
	{
		e->x1 -= WINX / 2 / e->zoom / 2;
		e->x2 -= WINY / 2 / e->zoom / 2;
		e->zoom -= 0.05;
	}
}

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	mandelbrot(e);
	return (0);
}
