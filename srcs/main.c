/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:53:47 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/18 20:32:27 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_handler(t_mix mix)
{
	mix.mlx = mlx_init();
	mix.win = mlx_new_window(mix.mlx, W, H, "Fract-ol!");
	mix.data.img = mlx_new_image(mix.mlx, W, H);
	mix.data.addr = mlx_get_data_addr(mix.data.img,
			&mix.data.bits_per_pixel, &mix.data.line_length,
			&mix.data.endian);
	var_init(&mix);
	mlx_hook(mix.win, 2, 1L << 0, ft_all_hooks, &mix);
	mlx_hook(mix.win, 17, 1L << 5, ft_escape, &mix);
	mlx_mouse_hook(mix.win, mouse, &mix);
	mlx_loop_hook(mix.mlx, loop_hook, &mix);
	mlx_loop(mix.mlx);
}

int	main(int ac, char **av)
{
	t_mix	mix;

	ft_parser(ac, av, &mix);
	my_mlx_handler(mix);
}
