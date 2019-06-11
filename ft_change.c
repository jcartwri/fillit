/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:16:26 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 16:28:02 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_find_x_y(char **str, int *x1, int *y1)
{
	int	x;
	int	y;

	y = -1;
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
		{
			if (str[y][x] == '#')
			{
				if (x < *x1)
					*x1 = x;
				if (y < *y1)
					*y1 = y;
			}
		}
	}
}

void		ft_change(t_slist *list)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	char	**str;

	while (list)
	{
		(CHANGE_1);
		str = list->tetr;
		ft_find_x_y(str, &x1, &y1);
		while (str[++y])
		{
			x = -1;
			while (str[y][++x])
			{
				if (str[y][x] == '#')
				{
					str[y][x] = '.';
					str[y - y1][x - x1] = '#';
				}
			}
		}
		list = list->next;
	}
}
