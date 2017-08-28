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
** way_info[i][0]   - цвет прохождения; 0 - не проходили, 1 - соседи, 2 - прошел; 3 - нужно поменять; default = 0;
** way_info[i][1]   - расстояние от старта; default = -1;
**   i - индекс (+1?) дома;
**
*/

int **ft_find_room_links(int **way_info, int **matrix, char **rooms)
{
    int i;
    int k;

    i = 0;

    k = 1;

    while (i < ft_count_rooms(rooms)) //проходимся по всем комнатам
    {
        if (way_info[i][0] == 3)  // находим  серые комнаты
        {
            printf("gray: %d, status %d || ", i, way_info[i][0]);
            k = 1;
            while (k <= ft_count_rooms(rooms)) //проходим по матрице
            {
                if (matrix[i + 1][k] == 1 && way_info[k-1][0] == 0) //находим линковку i и k(другой домик)
                {
                    way_info[k-1][0] = 1;
                    way_info[k-1][1] = way_info[i][1] + 1;
                }
                k++;
            }
            way_info[i][0] = 2;
//            printf("gray: %d %d ", i, way_info[i][0]);
        }
        i++;
    }



        printf("-------------\n");
    int l;
    int ku;
    l = 0;

    while (l < ft_count_rooms(rooms))
    {
        ku = 0;
        while (ku < 2)
        {
            printf("%d ", way_info[l][ku]);
            ku++;
        }
        l++;
        printf("\n");

    }
    printf("\n------------\n");

    return way_info;
}

int **ft_fill_way_info(int **way_info, char **rooms, char **links, int **matrix)
{
    int i;
    int current_index;
    int steps_from_start;

    steps_from_start = 0;
//    i = 0;
    current_index = 0;
    way_info[0][0] = 1;
    way_info[0][1] = 0;


    while (way_info[1][1] == -1)
    {
//    printf("asd\n");
        i = 0;
        while (i < ft_count_rooms(rooms))
        {
            if (way_info[i][0] == 1)  //нашли серую ячейку
            {
                way_info[i][0] = 3;
            }
                i++;
        }
        way_info = ft_find_room_links(way_info, matrix, rooms);



//        printf("tuc\n");
//        way_info[1][1] = 1;
    }
    return (way_info);
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




    printf("%d \n", way_info[1][1]);







    int l;
    int k;
    l = 0;

    while (l < ft_count_rooms(rooms))
    {
        k = 0;
        while (k < 2)
        {
            printf("%d ", way_info[l][k]);
            k++;
        }
        l++;
        printf("\n");

    }

}