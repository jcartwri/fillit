/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:22:09 by jcartwri          #+#    #+#             */
/*   Updated: 2019/01/17 17:31:41 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define CHANGE_1 {x1 = 30; y1 = 30; y = -1;}
# define HE_WI_1 {y1 = -1; y2 = -1; y = -1;}
# define HE_WI_2 {list->height = y2 - y1 + 1; list->width = x2 - x1 + 1;}
# define MAIN1 {ft_putendl("usage source_file"); return (0);}
# define MAIN2 {ft_putendl("error"); return (0);}
# define VALID1 {a = 0; col = 0; y = -1;}
# define VAL(a, col) (((a == 6) || (a == 8)) && (col == 4)) ? 1 : -1
# define VA {b = ft_strsub(buf, 0, 20); tetr = ft_strsplit(b, '\n'); y = -1;}
# define VA1 {list->tetr = tetr; return (1);}
# define VALID2(y, i) (y != 20 || y == 0 || i > 26) ? (-1) : 1
# define TETR {x1 = list->x; y1 = list->y; str = list->tetr; y = -1;}
# define TETR_LIST {list->x = 0; list->y = 0; list = list->next;}
# define MAI1 {table = NULL; dosk = NULL; return (1);}
# define MAI2 {ft_finish_table(table, dosk, fd); freelist(&root); fd = -1;}
# define MA {ft_height_width(root); list = root; ft_change(root); list = root;}

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct		s_slist
{
	int				height;
	int				width;
	int				i;
	int				x;
	int				y;
	char			**tetr;
	struct s_slist	*next;
}					t_slist;
int					main(int argc, char **argv);
void				ft_height_width(t_slist *root);
void				ft_change(t_slist	*list);
void				ft_change_dosk(char	**table, int size, t_slist *list);
int					fillit(char **table, t_slist *root, t_slist *list,
		int size);
void				ft_change_table(char	***table, int size);
void				ft_finish_table(char **table, char **dosk, int size);
void				ft_body_he_wi(char **str, t_slist *list,
		int x1, int x2);
int					ft_valid(int fd, t_slist **root);
void				ft_back_tetr(t_slist *list, char **table, int size);
t_slist				*ft_find_list(t_slist *root, t_slist *list);
void				freelist(t_slist **root);

#endif
