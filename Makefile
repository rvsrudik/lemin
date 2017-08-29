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
        ft_find_links.c \
        ft_is_correct_in_params.c \
        help_func/ft_is_number.c \
        help_func/ft_free_str_array.c \
        ft_create_matrix.c \
        ft_find_way.c \
        ft_print_way.c \
        help_func/ft_putnbr.c \
        ft_new_int_int_array.c \
        ft_find_way_second.c \
        is_funcs.c \


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
        ft_find_links.o \
        ft_is_correct_in_params.o \
        help_func/ft_is_number.o \
        help_func/ft_free_str_array.o \
        ft_create_matrix.o \
        ft_find_way.o \
        ft_print_way.o \
        help_func/ft_putnbr.o \
        ft_new_int_int_array.o \
        ft_find_way_second.o \
        is_funcs.o

CC = gcc
INC = -Iincludes
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all