/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:22:40 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 18:45:33 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_change_dosk(char **table, int size, t_slist *list)
{
	int i;

	i = -1;
	while (++i < size)
	{
		table[i][size] = '\0';
		table[i][size - 1] = '.';
	}
	i = -1;
	while (++i < size)
		table[size - 1][i] = '.';
	table[size][0] = '\0';
	while (list)
	{
		list->x = 0;
		list->y = 0;
		list = list->next;
	}
}

static void	ft_tetr_put(char **table, t_slist *list, int x1, int y1)
{
	int		x;
	int		y;
	char	**str;

	str = list->tetr;
	y = -1;
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
		{
			if (str[y][x] == '#')
				table[y + y1][x + x1] = 'A' + list->i - 1;
		}
	}
}

static int	ft_tetr_cheak(char **table, t_slist *list, int size)
{
	int		x;
	int		y;
	char	**str;
	int		x1;
	int		y1;

	(TETR);
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
		{
			if (str[y][x] == '#')
			{
				if (list->height > size - y1)
					return (2);
				if (list->width > size - x1)
					return (0);
				if (table[y + y1][x + x1] != '.')
					return (-1);
			}
		}
	}
	return (1);
}

static int	ft_recursiv(char **table, t_slist *list, int size)
{
	int i;

	i = ft_tetr_cheak(table, list, size);
	while (i != 1)
	{
		if (i == -1)
		{
			list->x = (list->x) + 1;
			i = ft_tetr_cheak(table, list, size);
		}
		if (i == 0)
		{
			list->x = 0;
			(list->y) = (list->y) + 1;
			i = ft_tetr_cheak(table, list, size);
		}
		if (i == 2)
			return (-1);
	}
	ft_tetr_put(table, list, list->x, list->y);
	return (1);
}

int			fillit(char **table, t_slist *root, t_slist *list, int size)
{
	while (list)
	{
		if (ft_recursiv(table, list, size) == 1)
			list = list->next;
		else
		{
			if (list == root)
				ft_change_dosk(table, ++size, list);
			else
			{
				list = ft_find_list(root, list);
				ft_back_tetr(list, table, size);
			}
		}
	}
	return (size);
}
