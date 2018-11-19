/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:47:58 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 14:03:49 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room		*get_start_room(t_lem *lem)
{
	t_room		*tmp;

	tmp = ROOM;
	while (tmp)
	{
		if (ft_strcmp(START, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	tmp->ant = L->nb_ant;
	return (0);
}

int					move_list(t_lem *lem, t_room *room, t_lists **list_move)
{
	while (*list_move)
	{
		room = find_node(lem, (*list_move)->name);
		if (find_road(lem, room, list_move) == -1)
			return (-1);
		else
			return (0);
		*list_move = (*list_move)->next;
	}
	if (!*list_move)
		return (-1);
	return (0);
}

int					start_algo(t_lem **lem)
{
	t_room *start;

	if (!(start = get_start_room(*lem)))
		return (-1);
	if (do_algo(*lem, start) == -1)
	{
		ft_putstr("No path available\n");
		exit(0);
	}
	return (0);
}
