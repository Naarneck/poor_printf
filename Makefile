# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izelensk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:17:24 by izelensk          #+#    #+#              #
#    Updated: 2017/08/07 16:21:45 by izelensk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c 	handle_types.c handle_width.c util.c handle_other_types.c util1.c util2.c identify_stuff.c
OBJS = ft_printf.o 	handle_types.o handle_width.o util.o handle_other_types.o util1.o util2.o identify_stuff.o
HEADER = ft_printf.h

JUNK = $(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch)

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -I $(HEADER) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@rm -rf $(JUNK)
	@echo "compiled"

clean:
	@rm -rf $(OBJS)
	@rm -f ft_printf.h.gch
	@echo "cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned"

re: fclean all
