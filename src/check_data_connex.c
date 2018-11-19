/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_connex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:12:09 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:20:29 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			check_name(t_lem *lem, char *str)
{
	t_map *tmp;

	tmp = lem->map;
	while (tmp)
	{
		if (ft_strcmp(tmp->tab[0], str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void			ugly_one(t_lem *lem, char *str)
{
	char **tab;

	if (!(tab = ft_strsplit(str, ' ')))
		return ;
	lst_push_back_map(&lem->map, tab);
	free_tab(tab);
}

int					check_same_name_connexion(char **tab)
{
	if (ft_strcmp(tab[0], tab[1]) == 0)
		return (-1);
	return (0);
}

int					check_double_connexion(t_lem *lem, char **tab)
{
	t_parse_connex	*tmp;

	tmp = L->con;
	while (tmp)
	{
		if ((ft_strcmp(tab[0], tmp->tab[0]) == 0) && (ft_strcmp(tab[1],
						tmp->tab[1]) == 0))
		{
			return (0);
		}
		if ((ft_strcmp(tab[0], tmp->tab[1]) == 0) && (ft_strcmp(tab[1],
						tmp->tab[0]) == 0))
			return (0);
		tmp = tmp->next;
	}
	return (0);
}

int					check_connexion(t_lem *lem, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(str, '-')))
		return (-1);
	if (size_tab(tab) != 2)
	{
		free_tab(tab);
		return (-1);
	}
	if ((check_name(lem, tab[0]) == 0) || (check_name(lem, tab[1]) == 0))
	{
		free_tab(tab);
		return (-1);
	}
	if (check_name_and_double_connexion(lem, tab) == 1)
		return (-1);
	lst_push_back_con(&lem->con, tab);
	free_tab(tab);
	ugly_one(lem, str);
	return (0);
}
