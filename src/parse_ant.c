/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:00:56 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:12:04 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int					check_value(char *str, t_lem *lem, int i, int j)
{
	char			*tmp;
	char			*tmp2;
	int				value;

	if (!(tmp = ft_strsub(str, j, i)))
		return (-1);
	value = ft_atoi(tmp);
	if (!(tmp2 = ft_itoa(value)))
		return (-1);
	if ((ft_strcmp(tmp, tmp2) != 0) || value < 0)
	{
		free(tmp);
		free(tmp2);
		return (-1);
	}
	free(tmp);
	free(tmp2);
	lem->nb_ant = value;
	return (0);
}

static int			check_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

int					check_nb_ant(t_lem *lem, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (check_str(str) == 0)
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			i++;
		if (ft_isdigit(str[i]) || str[i] == '+' || (str[i] == '-' &&
					ft_isdigit(str[i + 1])))
		{
			j = i;
			while (ft_isdigit(str[i]) == 1)
				i++;
			if (check_value(str, lem, i, j) == -1)
				return (-1);
			break ;
		}
		i++;
	}
	return (0);
}
