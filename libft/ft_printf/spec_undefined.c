/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_undefined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:55 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:56 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_undefined(const char *format)
{
	char		*print;
	t_flags		flags;
	t_toprint	*ret;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flag_parser(&flags, format, 'c');
	if (!(print = ft_strnew(1)))
		return (NULL);
	*print = *ft_skip(format, "+-0# .123456789hljz");
	if (!(padding_c(flags, &print, 0, 0)))
		return (NULL);
	ret->str = print;
	ret->len = ft_strlen(print);
	return (ret);
}
