/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:35:10 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 13:25:51 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_node(t_lists **batman)
{
	t_lists *robin;

	if (batman)
	{
		robin = (*batman)->next;
		free((*batman)->name);
		free(*batman);
		*batman = robin;
	}
}

static char		*check_distance(t_lem *lem, t_room *room)
{
	t_room	*tmp;
	char	*str;
	int		distance;
	int		i;

	i = 0;
	distance = room->distance;
	while (i < room->connex)
	{
		tmp = find_node(lem, room->neigh[i]);
		if (tmp->distance < distance && tmp->visited == 1)
		{
			distance = tmp->distance;
			str = tmp->name;
		}
		i++;
	}
	return (str);
}

static void		display_map(t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (tmp)
	{
		read_tab(tmp->tab);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int				get_road(t_lem *lem)
{
	t_room	*tmp;
	t_lists	*road;
	char	*name;

	road = NULL;
	tmp = find_node(lem, L->name_end);
	while (ft_strcmp(tmp->name, L->name_start) != 0)
	{
		name = check_distance(lem, tmp);
		lst_push_front_l(&road, name);
		tmp = find_node(lem, name);
	}
	lst_push_back_l(&road, L->name_end);
	display_map(lem->map);
	if (move_ant(&road, lem) == -1)
		return (-1);
	free_lists(road);
	return (0);
}
