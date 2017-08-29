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

#include "includes/lemin.h"

void			ft_free_matrix(int **matrix, int x)
{
	int i;

	i = 0;
	while (i <= x)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int		ft_find_room(char **rooms, char *link)
{
	int		i;
	char	*trim_link;

	i = 0;
	while (rooms[i] != 0)
	{
		trim_link = link;
		if (!strcmp(trim_link, rooms[i]))
		{
			return (1);
		}
		i++;
	}
	ft_error();
	return (0);
}

static int		ft_is_room_link_exist(char **rooms, char **links)
{
	int		i;
	char	**links_arr;

	i = 0;
	while (links[i] != 0)
	{
		links_arr = ft_strsplit(links[i], '-');
		ft_find_room(rooms, links_arr[0]);
		ft_find_room(rooms, links_arr[1]);
		ft_free_str_array(links_arr);
		i++;
	}
	return (0);
}

char			**ft_find_print_rooms(char **input)
{
	char	**print_rooms;
	int		i;
	int		k;
	int		rooms;

	i = 0;
	k = 0;
	rooms = ft_determ_number_of_rooms(input);
	print_rooms = (char**)malloc(sizeof(char*) * (rooms + 3));
	print_rooms[rooms + 2] = 0;
	while (input[i] != 0)
	{
		if (ft_is_start(input[i], input[i + 1])
		|| ft_is_end(input[i], input[i + 1]) || ft_is_rooms(input[i]))
		{
			print_rooms[k] = ft_strnew(ft_strlen(input[i]));
			print_rooms[k] = ft_strcpy(print_rooms[k], input[i]);
			k++;
		}
		i++;
	}
	return (print_rooms);
}

void			ft_check_input(char **input)
{
	int		num_of_ants;
	char	**rooms;
	char	**links;
	int		**matrix;
	char	**print_rooms;

	num_of_ants = ft_find_number_of_ants(input);
	ft_is_links_exist(input);
	print_rooms = ft_find_print_rooms(input);
	ft_is_start_end_exist(input);
	rooms = ft_find_rooms(input);
	links = ft_find_links(input);
	ft_is_room_link_exist(rooms, links);
	ft_is_same_rooms(rooms);
	matrix = ft_create_matrix(rooms, links);
	ft_free_str_array(input);
	ft_find_way(num_of_ants, rooms, links, matrix, print_rooms);
}
