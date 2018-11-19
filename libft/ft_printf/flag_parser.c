/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:56:54 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:17:49 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_zero(t_flags *flags, char *tmp, const char spec)
{
	if (!flags->zero)
		return (0);
	if (ft_strcchr(tmp, '.', spec))
		return (0);
	return (1);
}

static int	get_prec(t_flags *flags, char *tmp, const char spec)
{
	int prec;
	int dot_count;

	(void)flags;
	prec = 0;
	dot_count = 0;
	while ((tmp = ft_strcchr(tmp, '.', spec)))
	{
		dot_count++;
		prec = ft_atoi(++tmp);
		if (prec && ((dot_count == 1 && spec == 'd') || (spec != 'd')))
			return (prec);
	}
	return (0);
}

t_flags		*flag_parser(t_flags *flags, const char *format, const char spec)
{
	char	*tmp;

	flags->plus = (ft_strcchr(format, '+', spec) != NULL);
	flags->minus = (ft_strcchr(format, '-', spec) != NULL);
	flags->space = (ft_strcchr(format, ' ', spec) != NULL);
	flags->hashtag = (ft_strcchr(format, '#', spec) != NULL);
	flags->prec_specified = (ft_strcchr(format, '.', spec) != NULL);
	tmp = (char*)ft_skip(format, "+- #");
	flags->zero = (*tmp == '0');
	tmp = (char*)ft_skip(format, "0+- #");
	flags->padding = ft_atoi(tmp);
	tmp = (char*)ft_skip(tmp, "0123456789");
	flags->precision = get_prec(flags, tmp, spec);
	if (spec == 'd')
		flags->zero = get_zero(flags, tmp, spec);
	tmp = (char*)ft_skip(tmp, "0123456789");
	flags->cast = tmp;
	return (flags);
}
