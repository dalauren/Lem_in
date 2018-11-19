/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:09 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:11 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_i(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	intmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'i');
	nb = get_cast_d(flags.cast, ap, 'i');
	if ((nb = sign_d(flags, &ret->str, nb)) == -1)
		return (NULL);
	if (!(tmp = ft_getuint_base(nb, 10)))
		return (NULL);
	if (!precision(flags, &tmp))
		return (NULL);
	if (!(padding_d(flags, &ret->str, tmp)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
