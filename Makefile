# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleland <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:35:43 by oleland           #+#    #+#              #
#    Updated: 2019/07/23 12:31:50 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = bsq

CFILES = $(wildcard *.c)

HFILES =

OFILES = $(CFILES:.c=.o)

all: $(CFILES) $(NAME)
$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
