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

void ft_free_str_arrat(char **line)
{
	int i;

	i = 0;

	while (line[i] != 0)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int ft_is_number(char *num)
{
	int i;

	i = 0;

	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_is_comment(char *line)
{
	if (line[0] == '#')
	{
		return (1);
	}
	return (0);
}

int ft_is_number_of_ants(char *line)
{
	int i;

	i = 0;
	if (strlen(line) == 0)
	{
		return (0);
	}
	if (!ft_is_number(line))
	{
		return (0);
	}
	return (1);
}

int ft_is_rooms(char *line)
{
	char	**room;

	room = ft_strsplit(line, ' ');
	if (count_str_array(room) != 3)
	{
		ft_free_str_arrat(room);
		return (0);
	}

//	printf("%d\n", count_str_array(room));
//	printf("[%s]\n", room[0]);
//	printf("[%s]\n", room[1]);
//	printf("[%s]\n", room[2]);
//
	if(room[0][0] == '#' || room[0][0] == 'L')
	{
		ft_free_str_arrat(room);
		return (0);
	}

	if (!ft_is_number(room[1]))
	{
		ft_free_str_arrat(room);
		return (0);
	}
	if (!ft_is_number(room[2]))
	{
		ft_free_str_arrat(room);
		return (0);
	}
	ft_free_str_arrat(room);
	return (1);
}

int ft_is_links(char *line)
{
	char **link;

	link = ft_strsplit(line, '-');

//		printf("%d\n", count_str_array(link));
//	printf("[%s]\n", link[0]);
//	printf("[%s]\n", link[1]);

	if (count_str_array(link) != 2)
	{
		ft_free_str_arrat(link);
		return (0);
	}
	ft_free_str_arrat(link);
	return (1);
}

int ft_is_start(char * line)
{
	if (!ft_strcmp(line, "#start"))
	{
		return (1);
	}
	return (0);
}

int ft_is_end(char * line)
{
	if (!ft_strcmp(line, "#end"))
	{
		return (1);
	}
	return (0);
}


int ft_find_number_of_ants(char **input)
{
	int i;
	int number_of_ants;

	i = 0;

	while (input[i] != 0)
	{
		if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_number_of_ants(input[i]))
		{
			number_of_ants = ft_atoi(input[i]);
			input[i][0] = '#';
			return (number_of_ants);
		}
		else
		{
			ft_error();
		}
	}
	return 0;
}

int ft_determ_number_of_rooms(char **input)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (!ft_is_links(input[i]))
	{
		if (ft_is_start(input[i]) || ft_is_end(input[i]))
		{
			i++;
		}
		else if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_rooms(input[i]))
		{
			i++;
			rooms++;
		}
		else
		{
			ft_error();
		}
	}
	return (rooms);
}

char **ft_find_rooms(char **input)
{
	int i;
	int number_of_rooms;

	i = 0;

	number_of_rooms = ft_determ_number_of_rooms(input);

	printf("%d\n", number_of_rooms);

//	while (!ft_is_links(input[i]))
//	{
//		if (ft_is_start(input[i]))
//		{
//			i++;
//		}
//
//	}
	return 0;
}



void ft_check_input(char **input)
{
	int i;
	int num_of_ants;
	char **rooms;
	i = 0;

	num_of_ants = ft_find_number_of_ants(input);
//	rooms = ft_find_rooms(input);

	printf("%d\n", ft_is_links("    asdf   -   23       32        "));


//	printf("%d\n", num_of_ants);

//	while (input[i] != 0)
//	{
//		printf("%s\n", input[i]);
//		i++;
//	}
}