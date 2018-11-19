/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:01:59 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/30 20:22:10 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	begin;
	unsigned int	end;

	i = 0;
	begin = 0;
	end = 0;
	if (s)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		begin = i;
		while (s[i])
		{
			if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				end = i;
			i++;
		}
		return (ft_strsub(s, begin, (size_t)(end - begin + 1)));
	}
	return (NULL);
}
