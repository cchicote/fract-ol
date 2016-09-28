/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 15:09:13 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 15:09:23 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		treat_mouse(int x, int y, t_env *e)
{
	if (x <= WINX && y <= WINY && x >= 0 && y >= 0)
	{
		if (e->rdm == 1)
		{
			randomize(e);
			ft_bzero(e->data, e->sl * WINY);
			navigante(e);
		}
		if (e->mouse_activate == 0)
		{
			e->mouse_param_x = (WINX / 2 - x) / 200;
			e->mouse_param_y = (WINY / 2 - y) / 200;
			ft_bzero(e->data, e->sl * WINY);
			navigante(e);
		}
	}
}

void		manage_button(int button, int x, int y, t_env *e)
{
	if (x <= WINX && y <= WINY && x >= 0 && y >= 0)
	{
		if (button == 4)
		{
			e->pos_x -= ((double)WINX / 2 - x) / e->zoom / 2;
			e->pos_y -= ((double)WINY / 2 - y) / e->zoom / 2;
			e->zoom *= 1.5;
		}
		else if (button == 5)
			e->zoom /= 1.5;
		if (e->rdm == 1 && e->mouse_activate == 1)
			randomize(e);
		ft_bzero(e->data, e->sl * WINY);
		navigante(e);
	}
}

int			manage_mouse(int x, int y, void *e)
{
	treat_mouse(x, y, e);
	return (0);
}

int			mouse_button(int button, int x, int y, void *e)
{
	manage_button(button, x, y, e);
	return (0);
}
