/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:20:32 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/14 22:20:33 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	var_init(t_mix *mix)
{
	mix->max_iteration = 10;
	mix->color_change = 0xf31717;
	mix->cor.a_zoom = 1;
	mix->cor.mo_x = 0.01;
	mix->cor.mo_y = 0.01;
}
