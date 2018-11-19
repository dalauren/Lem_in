/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:18:29 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/23 15:20:21 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(const char *src, const size_t begin, const size_t end)
{
	char	*dest;
	size_t	pt;

	if (src == NULL || begin > end)
		return (NULL);
	dest = ft_strnew(end - begin);
	if (dest == NULL)
		return (NULL);
	pt = 0;
	while (pt < (end - begin))
	{
		dest[pt] = src[begin + pt];
		pt++;
	}
	return (dest);
}
