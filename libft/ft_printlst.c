/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:57:22 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 11:00:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *list)
{
	t_list *l;

	l = list;
	while (l)
	{
		ft_putstr(l->content);
		ft_putchar('\n');
		l = l->next;
	}
}
