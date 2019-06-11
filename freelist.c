/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:40:51 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/18 12:41:11 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freelist(t_slist **root)
{
	t_slist	*next;
	t_slist	*list;

	next = (*root)->next;
	free((*root)->tetr);
	free(*root);
	*root = NULL;
	while (next != NULL)
	{
		list = next;
		next = list->next;
		free(list->tetr);
		free(list);
		list = NULL;
	}
}
