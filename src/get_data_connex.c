/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_connex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:51:08 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:49:33 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room			*get_first(t_room **room, char *str)
{
	t_room		*tmp;
	int			i;

	tmp = *room;
	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

static void				malloc_tab(t_room **room, t_lem *lem)
{
	t_room	*tmp;
	int		len;

	tmp = *room;
	while (tmp)
	{
		len = L->nb_room;
		if (!(tmp->neigh = (char **)malloc(sizeof(char *) * (len + 1))))
			return ;
		tmp->neigh[len] = NULL;
		while (--len)
			tmp->neigh[len] = NULL;
		tmp = tmp->next;
	}
}

int						get_connexion(t_lem *lem)
{
	t_parse_connex	*tmp;
	t_room			*first;
	t_room			*second;

	malloc_tab(&ROOM, lem);
	tmp = L->con;
	while (tmp)
	{
		first = get_first(&ROOM, tmp->tab[0]);
		second = get_first(&ROOM, tmp->tab[1]);
		if (!(first->neigh[first->connex] = ft_strdup(second->name)))
			return (-1);
		first->connex++;
		if (!(second->neigh[second->connex] = ft_strdup(first->name)))
			return (-1);
		second->connex++;
		tmp = tmp->next;
	}
	return (0);
}
