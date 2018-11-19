/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_big_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:14 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:23:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_cast_big_c(va_list ap, char **ret)
{
	wint_t tmp;

	tmp = va_arg(ap, wint_t);
	if (!(*ret = ft_wchar_to_charptr(tmp)))
		return (0);
	return (1);
}

t_toprint	*spec_big_c(const char *format, va_list ap)
{
	t_toprint	*ret;
	t_flags		flags;
	int			null_chr;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	null_chr = 0;
	flag_parser(&flags, format, 'C');
	if (!(get_cast_big_c(ap, &(ret->str))))
		return (NULL);
	if (!ret->str[0])
		null_chr = 1;
	if (!(padding_c(flags, &ret->str, 0, null_chr)))
		return (NULL);
	ret->len = ft_strlen(ret->str) + null_chr;
	return (ret);
}
