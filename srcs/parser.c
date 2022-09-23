/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:53:33 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/22 17:50:31 by salmazro         ###   ########.fr       */
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

void	ft_parser(int ac, char **av, t_mix *mix)
{
	if (ac != 2 && ac != 4)
		ft_error("Wrong number of arguments\n");
	if (!ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
		mix->fractal = 1;
	else if (!ft_strncmp(av[1], "julia", ft_strlen("julia")))
		check_input(mix, ac, av);
	else
		ft_error("Two options:\nmandelbrot\njulie (cord - x) (cord - y)\n");
}

void	check_input(t_mix *mix, int ac, char **av)
{
	mix->fractal = 2;
	if (ac != 4)
		ft_error("invalid amount of arguments");
	mix->jul_x = ft_atod_fractol(av[2]);
	mix->jul_y = ft_atod_fractol(av[3]);
}
