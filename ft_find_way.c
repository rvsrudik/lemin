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

/*
** way_info[i][0]   - цвет прохождения; 0 - не проходили, 1 - соседи, 2 - прошел; default = 0;
** way_info[i][1]   - расстояние от старта; default = -1;
**   i - индекс (+1?) дома;
**
*/

int **ft_fill_way_info(int **way_info, char **rooms, char **links, int **matrix)
{
    int i;
    int current_index;


    i = 1;
    current_index = 0;

    while (way_info[1][1] == 0)
    {
    printf("asd");
        while (i <= ft_count_rooms(rooms))
        {
//            if ()
//            if ( matrix[current_index + 1][i] == 1 )
//            {
                printf("%d ", matrix[current_index + 1][i]);
//            }

                i++;
        }

        printf("tuc\n");
        way_info[1][1] = 2;
    }
    return (0);
}

int **ft_get_info_way_array(int num_of_ants, char **rooms, char **links, int **matrix)
{
    int **way_info;
    int i;
    int count_rooms;

    i = 0;
    count_rooms = ft_count_rooms(rooms);

    way_info = (int**)malloc(sizeof(int*) * ft_count_rooms(rooms));

    while (i < count_rooms)
    {
        way_info[i] = (int*)malloc(sizeof(int) * 2);
        way_info[i][0] = 0;
        way_info[i][1] = -1;
        i++;
    }


    way_info = ft_fill_way_info(way_info, rooms, links, matrix);


    return (way_info);
}

void ft_find_way(int num_of_ants, char **rooms, char **links, int **matrix)
{
    int **way_info;

    way_info = ft_get_info_way_array(num_of_ants, rooms, links, matrix);
//    way_info












//    int l;
//    int k;
//    l = 0;
//
//    while (l < ft_count_rooms(rooms))
//    {
//        k = 0;
//        while (k < 2)
//        {
//            printf("%d ", way_info[l][k]);
//            k++;
//        }
//        l++;
//        printf("\n");
//
//    }

}