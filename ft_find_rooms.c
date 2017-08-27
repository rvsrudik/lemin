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

static int		ft_determ_number_of_rooms(char **input)
{
	int		i;
	int		rooms;

	i = 0;
	rooms = 0;
	while (!ft_is_links(input[i]))
	{
		if (ft_is_start(input[i]) || ft_is_end(input[i]))
			i++;
		else if (ft_is_comment(input[i]))
			i++;
		else if (ft_is_rooms(input[i]))
		{
			i++;
			rooms++;
		}
		else
			ft_error();
	}
	return (rooms);
}

static char		*ft_add_room(char *src, char *dst)
{
	int letters;
	char **line;

	line = ft_strsplit(dst, ' ');

	letters = ft_strlen(line[0]);

	src = ft_strnew(letters);

	src = ft_strcpy(src, line[0]);
	dst[0] = '#';

	ft_free_str_array(line);

	return (src);
}

static void		ft_norm_two(int *i, int *k, char **rooms, char **input)
{
	(*i)++;
	if (ft_is_rooms(input[*i]))
	{
		if (!rooms[1])
		{
			rooms[1] =	ft_add_room(rooms[1], input[*i]);
		}
		else
		{
			rooms[*k] = ft_add_room(rooms[*k], input[*i]);
			(*k)++;
		}
	}
}


static void		ft_norm_one(int *i, int *k, char **rooms, char **input)
{
	if (ft_is_start(input[*i]))
	{
		(*i)++;
		if (ft_is_rooms(input[*i]))
		{
			if (!rooms[0])
				rooms[0] =	ft_add_room(rooms[0], input[*i]);
			else
			{
				rooms[*k] =	ft_add_room(rooms[*k], input[*i]);
				(*k)++;
			}
		}
	}
	else if (ft_is_end(input[*i]))
		ft_norm_two(i, k, rooms, input);
	else if (ft_is_rooms(input[*i]))
	{
		rooms[*k] = ft_add_room(rooms[*k], input[*i]);
		(*k)++;
	}
	(*i)++;
}

char			**ft_find_rooms(char **input)
{
	int		i;
	int		number_of_rooms;
	char	**rooms;
	int		k;

	i = 0;
	k = 2;
	number_of_rooms = ft_determ_number_of_rooms(input);
	rooms = (char**)malloc(sizeof(char**) * (number_of_rooms + 1));
	while (i <= number_of_rooms)
	{
		rooms[i] = 0;
		i++;
	}
	i = 0;
	while (!ft_is_links(input[i]))
	{
		ft_norm_one(&i, &k, rooms, input);
	}
	return (rooms);
}