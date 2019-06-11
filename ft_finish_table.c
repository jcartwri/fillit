/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:50:26 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 15:53:40 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_finish_table(char **table, char **dosk, int size)
{
	int x;
	int y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			dosk[y][x] = table[y][x];
		}
	}
	y = -1;
	while (dosk[++y])
		ft_putendl(dosk[y]);
}
