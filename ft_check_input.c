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

void ft_free_matrix(int **matrix, int rooms)
{
    int i;


    i = 0;

    while (i <= rooms)
    {
            free(matrix[i]);
        i++;
    }
    free(matrix);
}

int ft_is_rooms(char *line)
{
	char	**room;

	room = ft_strsplit(line, ' ');
	if (count_str_array(room) != 3)
	{
		ft_free_str_array(room);
		return (0);
	}
	if(room[0][0] == '#' || room[0][0] == 'L')
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

static void  ft_is_same_rooms(char **rooms)
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
//                printf("%s %s\n", rooms[i], rooms[k]);
                flag++;
            }
            k++;
        }
        if (flag > 1)
        {
//            printf("%d\n", flag);
            ft_error();
        }
        flag = 0;
        k = 0;
        i++;
    }
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

void ft_is_links_exist(char **input)
{
    int i;
    int flag;

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



void ft_is_start_end_exist(char **input)
{
    int     i;
    int     count_start;
    int     count_finish;

    i = 0;
    count_finish = 0;
    count_start = 0;
//    printf("here\n");

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

void			ft_check_input(char **input)
{
	int		num_of_ants;
	char	**rooms;
	char	**links;
    int     **matrix;

	num_of_ants = ft_find_number_of_ants(input);
    ft_is_links_exist(input);
    ft_is_start_end_exist(input);
	rooms = ft_find_rooms(input);
	links = ft_find_links(input);

    ft_is_room_link_exist(rooms, links);
    ft_is_same_rooms(rooms);

    matrix = ft_create_matrix(rooms, links);

	ft_free_str_array(input);

    ft_find_way(num_of_ants, rooms, links, matrix);

//	ft_free_str_array(links);
//	ft_free_str_array(rooms);
//    ft_free_matrix(matrix, ft_count_rooms(rooms));


//	printf("%d\n", num_of_ants);


    int		i;

//	printf("////////LINKS///////////\n");
//	i = 0;
//	while (links[i] != 0)
//	{
//		printf("%s\n", links[i]);
//		i++;
//	}
//
//  i = 0;
//	printf("/////////ROMS//////////\n");
//	while (rooms[i] != 0)
//	{
//		printf("%s\n", rooms[i]);
//		i++;
//	}
//
//	i = 0;
//
//	printf("///////////////////\n");
//
//	while (input[i] != 0)
//	{
//		printf("%s\n", input[i]);
//		i++;
//	}



    ft_print_matrix(matrix, ft_count_rooms(rooms));
}