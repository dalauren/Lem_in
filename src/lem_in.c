/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:05:36 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:49:16 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			start_end(t_lem *lem, char *str)
{
	char **tab;

	if (!(tab = ft_strsplit(str, ' ')))
		return (-1);
	if ((ft_strcmp(str, "##start") == 0 && L->start == 1) ||
			((ft_strcmp(str, "##end") == 0) && L->end == 1))
		return (-1);
	if ((ft_strcmp(str, "##start") == 0) || (ft_strcmp(str, "##end") == 0))
	{
		L->start = (ft_strcmp(str, "##start") == 0) ? 1 : L->start;
		L->end = (ft_strcmp(str, "##end") == 0) ? 1 : L->end;
		lst_push_back_map(&lem->map, tab);
		free_tab(tab);
	}
	else
		free_tab(tab);
	return (0);
}

int					check_data_room(t_lem *lem, char *str)
{
	char **tab;

	tab = NULL;
	if (!(tab = ft_strsplit(str, ' ')))
		return (-1);
	if (check_tab(tab, lem) == -1)
	{
		free_tab(tab);
		return (-1);
	}
	lst_push_back_map(&lem->map, tab);
	free_tab(tab);
	return (0);
}

static int			first_turn(t_lem *lem, char *str)
{
	char **tab;

	tab = NULL;
	if (check_nb_ant(lem, str) == -1)
		return (-1);
	if (L->nb_ant == 0)
		return (-1);
	if (!(tab = ft_strsplit(str, ' ')))
		return (-1);
	lst_push_back_map(&lem->map, tab);
	free_tab(tab);
	return (0);
}

static int			get_parse(t_lem **lem, char *str)
{
	char **tab;

	tab = NULL;
	if ((*lem)->turn == 0 && str[0] != '#')
	{
		if (first_turn(*lem, str) == -1)
			return (-1);
	}
	if (comment_or_unknowed_commend(str) == 1)
	{
		(*lem)->nb_comment++;
		if (!(tab = ft_strsplit(str, ' ')))
			return (-1);
		lst_push_back_map(&(*lem)->map, tab);
		free_tab(tab);
		return (0);
	}
	if (start_end(*lem, str) == -1)
		return (-1);
	if (get_parse_2(lem, str) == -1)
		return (-1);
	return (0);
}

int					main(void)
{
	t_lem	*lem;
	char	*line;
	int		ret;

	if (!(lem = ft_memalloc(sizeof(t_lem))))
		return (-1);
	while ((ret = get_next_line(0, &line)) && ret > -1)
	{
		if (line[0] == '\0' || !ret)
			break ;
		if (get_parse(&lem, line) == -1)
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		(line[0] != '#') ? lem->turn++ : lem->turn;
		free(line);
	}
	if (main_algo(lem) == -1)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	free_all(&lem);
	return (0);
}
