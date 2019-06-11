# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 09:55:46 by jcartwri          #+#    #+#              #
#    Updated: 2019/01/17 17:05:07 by jcartwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LNAME = libft
SRCS = fillit.c ft_change_table.c ft_height_width.c ft_change.c ft_finish_table.c valid.c ft_tetr_list.c freelist.c
LINCLUDES = libft
OBJ = *.o
NORMA = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@make -C libft fclean && make -C libft
		@gcc -I $(LINCLUDES)  $(NORMA) -c $(SRCS)
		@gcc -L libft -lft -I $(LNAME) $(NORMA) -o $(NAME) main.c $(OBJ)

clean:
		@rm -f $(OBJ)
		@rm -f libft/$(OBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -f libft/libft.a

re: fclean all
