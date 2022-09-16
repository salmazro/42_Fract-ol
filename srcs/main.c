/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:20:46 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/14 22:20:47 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	fractal(t_mix *mix)
{
	if (mix->fractal == 1)
		return (mand(mix));
	else if (mix->fractal == 2)
		return (jul(mix));
	return (0);
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

int	loop_hook(t_mix *mix)
{
	draw_image(mix);
	mlx_put_image_to_window(mix->mlx, mix->win, mix->data.img, 0, 0);
	return (0);
}

void	check_input(t_mix *mix, int ac, char **av)
{
	mix->fractal = 2;
	if (ac != 4)
		ft_error("invalid amount of arguments");
	mix->jul_x = ft_atoi_fractol(av[2]);
	mix->jul_y = ft_atoi_fractol(av[3]);
}

void	helper(int ac, char **av, t_mix *mix)
{
	if (ac < 2 || ac > 4)
		ft_error("Wrong number of arguments\n");
	if (!ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
		mix->fractal = 1;
	else if (!ft_strncmp(av[1], "julie", ft_strlen("julie")))
		check_input(mix, ac, av);
	else
		ft_error("two options\nmandelbrot\njulie (optional) (optional)\n");
}

void	my_mlx_handler(t_mix mix)
{
	mix.mlx = mlx_init();
	mix.win = mlx_new_window(mix.mlx, W, H, "Hello world!");
	mix.data.img = mlx_new_image(mix.mlx, W, H);
	mix.data.addr = mlx_get_data_addr(mix.data.img,
			&mix.data.bits_per_pixel, &mix.data.line_length,
			&mix.data.endian);
	var_init(&mix);
	mlx_hook(mix.win, 2, 1L << 0, ft_hook, &mix);
	mlx_hook(mix.win, 17, 1L << 5, clox, &mix);
	mlx_mouse_hook(mix.win, mouse, &mix);
	mlx_loop_hook(mix.mlx, loop_hook, &mix);
	mlx_loop(mix.mlx);
}

int	main(int ac, char **av)
{
	t_mix	mix;

	helper(ac, av, &mix);
	my_mlx_handler(mix);
}
