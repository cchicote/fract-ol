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

void		treat_keycode_2(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 65361)
		e->x1 -= 0.01;
	else if (keycode == 69 || keycode == 65451)
		e->prof++;
	else if ((keycode == 78 || keycode == 65453) && e->prof > 1)
		e->prof--;
	else if (keycode == 47 || keycode == 46)
	{
		e->zoom += 0.05;
	}
	else if (keycode == 43 || keycode == 44)
	{
		e->zoom -= 0.05;
	}
	else if (keycode == 65436 || keycode == 83)
		e->color = 0x228B22;
	else if (keycode == 65433 || keycode == 84)
		e->color = 0xDA70D6;
	else if (keycode == 65438 || keycode == 82)
		e->color = 0xffffff;
	else if (keycode == 65435 || keycode == 85)
		e->color = 0x5F9EA0;
}

void		treat_keycode(int keycode, t_env *e)
{
	ft_putnbrendl(keycode);
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("goodbye");
		exit(0);
	}
	ft_bzero(e->data, e->sl * WINY);
	if (keycode == 124 || keycode == 65363)
		e->x1 += 0.01;
	else if (keycode == 125 || keycode == 65364)
	{
		if (ft_strcmp("julia", e->proj) == 0)
			e->y1 += 0.01;
		else
			e->x2 += 0.01;
	}
	else if (keycode == 126 || keycode == 65362)
	{
		if (ft_strcmp("julia", e->proj) == 0)
			e->y1 -= 0.01;
		else
			e->x2 -= 0.01;
	}
	else
		treat_keycode_2(keycode, e);
}

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	navigante(e);
	return (0);
}
