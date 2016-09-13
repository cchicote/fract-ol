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
	new->x1 = -2.1;
	new->y1 = 0.6;
	new->x2 = -1.2;
	new->y2 = 1.5;
	new->prof = 10;
	new->zoom = 6;
	new->centerx = WINX;
	new->centery = WINY;
	return (0);
}

int			read_arg(t_env *e, char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
		argv[i] = ft_tolower(argv[i]);
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "mandelbrot") == 0)
		e->proj = ft_strdup(argv);
	else
	{
		ft_putstr(argv);
		ft_putendl(": invalid parameter");
		ft_putendl("Available parameters:");
		ft_putendl("-julia");
		ft_putendl("-mandelbrot");
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		ft_putendl("usage: './fractol parameter'");
		return (0);
	}
	if (env_init(&e, argv[1]) == -1)
		return (0);
	mandelbrot(&e);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
