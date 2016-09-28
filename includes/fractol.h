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
# include "../minilibxLinux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define WINX 400.0
# define WINY 400.0


typedef struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			color_start;
	int			color_begin;
	int			color_end;
	int			fract;
	int			mouse_activate;
	int			rdm;
	char		*proj;
	double		c_r;
	double		c_i;
	double 		z_r;
	double		z_i;
	double		pos_x;
	double		pos_y;
	double		prof;
	double		zoom;
	double		centerx;
	double		centery;
	double		zoom_x;
	double		zoom_y;
	double		mouse_param_x;
	double		mouse_param_y;
	double		echelle;
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

int				manage_key(int keycode, void *e);
void			reset_param(t_env *e);
void			treat_keycode(int keycode, t_env *e);
void			treat_keycode_2(int keycode, t_env *e);

/*
** MANAGE_COLORS.C
*/

int				choose_color(t_env *e, int i);
void			manage_colors(int keycode, t_env *e);
void			manage_colors2(int keycode, t_env *e);
void			randomize(t_env *e);

/*
** MANAGE_MOUSE.C
*/

int			manage_mouse(int x, int y, void *e);
int			mouse_button(int button, int x, int y, void *e);
void		treat_mouse(int x, int y, t_env *e);
void		manage_button(int button, int x, int y, t_env *e);

/*
** DRAW.C
*/

void			my_pixel_put(t_env *e, int x, int y, int color);
void			navigante(t_env *e);
void			mandelbrot(t_env *e, double x, double y);
void			julia(t_env *e, double x, double y);
void			burningship(t_env *e, double x, double y);


#endif