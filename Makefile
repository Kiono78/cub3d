# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:05:19 by bterral           #+#    #+#              #
#    Updated: 2022/05/20 11:26:43 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

FFLAGS			= -fsanitize=address -g

NAME			= cub3d

HEADER			= include/cub3d.h srcs/parsing/parsing.h

INCLUDES_D		= ./includes

SRC				= main.c

SRC_PARSING_F	= parsing.c parsing_utils.c rgb_check.c parse_map.c \
					error.c map_consistency.c

SRC_PARSING_D	= srcs/parsing/

SRC_PARSING		= $(addprefix $(SRC_PARSING_D), $(SRC_PARSING_F))

OBJS			= $(SRC:.c=.o) $(SRC_PARSING:.c=.o)

LIBFT			= ./libft/libft.a

all: libft $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(FFLAGS) -I $(INCLUDES_D) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(FFLAGS) -c $< -o $@

libft:
	$(MAKE) -C ./libft

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean libft re