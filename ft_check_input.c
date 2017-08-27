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

int ft_is_comment(char *line)
{
	if (line[0] == '#')
	{
		return (1);
	}
	return (0);
}

int ft_is_number_of_ants(char *line)
{
	int i;

	i = 0;
	if (strlen(line) == 0)
	{
		return (0);
	}
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void ft_is_rooms(char *line)
{

}

void ft_is_links(char *line)
{

}

void ft_is_start_end(char * line)
{

}


int ft_find_number_of_ants(char **input)
{
	int i;
	int number_of_ants;

	i = 0;

	while (input[i] != 0)
	{
		if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_number_of_ants(input[i]))
		{
			number_of_ants = ft_atoi(input[i]);
			input[i][0] = '#';
			return (number_of_ants);
		}
		else
		{
			ft_error();
		}
	}
	return 0;
}



void ft_check_input(char **input)
{
	int i;
	int num_of_ants;

	i = 0;

	num_of_ants = ft_find_number_of_ants(input);


//	printf("%d\n", num_of_ants);

	while (input[i] != 0)
	{
		printf("%s\n", input[i]);
		i++;
	}

}