/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:27:33 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:15:02 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_parse_connex		*create_elem_con(char **tab)
{
	t_parse_connex *new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_parse_connex))))
		return (NULL);
	if (!(new_elem->tab = cpy_tab(tab)))
		return (NULL);
	new_elem->next = NULL;
	return (new_elem);
}

void				lst_push_front_con(t_parse_connex **begin_list, char **tab)
{
	t_parse_connex *list;

	if (*begin_list)
	{
		list = create_elem_con(tab);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = create_elem_con(tab);
}

void				lst_push_back_con(t_parse_connex **begin_list, char **tab)
{
	t_parse_connex *list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_elem_con(tab);
	}
	else
		*begin_list = create_elem_con(tab);
}

void				lst_push_front_l(t_lists **begin_list, char *str)
{
	t_lists *list;

	if (*begin_list)
	{
		list = create_elem_l(str);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = create_elem_l(str);
}
