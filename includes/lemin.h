/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:21:35 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 18:35:40 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>
# include "get_next_line.h"

char		**ft_read_input();
void		ft_error(void);
void		ft_check_input(char **input);
int			ft_determ_number_of_rooms(char **input);
int			count_str_array(char **input);
int			ft_find_number_of_ants(char **input);
int			ft_is_comment(char *line);
int			ft_is_number_of_ants(char *line);
char		**ft_find_rooms(char **input);
int			ft_is_start(char *line, char *next_line);
int			ft_is_end(char *line, char *next_line);
int			ft_is_rooms(char *line);
int			ft_is_links(char *line);
void		ft_free_str_array(char **line);
char		**ft_find_links(char **input);
int			ft_is_number(char *num);
void		ft_free_str_array(char **line);
int			**ft_create_matrix(char **rooms, char **links);
int			ft_count_rooms(char **rooms);
void		ft_print_matrix(int **matrix, int numb_of_rooms);
void		ft_find_way(int num_of_ants, char **rooms, char **links,
			int **matrix, char **print_rooms);
void		ft_print_way(char **shortest_way_by_names,
			int num_of_ants, int way_len);
int			*ft_new_int_array(int size, int num_of_ants, int way_len);
int			**ft_fill_way_info(int **way_info, char **rooms, int **matrix);
void		ft_is_no_way(int **way_info, char **rooms);
void		ft_free_matrix(int **matrix, int x);
int			**ft_find_room_links(int **way_info, int **matrix, char **rooms);
void		ft_is_start_end_exist(char **input);
void		ft_is_links_exist(char **input);
void		ft_is_same_rooms(char **rooms);
int			ft_is_rooms(char *line);

#endif
