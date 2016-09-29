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

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	navigante(e);
	return (0);
}

void		reset_param(t_env *e)
{
	e->mouse_param_x = 0;
	e->mouse_param_y = 0;
	e->pos_x = 0;
	e->pos_y = 0;
	e->zoom = WINX / 4;
	e->prof = 10;
}

void		move_fract_key(t_env *e, int keycode)
{
	free(e->proj);
	if (keycode == 49 || keycode == 18)
		e->proj = ft_strdup("mandelbrot");
	else if (keycode == 50 || keycode == 19)
		e->proj = ft_strdup("julia");
	else if (keycode == 51 || keycode == 20)
		e->proj = ft_strdup("burningship");
	reset_param(e);
	navigante(e);
}

void		treat_keycode(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("goodbye");
		exit(0);
	}
	ft_bzero(e->data, e->sl * WINY);
	if (keycode == 124 || keycode == 65363)
		e->pos_x += 1 / e->zoom * 2;
	else if (keycode == 125 || keycode == 65364)
		e->pos_y += 1 / e->zoom * 2;
	else if (keycode == 126 || keycode == 65362)
		e->pos_y -= 1 / e->zoom * 2;
	else if (keycode == 123 || keycode == 65361)
		e->pos_x -= 1 / e->zoom * 2;
	else if (keycode == 1 || keycode == 115)
	{
		if (e->rdm == 0)
			e->rdm = 1;
		else
			e->rdm = 0;
	}
	else
		treat_keycode_2(keycode, e);
}

void		treat_keycode_2(int keycode, t_env *e)
{
	if (keycode == 69 || keycode == 65451)
		e->prof++;
	else if ((keycode == 78 || keycode == 65453) && e->prof > 1)
		e->prof--;
	else if (keycode == 47 || keycode == 46)
		e->zoom *= 1.5;
	else if (keycode == 43 || keycode == 44)
		e->zoom /= 1.5;
	else if (keycode == 8 || keycode == 99)
	{
		if (e->mouse_activate == 0)
			e->mouse_activate = 1;
		else
			e->mouse_activate = 0;
	}
	else if ((keycode == 15 || keycode == 114) && e->mouse_activate == 1)
		reset_param(e);
	else if ((keycode >= 82 && keycode <= 89) || keycode == 65)
		manage_colors(keycode, e);
	else if (keycode == 49 || keycode == 50 || keycode == 51 ||
		keycode == 18 || keycode == 19 || keycode == 20)
		move_fract_key(e, keycode);
}
