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


void ft_print_way(char **shortest_way_by_names, int num_of_ants, int way_len)
{
//	int start_ant;
//	int finish_ant;
	int *way_array;
	int i;
	int k;
	int aunts_to_start;
	int aunts_to_end;


//	printf("!!!%s\n", shortest_way_by_names[0]);
//	printf("!!!%s\n", shortest_way_by_names[1]);
//	printf("!!!%s\n", shortest_way_by_names[2]);

	printf("////////////\n");


	i = 0;

	way_array = (int*)malloc(sizeof(int) * (num_of_ants + 2));

//	printf(">>%d\n", way_len);
	while (i <= way_len)
	{

		way_array[i] = 0;
//		printf("%d > %d\n", i, way_array[i]);
		i++;
	}

//	printf("[%d] | %d |  %d |  %d |   [%d]\n", way_array[0], way_array[1], way_array[2], way_array[3], way_array[4]);
	way_array[0] = num_of_ants;
	way_array[way_len + 1] = 0;



//	i = way_len - 1;

//	printf("!%d\n", way_array[0]);
	while (way_array[way_len+1] != num_of_ants)
	{
//		printf("yobana\n");
		i = way_len;
		while (i >= 0)
		{
//			printf("i = %d\n", i);
			if (way_array[i] > 0)
			{
				way_array[i] -= 1;
				way_array[i + 1] += 1;
//
				k = i;
				aunts_to_start = 0;

				while (k >= 0)
				{
					aunts_to_start += way_array[k];
					k--;
				}
				k = i;
				aunts_to_end = 0;
				while (k <= way_len + 1)
				{
					aunts_to_end += way_array[k];
					k++;
				}
//				printf("k = %d, to start %d, to end %d\n",k, aunts_to_start,  aunts_to_end);
				if(i != 0)
//					printf("L%d-%s (start %d)(end %d) ", aunts_to_end, shortest_way_by_names[(i-1)], aunts_to_start, aunts_to_end);
					printf("L%d-%s ", aunts_to_end, shortest_way_by_names[(i-1)]);
			}
			i--;
		}
		printf("\n");
//		printf("[%d] | %d |  %d |  %d |   [%d]\n", way_array[0], way_array[1], way_array[2], way_array[3], way_array[4]);
	}

//    printf("%d\n", way_len);
//    printf("%d\n", num_of_ants);
}