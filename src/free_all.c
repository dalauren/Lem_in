/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:54:53 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:48:02 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			free_list_con(t_parse_connex *a)
{
	t_parse_connex *robin;
	t_parse_connex *batman;

	batman = a;
	while (batman)
	{
		free_tab(batman->tab);
		robin = batman->next;
		free(batman);
		batman = robin;
	}
	a = NULL;
}

void				free_lists(t_lists *list)
{
	t_lists *batman;
	t_lists *robin;

	batman = list;
	while (batman)
	{
		free(batman->name);
		robin = batman->next;
		free(batman);
		batman = robin;
	}
	batman = NULL;
}

static void			free_list_map(t_map *a)
{
	t_map *robin;
	t_map *batman;

	batman = a;
	while (batman)
	{
		free_tab(batman->tab);
		robin = batman->next;
		free(batman);
		batman = robin;
	}
	a = NULL;
}

static void			free_list_room(t_room *a)
{
	t_room *robin;
	t_room *batman;

	batman = a;
	while (batman)
	{
		if (batman->name)
			free(batman->name);
		if (batman->neigh)
			free_tab_neigh(batman->neigh);
		robin = batman->next;
		free(batman);
		batman = robin;
	}
	a = NULL;
}

void				free_all(t_lem **lem)
{
	free_list_con((*lem)->con);
	free_list_room((*lem)->lst_room);
	free_list_map((*lem)->map);
	free_ant((*lem)->ant);
	free(*lem);
	*lem = NULL;
}
