/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 10:33:59 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 10:34:09 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			env_init(t_env *new, char *argv)
{
	if (read_arg(new, argv) == -1)
		return (-1);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WINX, WINY, "fractol");
	new->img = mlx_new_image(new->mlx, WINX, WINY);
	new->data = mlx_get_data_addr(new->img, &(new->bpp), &(new->sl), &(new->endian));
	new->prof = 10;
	new->zoom = 6;
	new->pos_x = 0;
	new->pos_y = 0;
	new->c_r = 0;
	new->c_i = 0;
	new->centerx = WINX;
	new->centery = WINY;
	new->mouse_activate = 0;
	new->fract = 0;
	new->color_begin = 0x800080;
	new->color_end = 0xFA8072;
	new->color_start = 0x000000;
	return (0);
}

int			read_arg(t_env *e, char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
		argv[i] = ft_tolower(argv[i]);
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "mandelbrot") == 0 || ft_strcmp(argv, "burningship") == 0)
		e->proj = ft_strdup(argv);
	else
	{
		ft_putstr(argv);
		ft_putendl(": invalid parameter");
		ft_putendl("Available parameters:");
		ft_putendl("-julia");
		ft_putendl("-mandelbrot");
		ft_putendl("-burningship");
		return (-1);
	}
	return (0);
}

void		treat_mouse(int x, int y, t_env *e)
{
	if (e->mouse_activate == 0 && x <= WINX && y <= WINY && x >= 0 && y >= 0)
	{
		e->mouse_param_x = (WINX / 2 - x) / 200;
		e->mouse_param_y = (WINY / 2 - y) / 200;
		// printf("x : %f\n", e->mouse_param_x);
		// printf("y : %f\n", e->mouse_param_y);
		ft_bzero(e->data, e->sl * WINY);
		navigante(e);
	}
}

void		manage_button(int button, int x, int y, t_env *e)
{
	if (e->mouse_activate == 0 && x <= WINX && y <= WINY && x >= 0 && y >= 0)
	{
		if (button == 4)
		{
			e->pos_x -= x / 200;
			e->pos_y -= y / 200;
			e->zoom /= 1.5;
		}
		else if (button == 5)
		{
			e->pos_x += (WINX / 2 - x) / 400;
			e->pos_y += (WINY / 2 - y) / 400;
			e->zoom *= 1.5;
		}
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

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		ft_putendl("Available parameters:");
		ft_putendl("-julia");
		ft_putendl("-mandelbrot");
		ft_putendl("-burningship");
		return (0);
	}
	if (env_init(&e, argv[1]) == -1)
		return (0);
	navigante(&e);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	mlx_hook(e.win, 4, (1 << 11), mouse_button, &e); // vers le haut
	mlx_hook(e.win, 5, (1 << 12), mouse_button, &e); // vers le bas
	mlx_hook(e.win, 6, (1L << 6), manage_mouse, &e);
	mlx_loop(e.mlx);
	return (0);
}
