/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:02:58 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:08:32 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			**cpy_tab(char **tab)
{
	char	**tmp;
	int		j;
	int		i;

	i = size_tab(tab);
	j = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * (size_tab(tab) + 1))))
		return (NULL);
	while (i > 0)
	{
		if (!(tmp[j] = ft_strdup(tab[j])))
			return (NULL);
		j++;
		i--;
	}
	tmp[size_tab(tab)] = NULL;
	return (tmp);
}
