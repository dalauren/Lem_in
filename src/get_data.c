/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:47 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 16:59:57 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					size_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char			*find_start(t_map *map)
{
	t_map *tmp;

	tmp = map;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->tab[0][0] == '#')
			tmp = tmp->next;
		else
			return (tmp->tab[0]);
	}
	return (0);
}

static void			get_other_name(t_lem *lem, t_map *tmp)
{
	if (tmp->next)
		lem->tmp2 = tmp->next;
	if (L->name_start == NULL && (ft_strcmp(tmp->tab[0], "##start") == 0))
	{
		L->name_start = find_start(tmp);
		L->found_start = 1;
	}
	else if (L->name_end == NULL && (ft_strcmp(tmp->tab[0], "##end") == 0))
	{
		L->name_end = find_start(tmp);
		L->found_end = 1;
	}
	if (size_tab(tmp->tab) == 3)
	{
		lem->x = ft_atoi(tmp->tab[1]);
		lem->y = ft_atoi(tmp->tab[2]);
		lst_push_back(&ROOM, tmp->tab[0], lem->x, lem->y);
		if (L->found_start == 1)
			L->found_start = 0;
		if (L->found_end == 1)
			L->found_end = 0;
		L->nb_room++;
	}
}

static int			get_name_pos(t_lem *lem)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = L->map;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->next)
			tmp2 = tmp->next;
		get_other_name(lem, tmp);
		tmp = tmp->next;
	}
	return (0);
}

int					start_getting_data(t_lem **lem)
{
	if (get_name_pos(*lem) == -1)
		return (-1);
	if (ft_strchr((*L)->name_start, '-') != NULL ||
			ft_strchr((*L)->name_end, '-') != NULL ||
			ft_strcmp((*L)->name_start, (*L)->name_end) == 0)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	if (get_connexion(*lem) == -1)
		return (-1);
	return (0);
}
