/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:22:27 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 16:50:32 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_point_if(int x, int *x1, int *x2)
{
	*(x1) = x;
	*(x2) = x;
}

static void	ft_point_y(int y, int *y1, int *y2)
{
	if (y < *(y1))
		*(y1) = y;
	if (y > *(y2))
		*(y2) = y;
}

static void	ft_point_x(int x, int *x1, int *x2)
{
	if (x < *(x1))
		*(x1) = x;
	if (x > *(x2))
		*(x2) = x;
}

void		ft_body_he_wi(char **str, t_slist *list, int x1, int x2)
{
	int	y1;
	int	y2;
	int	x;
	int	y;

	(HE_WI_1);
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
		{
			if (str[y][x] == '#')
			{
				if ((x1 < 0) && (x2 < 0) && (y1 < 0) && (y2 < 0))
				{
					ft_point_if(x, &x1, &x2);
					y1 = y;
					y2 = y;
				}
				ft_point_x(x, &x1, &x2);
				ft_point_y(y, &y1, &y2);
			}
		}
	}
	(HE_WI_2);
}

void		ft_height_width(t_slist *root)
{
	t_slist		*list;
	int			x1;
	int			x2;
	char		**str;

	x1 = -1;
	x2 = -1;
	list = root;
	while (list)
	{
		str = list->tetr;
		ft_body_he_wi(str, list, x1, x2);
		list = list->next;
	}
}
