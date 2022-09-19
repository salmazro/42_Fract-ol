/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:53:58 by salmazro          #+#    #+#             */
/*   Updated: 2022/09/16 20:16:08 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (!c)
		return ((char *) &s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if ((n - 1) != i)
		return (1);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_error(char *error)
{
	while (*error)
		write(1, error++, 1);
	exit(1);
}
