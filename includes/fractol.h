/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 10:33:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/12 10:33:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/X.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define WINX 1000.0
# define WINY 1000.0


typedef struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	char		*proj;
}				t_env;

/*
** MAIN.C
*/

int				main(int argc, char **argv);
int				env_init(t_env *new, char *argv);
int				read_arg(t_env *e, char *argv);

/*
** MANAGE_KEY.C
*/

void			treat_keycode(int keycode, t_env *e);
int				manage_key(int keycode, void *e);

/*
** DRAW.C
*/

void			my_pixel_put(t_env *e, int x, int y, int color);
void			mandelbrot(t_env *e);
void			mandelgo(t_env *e, double x, double y);



#endif