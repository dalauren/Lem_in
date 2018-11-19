/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:08 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 14:26:58 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			padding(t_flags flags, char **print, int sign_len)
{
	char	fill;
	char	*tmp;
	int		printlen;

	printlen = ft_strlen(*print);
	if (flags.padding <= printlen)
		return (1);
	fill = ' ';
	if (flags.zero && !flags.precision && !flags.minus)
		fill = '0';
	if (!(tmp = ft_strnew(flags.padding - sign_len)))
		return (0);
	ft_memset(tmp, fill, flags.padding - (printlen + sign_len));
	*print = (flags.minus) ? ft_strjoinfree(*print, tmp) :
		ft_strjoinfree(tmp, *print);
	return (*print != NULL);
}

int			precision(t_flags flags, char **print)
{
	char	*tmp;
	int		printlen;

	printlen = ft_strlen(*print);
	if (!flags.precision && flags.prec_specified && (*print[0] == '0'))
	{
		free(*print);
		return ((*print = ft_strnew(0)) != NULL);
	}
	if (flags.precision <= printlen)
		return (1);
	if (!(tmp = ft_strnew(flags.precision - printlen)))
		return (0);
	ft_memset(tmp, '0', flags.precision - printlen);
	*print = ft_strjoinfree(tmp, *print);
	return (*print != NULL);
}
