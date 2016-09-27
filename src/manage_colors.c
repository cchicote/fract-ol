/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:06:18 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/27 11:06:29 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		manage_colors(int keycode, t_env *e)
{
	if (keycode == 65436 || keycode == 83) // RED
	{
		e->color_begin = 0x000000;
		e->color_end = 0xCD0000;
	}
	else if (keycode == 65433 || keycode == 84) // GREEN
	{
		e->color_begin = 0x000000;
		e->color_end = 0x00CD00;
	}
	else if (keycode == 65435 || keycode == 85) // BLUE
	{
		e->color_begin = 0x000000;
		e->color_end = 0x0000CD;
	}
	else if (keycode == 65438 || keycode == 82) // RESET
	{
		e->color_begin = 0x800080;
		e->color_end = 0xFA8072;
	}
	else
		manage_colors2(keycode, e);
}

void		manage_colors2(int keycode, t_env *e)
{
	if (keycode == 65430 || keycode == 65) // WHITE
	{
		e->color_begin = 0x000000;
		e->color_end = 0x0F0F0F;
	}
	else if (keycode == 65430 || keycode == 86) // PSY1
	{
		e->color_begin = 0xAF0EFB;
		e->color_end = 0xBFE0FA;
	}
	else if (keycode == 87) // PSY2
	{
		e->color_begin = 0xabcdef;
		e->color_end = 0xfedcba;
	}
	else if (keycode == 88) // PSY3
	{
		e->color_begin = 0xFF6347;
		e->color_end = 0x00CED1;
	}
	else if (keycode == 89)
		randomize(e);
}

void		randomize(t_env *e)
{
	e->color_begin = rand();
	e->color_end = rand();
}