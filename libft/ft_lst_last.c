/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:42:14 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/22 13:37:18 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_last(t_list *begin_list)
{
	t_list *tmp;

	tmp = begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}
