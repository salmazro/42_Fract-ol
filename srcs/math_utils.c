/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:53:41 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/16 18:09:47 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	jul(t_mix *mix)
{
	t_cor		coor;
	t_cor		coor2;
	int			iteration ;
	double		xtemp;

	coor.x = (1.70 * (mix->cor.i - W / 2)
			/ (0.365 * W * mix->cor.a_zoom) + mix->cor.mo_x);
	coor.y = (mix->cor.j - H / 2) / (0.25 * H
			* mix->cor.a_zoom) + mix->cor.mo_y;
	coor2.x = mix->jul_x;
	coor2.y = mix->jul_y;
	iteration = 0;
	while (coor.x * coor.x + coor.y * coor.y
		<= 2 * 2 && iteration < mix->max_iteration)
	{
		xtemp = coor.x * coor.x
			- coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x * coor.y - coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}

int	mand(t_mix *mix)
{
	t_cor	coor;
	t_cor	coor2;
	int		iteration;
	double	xtemp;

	coor2.x = (1.70 * (mix->cor.i - W / 2)
			/ (0.365 * W * mix->cor.a_zoom) + mix->cor.mo_x);
	coor2.y = (mix->cor.j - H / 2)
		/ (0.25 * H * mix->cor.a_zoom) + mix->cor.mo_y;
	coor.x = 0.0;
	coor.y = 0.0;
	iteration = 0;
	while (coor.x * coor.x + coor.y
		* coor.y <= 2 * 2 && iteration < mix->max_iteration)
	{
		xtemp = coor.x * coor.x - coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x * coor.y + coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}
