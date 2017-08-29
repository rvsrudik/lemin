/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 07:21:42 by vrudenko          #+#    #+#             */
/*   Updated: 2017/08/29 07:21:44 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

int			**ft_find_room_links(int **way_info, int **matrix, char **rooms)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (i < ft_count_rooms(rooms))
	{
		if (way_info[i][0] == 3)
		{
			k = 1;
			while (k <= ft_count_rooms(rooms))
			{
				if (matrix[i + 1][k] == 1 && way_info[k - 1][0] == 0)
				{
					way_info[k - 1][0] = 1;
					way_info[k - 1][1] = way_info[i][1] + 1;
					way_info[k - 1][2] = i;
				}
				k++;
			}
			way_info[i][0] = 2;
		}
		i++;
	}
	return (way_info);
}

void		ft_is_no_way(int **way_info, char **rooms)
{
	int i;
	int grays;

	grays = 0;
	i = 0;
	while (i < ft_count_rooms(rooms))
	{
		if (way_info[i][0] == 1)
		{
			grays++;
		}
		i++;
	}
	if (!grays)
		ft_error();
}

int			**ft_fill_way_info(int **way_info, char **rooms, int **matrix)
{
	int i;
	int current_index;
	int steps_from_start;

	steps_from_start = 0;
	current_index = 0;
	way_info[0][0] = 1;
	way_info[0][1] = 0;
	while (way_info[1][1] == -1)
	{
		ft_is_no_way(way_info, rooms);
		i = 0;
		while (i < ft_count_rooms(rooms))
		{
			if (way_info[i][0] == 1)
			{
				way_info[i][0] = 3;
			}
			i++;
		}
		way_info = ft_find_room_links(way_info, matrix, rooms);
	}
	return (way_info);
}

int			**ft_get_info_way_array(char **rooms, int **matrix)
{
	int		**way_info;
	int		i;
	int		count_rooms;

	i = 0;
	count_rooms = ft_count_rooms(rooms);
	way_info = (int**)malloc(sizeof(int*) * ft_count_rooms(rooms));
	way_info[ft_count_rooms(rooms)] = 0;
	while (i < count_rooms)
	{
		way_info[i] = (int*)malloc(sizeof(int) * 3);
		way_info[i][0] = 0;
		way_info[i][1] = -1;
		way_info[i][2] = -1;
		i++;
	}
	way_info = ft_fill_way_info(way_info, rooms, matrix);
	return (way_info);
}

int			*ft_determ_shortest_way(int **way_info)
{
	int		*shortest_way;
	int		room_index;
	int		current_link;
	int		i;
	int		steps;

	steps = way_info[1][1];
	i = steps - 1;
	current_link = way_info[1][2];
	room_index = 1;
	shortest_way = (int*)malloc(sizeof(int) * steps);
	shortest_way[i] = room_index;
	i--;
	while (current_link != -1)
	{
		shortest_way[i] = current_link;
		current_link = way_info[current_link][2];
		i--;
	}
	return (shortest_way);
}

char		**ft_convert_way_to_names(int *shortest_way_by_index,
			int **way_info, char **rooms)
{
	int		i;
	char	**shortest_way_by_names;
	int		size;

	size = way_info[1][1];
	i = 0;
	shortest_way_by_names = (char**)malloc(sizeof(char*) * (size + 1));
	shortest_way_by_names[size] = 0;
	while (i < size)
	{
		shortest_way_by_names[i] = rooms[shortest_way_by_index[i]];
		i++;
	}
	return (shortest_way_by_names);
}

void		ft_print_params(int num_of_ants, char **links, char **print_rooms)
{
	int i;

	i = 0;
	ft_putnbr(num_of_ants);
	write(1, "\n", 1);
	while (print_rooms[i] != 0)
	{
		write(1, print_rooms[i], ft_strlen(print_rooms[i]));
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (links[i] != 0)
	{
		write(1, links[i], ft_strlen(links[i]));
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_find_way(int num_of_ants, char **rooms,
			char **links, int **matrix, char **print_rooms)
{
	int		**way_info;
	int		*short_w_by_i;
	char	**short_w_by_names;

	way_info = ft_get_info_way_array(rooms, matrix);
	short_w_by_i = ft_determ_shortest_way(way_info);
	short_w_by_names = ft_convert_way_to_names(short_w_by_i, way_info, rooms);
	ft_print_params(num_of_ants, links, print_rooms);
	ft_print_way(short_w_by_names, num_of_ants, way_info[1][1]);
	ft_free_matrix(matrix, ft_count_rooms(rooms));
	ft_free_str_array(rooms);
	ft_free_str_array(links);
	ft_free_str_array(print_rooms);
//	ft_free_matrix(way_info, ft_count_rooms(rooms));
}
