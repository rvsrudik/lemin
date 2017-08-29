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

#include "includes/lemin.h"

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
