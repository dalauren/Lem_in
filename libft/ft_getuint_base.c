/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:28:59 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:29:09 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*append_char(char *str, char c)
{
	char *ret;

	if (!(ret = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	ret = ft_strcpy(ret, str);
	ret[ft_strlen(str)] = c;
	free(str);
	str = ret;
	return (str);
}

static char		*init(int base)
{
	char *ret;

	if (base < 2 || base > 16)
		return (NULL);
	if (!(ret = ft_strnew(0)))
		return (NULL);
	return (ret);
}

char			*ft_getuint_base(uintmax_t nb, int base)
{
	char			*symbol;
	char			*ret;

	if (!nb)
		return (ft_strdup("0"));
	if (!(symbol = ft_strdup("0123456789abcdef")))
		return (NULL);
	if (!(ret = init(base)))
		return (NULL);
	while (nb)
	{
		if (!(ret = append_char(ret, symbol[nb % base])))
			return (NULL);
		nb /= base;
	}
	free(symbol);
	return (ft_strrev(ret));
}
