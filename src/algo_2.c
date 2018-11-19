/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:56:38 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 13:50:59 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room				*find_node(t_lem *lem, char *name)
{
	t_room *tmp;

	tmp = ROOM;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

static int			check_end(t_lists *lists, t_lem *lem)
{
	t_lists *tmp;

	tmp = lists;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, L->name_end) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int			check_list(t_lists *list, char *str)
{
	int		i;
	t_lists	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int					find_road(t_lem *lem, t_room *room, t_lists **list_move)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = NULL;
	room->visited = 1;
	while (i < room->connex)
	{
		tmp = find_node(lem, room->neigh[i]);
		if (tmp->visited == 0 && (check_list(*list_move, tmp->name) == 0))
			lst_push_back_l(list_move, room->neigh[i]);
		if (tmp->visited == 0 && tmp->distance == 0 &&
				(ft_strcmp(tmp->name, L->name_start) != 0))
			tmp->distance = lem->distance_from_start + 1;
		if (check_end(*list_move, lem) == 1)
			return (1);
		i++;
	}
	lem->distance_from_start++;
	free_node(list_move);
	if (move_list(lem, tmp, list_move) == -1)
		return (-1);
	return (0);
}

int					do_algo(t_lem *lem, t_room *start)
{
	t_lists		*list_move;

	list_move = NULL;
	lem->distance_from_start = 0;
	start->distance = 0;
	lst_push_back_l(&list_move, start->name);
	if (find_road(lem, start, &list_move) == -1)
		return (-1);
	free_lists(list_move);
	if (get_road(lem) == -1)
		return (-1);
	return (0);
}
