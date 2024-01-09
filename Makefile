# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/01/09 14:33:55 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./MLX42/build
FTPRINTF	:= ./printf
GNL			:= ./get_next_line

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(GNL)/gnl.a $(FTPRINTF)/libftprintf.a $(LIBMLX)/libmlx42.a  -lglfw -lm 
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

gnl:
	@$(MAKE) -C $(GNL)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) ftprintf gnl 
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) 

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx