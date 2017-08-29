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

int     ft_count_rooms(char **rooms)
{
    int     i;

    i = 0;
    while (rooms[i] != 0)
    {
        i++;
    }
    return (i);
}

void ft_print_matrix(int **matrix, int numb_of_rooms)
{
    int i;
    int k;

    i = 0;
    while (i <= numb_of_rooms)
    {
        k = 0;
        while (k <= numb_of_rooms)
        {
//            printf("%d ", matrix[i][k]);
            k++;
        }
//        printf("\n");
        i++;
    }
}

int     **ft_create_empty_matrix(int numb_of_rooms)
{
    int **empty_matrix;
    int i;
    int k;

    i = 0;
    empty_matrix = (int**)malloc(sizeof(int*) * (numb_of_rooms + 1));
    while (i <= numb_of_rooms)
    {
        empty_matrix[i] = (int*)malloc(sizeof(int) * (numb_of_rooms + 1));
        k = 0;
        while (k <= numb_of_rooms)
        {
            if (k == 0)
                empty_matrix[i][k] = i;
            else if (i == 0)
                empty_matrix[i][k] = k;
            else
                empty_matrix[i][k] = 0;
            k++;
        }
        i++;
    }
    return (empty_matrix);
}

int     ft_get_room_index(char **rooms, char *name_room)
{
    int i;

    i = 0;
    while (rooms[i] != 0)
    {
        if (!ft_strcmp(rooms[i], name_room))
        {
            return (i);
        }
        i++;
    }
    return (-1);
}

int     **ft_fill_matrix(int **matrix, char **links, int numb_of_rooms, char **rooms)
{
    int     i;
    char    **links_params;
    int     coord_x;
    int     coord_y;

    i = 0;
    while (links[i] != 0)
    {
        links_params = ft_strsplit(links[i], '-');
        coord_x = ft_get_room_index(rooms, links_params[0]) + 1;
        coord_y = ft_get_room_index(rooms, links_params[1]) + 1;
        matrix[coord_x][coord_y] = 1;
        matrix[coord_y][coord_x] = 1;
        i++;
        ft_free_str_array(links_params);
    }
    return (matrix);
}

int     **ft_create_matrix(char **rooms, char **links)
{
    int     **matrix;
    int     numb_of_room;

    numb_of_room = ft_count_rooms(rooms);
    matrix = ft_create_empty_matrix(numb_of_room);
    matrix = ft_fill_matrix(matrix, links, numb_of_room, rooms);

    return (matrix);
}