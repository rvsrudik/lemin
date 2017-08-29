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

void		ft_print_step(int *i, int end, char *name, int start)
{
	write(1, "L", 1);
	ft_putnbr(end);
	write(1, "-", 1);
	write(1, name, ft_strlen(name));
	if (*i != 1 && start != 0)
	{
		write(1, " ", 1);
	}
}

void		ft_norm_one(int *i, int *k, int *way_array, int *start)
{
	way_array[*i] -= 1;
	way_array[*i + 1] += 1;
	*k = *i;
	*start = 0;
	while (*k >= 0)
	{
		*start += way_array[*k];
		(*k)--;
	}
	*k = *i;
}

void		ft_norm_two(int *k, int *way_array, int *end, int way_len)
{
	*end = 0;
	while (*k <= way_len + 1)
	{
		*end += way_array[*k];
		(*k)++;
	}
}

void		ft_t(int *i, int *end, char *name, int *start)
{
	if (*i != 0)
		ft_print_step(i, *end, name, *start);
}

void		ft_print_way(char **short_way_by_n,
			int num_of_ants, int way_len)
{
	int *way_array;
	int i;
	int k;
	int start_end[2];
	int flag;

	way_array = ft_new_int_array(num_of_ants + 2, num_of_ants, way_len);
	while (way_array[way_len + 1] != num_of_ants)
	{
		i = way_len;
		flag = 0;
		while (i >= 0)
		{
			if (way_array[i] > 0)
			{
				ft_norm_one(&i, &k, way_array, &start_end[0]);
				ft_norm_two(&k, way_array, &start_end[1], way_len);
				ft_t(&i, &start_end[1], short_way_by_n[i - 1], &start_end[0]);
				(i != 0) ? flag = 1 : 0;
			}
			i--;
		}
		(flag == 1) ? write(1, "\n", 1) : 0;
	}
	free(way_array);
}
