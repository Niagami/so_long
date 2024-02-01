# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/01/23 16:59:14 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX		:= ./MLX42
FTPRINTF	:= ./printf
GNL			:= ./get_next_line

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(GNL)/gnl.a $(FTPRINTF)/libftprintf.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

gnl:
	@$(MAKE) -C $(GNL)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) ftprintf gnl 
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) 

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	


re: clean all

.PHONY: all, clean, fclean, re, libmlx
