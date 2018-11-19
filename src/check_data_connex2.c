/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_connex2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:58:37 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 14:01:20 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_name_and_double_connexion(t_lem *lem, char **tab)
{
	if (check_same_name_connexion(tab) == -1)
	{
		free_tab(tab);
		return (-1);
	}
	if (check_double_connexion(lem, tab) == -1)
	{
		free_tab(tab);
		return (-1);
	}
	return (0);
}
