/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_big_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:47 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:34:48 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_big_x(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	uintmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'X');
	nb = get_cast_x(flags.cast, ap);
	if (!(ret->str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_getuint_base(nb, 16)))
		return (NULL);
	if (!precision(flags, &tmp))
		return (NULL);
	if (!(hashtag_x(flags, &ret->str, nb)))
		return (NULL);
	if (!(padding_x(flags, &ret->str, tmp)))
		return (NULL);
	ret->str = ft_strtoupper(ret->str);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
