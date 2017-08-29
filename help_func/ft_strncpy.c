/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/04 17:05:57 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	char	*t;
	int		flag;

	i = 0;
	t = dest;
	flag = 0;
	while (i < len)
	{
		if (src[i] == '\0' || flag == 1)
		{
			t[i] = '\0';
			flag = 1;
		}
		if (flag == 0)
			t[i] = src[i];
		i++;
	}
	return (dest);
}
