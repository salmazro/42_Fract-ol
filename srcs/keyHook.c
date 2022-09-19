/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:53:53 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/16 17:54:21 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	itera_color(int keycode, t_mix *mix)
{
	if (keycode == 34)
		mix->max_iteration += 5;
	if (keycode == 31)
		mix->max_iteration -= 5;
	if (keycode == 18)
		mix->color_change = 0x880808 * rand();
}

void	ft_zoom(int keycode, t_mix *mix)
{
	if (keycode == 24)
		mix->cor.a_zoom *= 2;
	if (keycode == 27)
		mix->cor.a_zoom /= 2;
}

int	ft_escape(t_mix *mix)
{
	mlx_destroy_window(mix->mlx, mix->win);
	mlx_destroy_image(mix->mlx, mix->data.img);
	exit(0);
}

int	ft_hook(int keycode, t_mix *mix)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mix->mlx, mix->win);
		mlx_destroy_image(mix->mlx, mix->data.img);
		exit(0);
	}
	if (keycode == 124)
		mix->cor.mo_x += 0.05 / mix->cor.a_zoom;
	else if (keycode == 123)
		mix->cor.mo_x -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 126)
		mix->cor.mo_y -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 125)
		mix->cor.mo_y += 0.05 / mix->cor.a_zoom;
	return (0);
}

int	ft_all_hooks(int keycode, t_mix *mix)
{
	ft_hook(keycode, mix);
	itera_color(keycode, mix);
	ft_zoom(keycode, mix);
	return (0);
}

int	mouse(int keycode, int x, int y, t_mix *mix)
{
	(void)x;
	(void)y;
	if (keycode == 5)
		mix->cor.a_zoom *= 2;
	else if (keycode == 4)
		mix->cor.a_zoom /= 2;
	return (0);
}
