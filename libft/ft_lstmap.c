/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:55:42 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 08:15:45 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *element))
{
	t_list *new;
	t_list *new_first;

	new_first = ft_lstnew(lst->content, lst->content_size);
	if (!new_first)
		return (NULL);
	new_first = f(lst);
	new = new_first;
	while (lst->next)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (new_first);
}
