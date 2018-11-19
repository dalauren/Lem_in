/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_charptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:24:36 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:24:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

static char		*end_split(wchar_t chr)
{
	char *ret;

	ret = NULL;
	if (chr <= 0xFFFF)
	{
		if (!(ret = ft_strnew(3)))
			return (NULL);
		ret[0] = (chr >> 12) + 0xE0;
		ret[1] = ((chr >> 6) & 0x3F) + 0x80;
		ret[2] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0x10FFFF)
	{
		if (!(ret = ft_strnew(4)))
			return (NULL);
		ret[0] = (chr >> 18) + 0xF0;
		ret[1] = ((chr >> 12) & 0x3F) + 0x80;
		ret[2] = ((chr >> 6) & 0x3F) + 0x80;
		ret[3] = (chr & 0x3F) + 0x80;
	}
	return (ret);
}

char			*ft_wchar_to_charptr(wchar_t chr)
{
	char *ret;

	ret = NULL;
	if (chr <= 0x7F)
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		ret[0] = chr;
	}
	else if (chr <= 0x7FF)
	{
		if (!(ret = ft_strnew(2)))
			return (NULL);
		ret[0] = (chr >> 6) + 0xC0;
		ret[1] = (chr & 0x3F) + 0x80;
	}
	else
		ret = end_split(chr);
	return (ret);
}
