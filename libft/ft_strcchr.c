/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:10:21 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:10:22 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcchr(const char *s, int c, int end)
{
	unsigned int i;

	i = 0;
	while (s[i] && s[i] != end)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}
