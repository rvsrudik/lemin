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

int				ft_is_rooms(char *line)
{
	char	**room;

	room = ft_strsplit(line, ' ');
	if (count_str_array(room) != 3)
	{
		ft_free_str_array(room);
		return (0);
	}
	if (room[0][0] == '#' || room[0][0] == 'L')
	{
		ft_free_str_array(room);
		return (0);
	}
	if (!ft_is_number(room[1]))
	{
		ft_free_str_array(room);
		return (0);
	}
	if (!ft_is_number(room[2]))
	{
		ft_free_str_array(room);
		return (0);
	}
	ft_free_str_array(room);
	return (1);
}

void			ft_is_same_rooms(char **rooms)
{
	int i;
	int k;
	int flag;

	flag = 0;
	k = 0;
	i = 0;
	while (rooms[i] != 0)
	{
		while (rooms[k] != 0)
		{
			if (!ft_strcmp(rooms[i], rooms[k]))
			{
				flag++;
			}
			k++;
		}
		if (flag > 1)
		{
			ft_error();
		}
		flag = 0;
		k = 0;
		i++;
	}
}

void			ft_is_links_exist(char **input)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (input[i] != 0)
	{
		if (ft_is_links(input[i]))
		{
			flag = 1;
		}
		i++;
	}
	if (!flag)
		ft_error();
}

void			ft_is_start_end_exist(char **input)
{
	int		i;
	int		count_start;
	int		count_finish;

	i = 0;
	count_finish = 0;
	count_start = 0;
	while (input[i] != 0)
	{
		if (ft_is_start(input[i], input[i + 1]))
			count_start++;
		i++;
	}
	i = 0;
	while (input[i] != 0)
	{
		if (ft_is_end(input[i], input[i + 1]))
			count_finish++;
		i++;
	}
	if (!count_finish || !count_start)
		ft_error();
}
