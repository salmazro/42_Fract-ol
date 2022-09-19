/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julie_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:54:06 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/16 20:06:45 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_double(char *n)
{
	char	*dot;

	dot = ft_strchr(n, '.');
	if (!dot)
		return (1);
	if ((dot == n && !dot[1]) || (dot != n && !dot[1]))
		return (1);
	if (ft_strchr(dot + 1, '.'))
		return (1);
	while (*n)
	{
		if (!(*n > '0' || *n < '9' || *n == '.' || *n == '-' || *n == '+'))
			return (1);
		n++;
	}
	return (0);
}

int	ft_intlen(char *number)
{
	int	len;

	len = 0;
	while (*number)
	{
		number++;
		len++;
	}
	return (len);
}

int	ft_power(int nb, int power)
{
	int	p;
	int	nbr;

	p = 1;
	nbr = nb;
	if (power < 0)
		return (1);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		p *= nbr;
		power--;
	}
	return (p);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	i;

	number = 0;
	if (*str)
	{
		while (*str >= '0' && *str <= '9' && *str)
		{
			i = *str++ - '0';
			number = (number * 10) + i;
		}
	}
	return (number);
}

double	ft_atod_fractol(char *str)
{
	double	value;
	char	*mantissa;
	int		sign;
	int		len;

	sign = 1;
	if (!str || is_double(str))
	{
		exit(1);
	}
	if (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			sign *= -1;
	mantissa = ft_strchr(str, '.');
	*(mantissa++) = '\0';
	len = ft_intlen(mantissa);
	value = (ft_atoi(mantissa) / (double) ft_power(10, len)) + ft_atoi(str);
	return (sign * value);
}
