/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:46:15 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/25 14:43:35 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		nb_word(char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static char		*fill_tab(char *s, char c, int *i)
{
	char	*str;
	int		j;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		j++;
		*i += 1;
	}
	str[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = nb_word((char*)s, c);
	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (k < nb_word((char *)s, c) && s[i])
	{
		tab[k] = fill_tab((char*)s, c, &i);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
