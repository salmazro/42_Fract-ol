/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:19:56 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/16 20:09:28 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 720
# define H 720

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cor
{
	double		x;
	double		y;
	int			i;
	int			j;
	double		a_zoom;
	double		mo_x;
	double		mo_y;
}				t_cor;

typedef struct s_mix
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_cor		cor;
	double		jul_x;
	double		jul_y;
	int			fractal;
	int			frac_color;
	int			max_iteration;
	int			color_change;
}			t_mix;

int		loop_hook(t_mix *mix);

int		fractal(t_mix *mix);

void	ft_parser(int ac, char **av, t_mix *mix);

void	ft_error(char *error);

size_t	ft_strlen(const char *str);

void	check_input(t_mix *mix, int ac, char **av);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	my_mlx_put_pixel(t_data *data, int x, int y, int color);

void	itera_color(int keycode, t_mix *mix);

int		ft_hook(int keycode, t_mix *mix);

void	var_init(t_mix *mix);

int		ft_escape(t_mix *mix);

int		shifter(int color, int mod);

int		zoom(int keycode, int x, int y, t_mix *mix);

void	ft_zoom(int keycode, t_mix *mix);

int		ft_all_hooks(int keycode, t_mix *mix);

int		jul(t_mix *mix);

int		mand(t_mix *mix);

int		mouse(int keycode, int x, int y, t_mix *mix);

int		is_double(char *n);

int		ft_intlen(char *number);

int		ft_power(int nb, int power);

int		ft_atoi(const char *str);

char	*ft_strchr(const char *s, int c);

double	ft_atod_fractol(char *str);

#endif
