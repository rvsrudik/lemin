/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:53:44 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/03 18:11:57 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int			ft_countsplit(char *str, char c)
{
	char	*temp;
	int		count;

	if (!str)
		return (0);
	temp = str;
	count = 0;
	temp = ft_runchar(temp, c);
	while (*temp != '\0')
	{
		temp = ft_runstr(temp, c);
		temp = ft_runchar(temp, c);
		count++;
	}
	return (count);
}

char		*ft_runchar(char *str, char c)
{
	char *tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp == c && *tmp != '\0')
		tmp++;
	return (tmp);
}

char		*ft_runstr(char *str, char c)
{
	char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp != c && *tmp != '\0')
		tmp++;
	return (tmp);
}

static int	ft_letters(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	char	*temp;
	int		words;
	int		k;

	k = 0;
	temp = ft_runchar((char*)s, c);
	words = ft_countsplit(temp, c);
	if ((fresh = (char**)malloc((sizeof(char**)) * words + 1)) == NULL)
		return (0);
	fresh[words] = 0;
	while (k < words)
	{
		fresh[k] = (char*)malloc(ft_letters(temp, c) + 1);
		fresh[k][ft_letters(temp, c)] = '\0';
		ft_strncpy(fresh[k], temp, ft_letters(temp, c));
		k++;
		temp = ft_runstr(temp, c);
		temp = ft_runchar(temp, c);
	}
	return (fresh);
}
