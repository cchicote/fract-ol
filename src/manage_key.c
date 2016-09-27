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
	if (keycode == 69 || keycode == 65451)
		e->prof++;
	else if ((keycode == 78 || keycode == 65453) && e->prof > 1)
		e->prof--;
	else if (keycode == 47 || keycode == 46)
	{
		e->zoom *= 1.5;
		// printf("e->zoom : %f\n", e->zoom);
	}
	else if (keycode == 43 || keycode == 44)
	{
		e->zoom /= 1.5;
		// printf("e->zoom : %f\n", e->zoom);
	}
	else if (keycode == 8 || keycode == 99)
	{
		if (e->mouse_activate == 0)
			e->mouse_activate = 1;
		else
			e->mouse_activate = 0;
	}
	else if ((keycode == 15 || keycode == 114) && e->mouse_activate == 1)
	{
		e->mouse_param_x = 0;
		e->mouse_param_y = 0;
	}
	else if (keycode == 65436 || keycode == 83) // RED
	{
		e->color_begin = 0x000000;
		e->color_end = 0xCD0000;
		e->color_start = 0x000000;
	}
	else if (keycode == 65433 || keycode == 84) // GREEN
	{
		e->color_begin = 0x000000;
		e->color_end = 0x00CD00;
		e->color_start = 0x000000;
	}
	else if (keycode == 65435 || keycode == 85) // BLUE
	{
		e->color_begin = 0x000000;
		e->color_end = 0x0000CD;
		e->color_start = 0x000000;
	}
	else if (keycode == 65438 || keycode == 82) // RESET
	{
		e->color_begin = 0x800080;
		e->color_end = 0xFA8072;
		e->color_start = 0x000000;
	}
	else if (keycode == 65430 || keycode == 65) // WHITE
	{
		e->color_begin = 0x000000;
		e->color_end = 0x0F0F0F;
		e->color_start = 0x000000;
	}
	else if (keycode == 65430 || keycode == 86) // PSY1
	{
		e->color_begin = 0xAF0EFB;
		e->color_end = 0xBFE0FA;
		e->color_start = 0x000000;
	}
	else if (keycode == 87)
	{
		e->color_begin = 0xabcdef;
		e->color_end = 0xfedcba;
		e->color_start = 0x000000;
	}
	else if (keycode == 88)
	{
		e->color_begin = 0xFF6347;
		e->color_end = 0x00CED1;
		e->color_start = 0x000000;
	}
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
		e->pos_x += 0.01;
	else if (keycode == 125 || keycode == 65364)
		e->pos_y += 0.01;
	else if (keycode == 126 || keycode == 65362)
		e->pos_y -= 0.01;
	else if (keycode == 123 || keycode == 65361)
		e->pos_x -= 0.01;
	else
		treat_keycode_2(keycode, e);
}

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	navigante(e);
	return (0);
}
