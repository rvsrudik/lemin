/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:27:46 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:24:50 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

int		count_str_array(char **input)
{
	int		i;
	int		count_lines;

	i = 0;
	count_lines = 0;
	while (input[i])
	{
		i++;
		count_lines++;
	}
	return (count_lines);
}

void	ft_free_old_array(char **input)
{
	int		i;

	i = 0;
	while(input[i] != 0)
	{
		free(input[i]);
		i++;
	}
	free(input[i]);
	free(input);
}

char	**ft_add_line(char** input, char* line)
{
	int		count_lines;
	int		i;
	char	**new_input;

	count_lines = count_str_array(input);
	i = 0;
	if (!(new_input = (char**)malloc(sizeof(char*) * (count_lines + 2))))
	{
		ft_free_old_array(input);
		free(line);
		ft_error();
	}
	while (i < count_lines + 2)
		new_input[i++] = 0;
	i = 0;
	while (i < count_lines){
		new_input[i] = ft_strnew(ft_strlen(input[i]));
		new_input[i] = ft_strcpy(new_input[i], input[i]);
		i++;
	}
	ft_free_old_array(input);
	new_input[i] = ft_strnew(ft_strlen(line));
	new_input[i] = ft_strcpy(new_input[i], line);
	return (new_input);
}

char	**ft_read_input()
{
	char	*line;
	char	**input;
	int		tmp;

	tmp = 0;
	input = (char **)malloc(sizeof(char*) * 1);
	input[0] = 0;
	while (get_next_line(0, &line) > 0)
	{
		tmp++;
		input = ft_add_line(input, line);
		free(line);
	}
	if (!tmp)
	{
		ft_error();
	}
	return input;
}