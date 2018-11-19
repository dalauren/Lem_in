/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:12:36 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/13 15:45:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_create_elem(void *content, size_t content_size)
{
	t_list *new_elem;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->content = content;
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
