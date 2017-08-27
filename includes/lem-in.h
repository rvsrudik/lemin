
#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include "get_next_line.h"


char 	**ft_read_input();
void	ft_error(void);
void 	ft_check_input(char **input);
int		count_str_array(char **input);
int ft_find_number_of_ants(char **input);
int ft_is_comment(char *line);
int ft_is_number_of_ants(char *line);
char **ft_find_rooms(char **input);
int ft_is_start(char * line);
int ft_is_end(char * line);
int ft_is_rooms(char *line);
int ft_is_links(char *line);
void ft_free_str_array(char **line);
char **ft_find_links(char **input);
int ft_is_number(char *num);
void ft_free_str_array(char **line);


//int			ft_isdigit(int c);
//char		**ft_strsplit(char const *s, char c)
#endif