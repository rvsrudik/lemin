
#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include "get_next_line.h"


char 	**ft_read_input();
void ft_error(void);
void ft_check_input(char **input);
int		ft_isdigit(int c);
#endif