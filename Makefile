# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:19:32 by vrudenko          #+#    #+#              #
#    Updated: 2016/11/29 18:04:45 by vrudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
        help_func/ft_strchr.c \
        help_func/ft_strdel.c \
        help_func/ft_strdup.c \
        help_func/ft_strjoin.c \
        help_func/ft_strnew.c \
        help_func/ft_strlen.c \
        help_func/get_next_line.c \
        help_func/ft_strcpy.c \
        ft_read_input.c \
        ft_error.c \
        help_func/ft_putstr.c \
        help_func/ft_putchar.c \
        ft_check_input.c \
        help_func/ft_isdigit.c \
        help_func/ft_atoi.c \
        help_func/ft_strsplit.c \
        help_func/ft_strncpy.c \
        help_func/ft_strcmp.c \
        help_func/ft_countchars.c \
        help_func/ft_strtrim.c \
        ft_find_number_of_ants.c \
        ft_find_rooms.c \


OBJ = main.o \
        help_func/ft_strchr.o \
        help_func/ft_strdel.o \
        help_func/ft_strdup.o \
        help_func/ft_strjoin.o \
        help_func/ft_strnew.o \
        help_func/ft_strlen.o \
        help_func/get_next_line.o \
        help_func/ft_strcpy.o \
        ft_read_input.o \
        ft_error.o \
        help_func/ft_putstr.o \
        help_func/ft_putchar.o \
        ft_check_input.o \
        help_func/ft_isdigit.o \
        help_func/ft_atoi.o \
        help_func/ft_strsplit.o \
        help_func/ft_strncpy.o \
        help_func/ft_strcmp.o \
        help_func/ft_countchars.o \
        help_func/ft_strtrim.o \
        ft_find_number_of_ants.o \
        ft_find_rooms.o \

CC = gcc
INC = -Iincludes
CFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all