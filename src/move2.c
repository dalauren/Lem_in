/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:42:38 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:14:30 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map		*create_elem_map(char **tab)
{
	t_map *new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(new_elem->tab = cpy_tab(tab)))
		return (NULL);
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_front_map(t_map **begin_list, char **tab)
{
	t_map *list;

	if (*begin_list)
	{
		list = create_elem_map(tab);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = create_elem_map(tab);
}

void		lst_push_back_map(t_map **begin_list, char **tab)
{
	t_map *list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_elem_map(tab);
	}
	else
		*begin_list = create_elem_map(tab);
}

t_lists		*create_elem_l(char *name)
{
	t_lists *new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_lists))))
		return (NULL);
	if (!(new_elem->name = ft_strdup(name)))
		return (NULL);
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_back_l(t_lists **begin_list, char *name)
{
	t_lists *list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_elem_l(name);
	}
	else
		*begin_list = create_elem_l(name);
}
