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

#include "../includes/lem-in.h"

int		ft_countchars(char *str, char c)
{
	int		i;
	int		conut_char;

	conut_char = 0;
	i = 0;


	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			conut_char++;
		}
		i++;
	}

	return (conut_char);
}
