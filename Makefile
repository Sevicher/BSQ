# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleland <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:35:43 by oleland           #+#    #+#              #
#    Updated: 2019/07/23 13:30:20 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(HFILES)

NAME = bsq

CFILES = $(wildcard srcs/*.c)

HFILES = includes/

OFILES = $(CFILES:.c=.o)

all: $(CFILES) $(NAME)
$(NAME): $(OFILES)
	$(CC) $(CFLAGS)	-o $@ $^

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
