/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 11:00:31 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/13 13:25:02 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*create_elem_a(char *name, int id)
{
	t_ant *new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_ant))))
		return (NULL);
	if (!(new_elem->position = ft_strdup(name)))
		return (NULL);
	new_elem->id = id;
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_back_a(t_ant **begin_list, char *name, int id)
{
	t_ant *list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_elem_a(name, id);
	}
	else
		*begin_list = create_elem_a(name, id);
}
