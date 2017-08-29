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
	int *way_array;
	int i;
	int k;
	int aunts_to_start;
	int aunts_to_end;
	int tmp;
	int suka = 0;
	int flag;


	i = 0;

	way_array = (int*)malloc(sizeof(int) * (num_of_ants + 2));


	while (i <= way_len)
	{

		way_array[i] = 0;
		i++;
	}

	way_array[0] = num_of_ants;
	way_array[way_len + 1] = 0;




	while (way_array[way_len+1] != num_of_ants)
	{
		i = way_len;
		suka = 0;


		flag = 0;
		while (i >= 0)
		{
			tmp++;
			if (way_array[i] > 0)
			{
				way_array[i] -= 1;
				way_array[i + 1] += 1;
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

				if(i != 0)
				{
					flag = 1;
					suka++;
//					write(1, "L", 1);
					write(1, "L", 1);
					ft_putnbr(aunts_to_end);
					write(1, "-", 1);
					write(1, shortest_way_by_names[i -1], ft_strlen(shortest_way_by_names[i -1]));
					if (i != 1 && aunts_to_start != 0)
					{
						write(1, " ", 1);
					}
				}

			}
			i--;
		}
		if (flag == 1)
		{
			write(1, "\n", 1);
		}
		tmp = 0;
	}
	free(way_array);
}