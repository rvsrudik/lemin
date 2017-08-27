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

int		ft_is_comment(char *line)
{
	if (line[0] == '#')
	{
		return (1);
	}
	return (0);
}

int		ft_is_number_of_ants(char *line)
{
	int i;

	i = 0;
	if (strlen(line) == 0)
	{
		return (0);
	}
	if (!ft_is_number(line))
	{
		return (0);
	}
	return (1);
}

int		ft_is_start(char * line)
{
	if (!ft_strcmp(line, "##start"))
	{
		return (1);
	}
	return (0);
}

int		ft_is_end(char * line)
{
	if (!ft_strcmp(line, "##end"))
	{
		return (1);
	}
	return (0);
}

int		ft_is_links(char *line)
{
	char	**link;

	link = ft_strsplit(line, '-');
	if (count_str_array(link) != 2)
	{
		ft_free_str_array(link);
		return (0);
	}
	ft_free_str_array(link);
	if (ft_countchars(line, '-') != 1)
	{
		return (0);
	}
	return (1);
}