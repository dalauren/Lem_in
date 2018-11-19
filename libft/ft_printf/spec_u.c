/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:47 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:49 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_u(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	intmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'u');
	nb = get_cast_x(flags.cast, ap);
	if (!(ret->str = ft_getuint_base(nb, 10)))
		return (NULL);
	if (!precision(flags, &ret->str))
		return (NULL);
	if (!(padding(flags, &ret->str, 0)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
