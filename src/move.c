/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:45:48 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 13:53:15 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*create_elem(char *str, int x, int y)
{
	t_room *new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_room))))
		return (NULL);
	if (!(new_elem->name = ft_strdup(str)))
		return (NULL);
	new_elem->x = x;
	new_elem->y = y;
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_front(t_room **begin_list, char *str, int x, int y)
{
	t_room *list;

	if (*begin_list)
	{
		list = create_elem(str, x, y);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = create_elem(str, x, y);
}

void		lst_push_back(t_room **begin_list, char *str, int x, int y)
{
	t_room *list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_elem(str, x, y);
	}
	else
		*begin_list = create_elem(str, x, y);
}
