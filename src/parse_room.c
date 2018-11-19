/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:20:48 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/17 16:49:25 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			check_value_coord(char *str)
{
	char	*tmp2;
	int		value;

	value = ft_atoi(str);
	if (!(tmp2 = ft_itoa(value)))
		return (-1);
	if ((ft_strcmp(str, tmp2) != 0))
	{
		free(tmp2);
		return (-1);
	}
	free(tmp2);
	return (0);
}

static int			check_coord(char **tab)
{
	int		i;
	int		j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) && (check_value_coord(tab[i]) == 0))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

static int			check_name(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i][j])
	{
		if (tab[i][j] == '-' || tab[0][0] == 'L')
		{
			return (-1);
		}
		j++;
	}
	return (0);
}

int					check_tab(char **tab, t_lem *lem)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (-1);
	if (check_name(tab) == -1)
		return (-1);
	if (check_coord(tab) == -1)
		return (-1);
	if (check_same_name_room(lem, tab) == -1)
		return (-1);
	return (0);
}

int					get_parse_2(t_lem **lem, char *str)
{
	if (ft_strchr(str, ' '))
	{
		if (check_data_room(*lem, str) == -1)
			return (-1);
	}
	if (ft_strchr(str, '-') != NULL)
	{
		if (check_connexion(*lem, str) == -1)
			return (-1);
	}
	return (0);
}
