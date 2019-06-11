/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetr_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:30:20 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 18:30:48 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_slist	*ft_find_list(t_slist *root, t_slist *list)
{
	if (root->next == list)
		return (root);
	while (root->next != list)
		root = root->next;
	return (root);
}

void	ft_back_tetr(t_slist *list, char **table, int size)
{
	int x;
	int y;

	y = -1;
	while (table[++y])
	{
		x = -1;
		while (table[y][++x])
		{
			if (table[y][x] == (list->i + 'A' - 1))
				table[y][x] = '.';
		}
	}
	if (size == (list->x + 1))
	{
		list->x = 0;
		list->y = list->y + 1;
	}
	else
		list->x = list->x + 1;
	list = list->next;
	while (list)
		(TETR_LIST);
}
