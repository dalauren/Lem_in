/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:36:06 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 13:54:48 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		struct_ant(t_lem *lem, t_ant **ant)
{
	t_room	*tmp;
	int		i;

	i = 1;
	tmp = find_node(lem, lem->name_start);
	tmp->ant = lem->nb_ant;
	while (i < lem->nb_ant + 1)
	{
		lst_push_back_a(ant, lem->name_start, i);
		i++;
	}
}

static void		display_ant(t_ant *ant)
{
	t_ant	*tmp;

	tmp = ant;
	while (tmp)
	{
		if (tmp->moved == 1)
		{
			ft_printf("L\033[32m%d\033[0m-\033[33m%s\033[0m ", tmp->id,
				tmp->position);
			tmp->moved = 0;
		}
		if (tmp->next == NULL)
			ft_printf("\n");
		tmp = tmp->next;
	}
}

static t_room	*next_on_the_road(t_lists *road, t_lem *lem, char *str)
{
	t_lists	*tmp_road;
	t_room	*tmp;

	tmp = NULL;
	tmp_road = road;
	while (tmp_road->next)
	{
		if ((ft_strcmp(str, tmp_road->name) == 0))
		{
			tmp = find_node(lem, tmp_road->next->name);
			break ;
		}
		tmp_road = tmp_road->next;
	}
	return (tmp);
}

static void		move_it(t_lem *lem, t_ant *ant, t_lists *road)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = next_on_the_road(road, lem, ant->position);
	if (tmp->ant == 0 || (ft_strcmp(L->name_end, tmp->name) == 0))
	{
		tmp2 = find_node(lem, ant->position);
		tmp2->ant--;
		tmp->ant++;
		ant->moved = 1;
		free(ant->position);
		if (!(ant->position = ft_strdup(tmp->name)))
			return ;
	}
}

int				move_ant(t_lists **road, t_lem *lem)
{
	t_lists	*tmp_road;
	t_room	*end;
	t_ant	*tmp_ant;

	struct_ant(lem, &lem->ant);
	tmp_ant = L->ant;
	tmp_road = *road;
	tmp_ant = L->ant;
	end = find_node(lem, L->name_end);
	while (end->ant < L->nb_ant)
	{
		while (tmp_ant)
		{
			if (ft_strcmp(tmp_ant->position, end->name) != 0)
				move_it(lem, tmp_ant, *road);
			tmp_ant = tmp_ant->next;
		}
		display_ant(L->ant);
		tmp_ant = L->ant;
	}
	return (0);
}
