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
 * way_info[i][2]   - от какой ячейки пришел;
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
//            printf("gray: %d, status %d || ", i, way_info[i][0]);
            k = 1;
            while (k <= ft_count_rooms(rooms)) //проходим по матрице
            {
                if (matrix[i + 1][k] == 1 && way_info[k-1][0] == 0) //находим линковку i и k(другой домик)
                {
                    way_info[k-1][0] = 1;
                    way_info[k-1][1] = way_info[i][1] + 1;
                    way_info[k-1][2] = i;
                }
                k++;
            }
            way_info[i][0] = 2;
//            printf("gray: %d %d ", i, way_info[i][0]);
        }
        i++;
    }


    return way_info;
}

void ft_is_no_way(int **way_info, char **rooms)
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

int     **ft_fill_way_info(int **way_info, char **rooms, char **links, int **matrix)
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
        ft_is_no_way(way_info,  rooms);
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

int     **ft_get_info_way_array(int num_of_ants, char **rooms, char **links, int **matrix)
{
    int **way_info;
    int i;
    int count_rooms;

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


    way_info = ft_fill_way_info(way_info, rooms, links, matrix);


    return (way_info);
}


int     *ft_determ_shortest_way(int **way_info, char **rooms)
{
    int     *shortest_way;
    int     room_index;
    int     current_link;
    int     i;
    int     steps;


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




//    int     *shortest_way;
//    int     i;
//    int     k;
//    int     steps;
//    int     j;
//
//    i = 0;
//    k = 0;
//    j = 0;
//    steps = way_info[1][1];
//
//    shortest_way = (int*)malloc(sizeof(int) * steps);
//
//    shortest_way[steps - 1] = 1;
//
//    k = steps - 1;
//    i = way_info[1][3];
//    while (way_info[i][3] != -1)
//    {
//        shortest_way[];
//        i = way_info[i][3];
//    }

//    while (i < way_info[1][1])
//    {
//        j = 0;
//        while (j < ft_count_rooms(rooms))
//        {
//            if (way_info[j][1] == k)
//            {
//                shortest_way[k-1] = j;
//                k--;
//                break;
//            }
//            j++;
//        }
//        i++;
//    }

//    printf("%d\n", way_info[1][1]);
//    printf("\n---------\n");
//    i = 0;
//    while (i < way_info[1][1])
//    {
//        printf("%d ", shortest_way[i]);
//        i++;
//    }
//    printf("\n---------\n");

    return shortest_way;
}

char    **ft_convert_way_to_names(int *shortest_way_by_index, int **way_info, char **rooms)
{
    int i;
    char    **shortest_way_by_names;
    int size = way_info[1][1];

    i = 0;
    shortest_way_by_names = (char**)malloc(sizeof(char*) * (size + 1));
    shortest_way_by_names[size] = 0;

    while (i < size)
    {

        shortest_way_by_names[i] = rooms[shortest_way_by_index[i]];
		printf("%s ", shortest_way_by_names[i]);
        i++;
    }


//    printf("\n");
    return shortest_way_by_names;

}

void ft_print_params(int num_of_ants, char **rooms, char **links, char **print_rooms)
{
	int i;

	i = 0;

	printf("%d\n", num_of_ants);

	while (print_rooms[i] != 0)
	{
		printf("%s\n", print_rooms[i]);
		i++;
	}
	i = 0;
	while (links[i] != 0)
	{
		printf("%s\n", links[i]);
		i++;
	}
	printf("\n");

}



void        ft_find_way(int num_of_ants, char **rooms, char **links, int **matrix, char **print_rooms)
{
    int     **way_info;
    int     *shortest_way_by_index;
    char    **shortest_way_by_names;

    way_info = ft_get_info_way_array(num_of_ants, rooms, links, matrix);

    shortest_way_by_index = ft_determ_shortest_way(way_info, rooms);

    shortest_way_by_names = ft_convert_way_to_names(shortest_way_by_index, way_info, rooms);
	free(shortest_way_by_index);

	ft_print_params(num_of_ants, rooms, links, print_rooms);

    ft_print_way(shortest_way_by_names, num_of_ants, way_info[1][1]);

	free(shortest_way_by_names);
	ft_free_matrix(matrix, ft_count_rooms(rooms));
	ft_free_str_array(rooms);
	ft_free_str_array(links);
	ft_free_str_array(print_rooms);
	ft_free_matrix(way_info, ft_count_rooms(rooms));








//
//    int l;
//    int k;
//    l = 0;
//
//    while (l < ft_count_rooms(rooms))
//    {
//        k = 0;
//        while (k < 3)
//        {
//            printf("%3d ", way_info[l][k]);
//            k++;
//        }
//        l++;
//        printf("\n");
//
//    }

}