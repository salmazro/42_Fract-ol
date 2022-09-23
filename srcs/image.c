/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:54:02 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/23 16:45:10 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	var_init(t_mix *mix)
{
	mix->max_iteration = 10;
	mix->color_change = 0xFFD700;
	mix->cor.a_zoom = 1;
	mix->cor.mo_x = 0.01;
	mix->cor.mo_y = 0.01;
}

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_image(t_mix *mix)
{
	int	iteration;

	mix->cor.i = 1;
	iteration = 0;
	while (mix->cor.i < W)
	{
		mix->cor.j = 0;
		while (mix->cor.j < H)
		{
			iteration = fractal(mix);
			if (iteration == mix->max_iteration)
				my_mlx_put_pixel(&mix->data, mix->cor.i, mix->cor.j, 0);
			else
				my_mlx_put_pixel(&mix->data, mix->cor.i, mix->cor.j,
					mix->color_change * iteration / 100);
			mix->cor.j++;
		}
		mix->cor.i++;
	}
}

int	ft_all_hooks(int keycode, t_mix *mix)
{
	ft_hook(keycode, mix);
	itera_color(keycode, mix);
	ft_zoom(keycode, mix);
	return (0);
}

int	loop_hook(t_mix *mix)
{
	draw_image(mix);
	mlx_put_image_to_window(mix->mlx, mix->win, mix->data.img, 0, 0);
	return (0);
}
