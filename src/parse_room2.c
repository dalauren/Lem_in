/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:06:32 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 13:55:00 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main_algo(t_lem *lem)
{
	if (L->start == 0 || L->end == 0 || !L->con)
		return (-1);
	if (start_getting_data(&lem) == -1)
		return (-1);
	if (start_algo(&lem) == -1)
		return (-1);
	return (0);
}

int			comment_or_unknowed_commend(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (str[0] == '#' && str[1] == '#' && ft_strcmp("##start", str) != 0
			&& ft_strcmp("##end", str) != 0)
		return (1);
	return (0);
}

int			check_same_name_room(t_lem *lem, char **tab)
{
	t_map	*tmp;
	int		s1;
	int		s2;

	tmp = L->map;
	s1 = size_tab(tab);
	while (tmp)
	{
		s2 = size_tab(tmp->tab);
		if ((ft_strcmp(tab[0], tmp->tab[0]) == 0) && (s1 == s2))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
