/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:02:21 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 17:34:54 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[k] != '\0')
	{
		tmp[i++] = s1[k];
		k++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		tmp[i++] = s2[k];
		k++;
	}
	tmp[i] = '\0';
	return (tmp);
}
