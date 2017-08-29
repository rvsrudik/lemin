/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:19:47 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 14:21:08 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_runspace_back(char *str)
{
	char *s;

	s = str;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		s--;
	return (s + 1);
}

char	*ft_runspace(char *str)
{
	char *s;

	s = str;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		s++;
	return (s);
}

char	*ft_strtoend(char *str)
{
	char	*s;

	s = str;
	while (*s != '\0')
		s++;
	return (s - 1);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*fresh;
	char	*tmp;
	char	*freshstr;
	int		len;

	if (!s)
		return (0);
	i = 0;
	fresh = ft_runspace((char*)s);
	tmp = ft_strtoend(fresh);
	tmp = ft_runspace_back(tmp);
	while (fresh[i] != '\0' && &fresh[i] != tmp)
		i++;
	len = i;
	if ((freshstr = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	freshstr[len] = '\0';
	i = 0;
	ft_strncpy(freshstr, fresh, len);
	return (freshstr);
}
