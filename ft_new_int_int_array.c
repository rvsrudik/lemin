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

int			*ft_new_int_array(int size, int num_of_ants, int way_len)
{
	int *way_array;
	int i;

	i = 0;
	way_array = (int*)malloc(sizeof(int) * (size));
	while (i <= way_len)
	{
		way_array[i] = 0;
		i++;
	}
	way_array[0] = num_of_ants;
	way_array[way_len + 1] = 0;
	return (way_array);
}