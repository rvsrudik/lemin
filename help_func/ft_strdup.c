/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:24:52 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/04 17:07:15 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if ((tmp = (char*)(malloc(len))) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
