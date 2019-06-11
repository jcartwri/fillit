/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:00:57 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 17:46:32 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_slist	*ft_new_struct(t_slist **root, int i)
{
	t_slist	*a_list;
	t_slist	*list;

	a_list = *root;
	if (*root == NULL)
	{
		if (!(*root = (t_slist *)malloc(sizeof(t_slist))))
			return (NULL);
		(*root)->next = NULL;
		(*root)->i = i;
		(*root)->x = 0;
		(*root)->y = 0;
		return (*root);
	}
	while (a_list->next)
		a_list = a_list->next;
	if (!(list = (t_slist *)malloc(sizeof(t_slist))))
		return (NULL);
	list->next = NULL;
	a_list->next = list;
	list->i = i;
	list->x = 0;
	list->y = 0;
	return (list);
}

static int		ft_valid_tetrimino(char **tetr)
{
	int			a;
	int			x;
	int			y;
	int			col;

	(VALID1);
	while (tetr[++y])
	{
		x = -1;
		while (tetr[y][++x])
		{
			if (tetr[y][x] == '#')
			{
				col++;
				if (tetr[y][x + 1] == '#')
					a = a + 2;
				if (y != 3)
				{
					if (tetr[y + 1][x] == '#')
						a = a + 2;
				}
			}
		}
	}
	return (VAL(a, col));
}

static int		ft_read(t_slist **root, char *buf, int y, int i)
{
	char		*b;
	t_slist		*list;
	char		**tetr;
	int			x;

	(VA);
	ft_strdel(&b);
	while (tetr[++y])
	{
		if (ft_strlen(tetr[y]) != 4)
			return (-1);
		x = -1;
		while (tetr[y][++x])
		{
			if (tetr[y][x] != '.' && tetr[y][x] != '#')
				return (-1);
		}
	}
	if (y != 4)
		return (-1);
	if (ft_valid_tetrimino(tetr) == -1)
		return (-1);
	if (!(list = ft_new_struct(root, i)))
		return (-1);
	(VA1);
}

int				ft_valid(int fd, t_slist **root)
{
	char		buf[22];
	int			i;
	int			y;
	int			res;

	*root = NULL;
	i = 0;
	y = 0;
	while ((res = read(fd, buf, 21)) > 0)
	{
		if (res < 20)
			return (-1);
		if (res == 21)
		{
			if (buf[20] != '\n')
				return (-1);
		}
		i++;
		if (ft_strchr(buf, '\n') == NULL)
			return (-1);
		if (ft_read(root, buf, y, i) == -1)
			return (-1);
		y = res;
	}
	return (VALID2(y, i));
}
