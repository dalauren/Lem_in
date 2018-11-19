/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_big_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:26 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:27:26 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_big_o(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	intmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'O');
	nb = va_arg(ap, unsigned long long int);
	if (!(ret->str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_getuint_base(nb, 8)))
		return (NULL);
	if (!precision_o(flags, &tmp))
		return (NULL);
	if (!(hashtag_o(flags, &ret->str, nb)))
		return (NULL);
	if (!(padding_o(flags, &ret->str, tmp)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
