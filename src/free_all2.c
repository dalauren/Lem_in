/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:29:16 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:48:23 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_ant(t_ant *ant)
{
	t_ant *batman;
	t_ant *robin;

	batman = ant;
	while (batman)
	{
		robin = batman->next;
		free(batman->position);
		free(batman);
		batman = robin;
	}
	ant = NULL;
}

void	free_tab_neigh(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
