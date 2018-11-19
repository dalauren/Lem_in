/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:57:03 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 16:18:56 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < len)
	{
		if (d < s)
			d[i] = s[i];
		if (d > s)
			d[len - i - 1] = s[len - i - 1];
		i++;
	}
	return (dst);
}
