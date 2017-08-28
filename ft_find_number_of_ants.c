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

static int ft_check_max_int(char *number)
{
	if (ft_strlen(number) > 10)
	{
		return (0);
	}
	if (ft_strlen(number) == 10)
	{
		if (number[0] > 50)
		{
			return (0);
		}
		if (ft_atoi(number) < 0)
		{
			return (0);
		}
	}
	return (1);
}

int			ft_find_number_of_ants(char **input)
{
	int		i;
	int		number_of_ants;

	i = 0;
	while (input[i] != 0)
	{
		if (ft_is_comment(input[i]))
			i++;
		else if (ft_is_number_of_ants(input[i]))
		{
			if (!ft_check_max_int(input[i]))
				ft_error();
			number_of_ants = ft_atoi(input[i]);
			if (number_of_ants == 0)
				ft_error();
			input[i][0] = '#';
			return (number_of_ants);
		}
		else
			ft_error();
	}
	return 0;
}