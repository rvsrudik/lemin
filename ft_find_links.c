/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:21:35 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 18:35:40 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

static int		ft_determ_number_of_links(char **input)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (input[i] != 0)
	{
		if (ft_is_start(input[i]) || ft_is_end(input[i]))
			i++;
		else if (ft_is_comment(input[i]))
			i++;
		else if (ft_is_links(input[i]))
		{
			i++;
			links++;
		}
		else
			ft_error();
	}
	return (links);
}

static char		*ft_add_link(char *src)
{
	int		letters;
	char	*new_link;

	letters = ft_strlen(src);
	new_link = ft_strnew(letters);
	new_link = ft_strcpy(new_link, src);
	src[0] = '#';
	return (new_link);
}

static void		ft_norm_one(int *i, int *k, char **links, char **input)
{
	if (ft_is_links(input[*i]))
	{
		links[*k] = ft_add_link(input[*i]);
		(*k)++;
	}
	else if (!ft_is_comment(input[*i]))
		ft_error();
	(*i)++;
}

char **ft_find_links(char **input)
{
	int		i;
	char	**links;
	int		number_of_links;
	int		k;

	i = 0;
	k = 0;
	number_of_links = ft_determ_number_of_links(input);
	links = (char**)malloc(sizeof(char**) * (number_of_links + 1));
	while (i <= number_of_links)
	{
		links[i] = 0;
		i++;
	}
	i = 0;
	while (input[i] != 0)
	{
		ft_norm_one(&i, &k, links, input);
	}
	return (links);
}