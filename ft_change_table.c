/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:49:09 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 15:58:44 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_change_table(char ***table, int size)
{
	int		i;
	int		m;
	char	**str;

	i = -1;
	i = -1;
	str = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		str[i] = (char *)malloc(sizeof(char) * (size + 1));
		m = -1;
		while (++m < size)
			str[i][m] = '.';
		str[i][size] = '\0';
	}
	str[size] = NULL;
	*table = str;
}
