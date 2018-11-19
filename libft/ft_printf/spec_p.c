/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:32 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	zero_x(char **print)
{
	if (!(*print = ft_strdup("0x")))
		return (0);
	return (1);
}

t_toprint	*spec_p(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	uintmax_t	addr;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'p');
	flags.hashtag = 1;
	addr = va_arg(ap, uintmax_t);
	if (!(zero_x(&ret->str)))
		return (NULL);
	if (!(tmp = ft_getuint_base(addr, 16)))
		return (NULL);
	if (!precision(flags, &tmp))
		return (NULL);
	if (!(padding_x(flags, &ret->str, tmp)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
