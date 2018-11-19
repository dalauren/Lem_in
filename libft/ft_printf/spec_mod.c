/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:17 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:19 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*spec_mod(const char *format, va_list ap)
{
	t_toprint	*ret;
	t_flags		flags;

	(void)ap;
	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flag_parser(&flags, format, '%');
	if (!(ret->str = ft_strnew(1)))
		return (NULL);
	ret->str[0] = '%';
	if (!(padding(flags, &ret->str, 0)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
