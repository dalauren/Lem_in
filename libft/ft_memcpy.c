/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:56:43 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 07:56:45 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *source;
	unsigned char *desti;

	source = (unsigned char *)src;
	desti = (unsigned char *)dst;
	while (n > 0)
	{
		*desti = *source;
		desti++;
		source++;
		n--;
	}
	return (dst);
}
