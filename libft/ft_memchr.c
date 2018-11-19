/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:56:24 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 08:16:05 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;

	src = (unsigned char*)s;
	while (n > 0 && *src != (unsigned char)c)
	{
		src++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return ((void*)src);
}
