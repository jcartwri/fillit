/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:16:38 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 17:10:20 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_slist	*root;
	t_slist	*list;
	char	**table;
	char	**dosk;

	if (argc != 2)
		(MAIN1);
	fd = open(argv[1], O_RDONLY);
	if (ft_valid(fd, &root) == -1)
		(MAIN2);
	(MA);
	ft_change_table(&table, 21);
	fd = 2;
	ft_change_dosk(table, fd, list);
	fd = fillit(table, list, list, fd);
	ft_change_table(&dosk, fd);
	(MAI2);
	while (table[++fd])
		ft_strdel(&table[fd]);
	fd = -1;
	while (dosk[++fd])
		ft_strdel(&dosk[fd]);
	(MAI1);
}
