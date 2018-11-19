/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:24 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:26 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			hashtag_o(t_flags flags, char **print, uintmax_t nb)
{
	if (!flags.hashtag || (!flags.precision && flags.prec_specified &&
				!flags.hashtag) || !nb || flags.precision)
		return (1);
	free(*print);
	if (!(*print = ft_strdup("0")))
		return (0);
	return (1);
}

int			padding_o(t_flags flags, char **print, char *tmp)
{
	if (flags.zero && !flags.precision)
	{
		if (!(padding(flags, &tmp, ft_strlen(*print))))
			return (0);
		if (!(*print = ft_strjoinfree(*print, tmp)))
			return (0);
	}
	else
	{
		if (!(*print = ft_strjoinfree(*print, tmp)))
			return (0);
		if (!(padding(flags, print, 0)))
			return (0);
	}
	return (1);
}

int			precision_o(t_flags flags, char **print)
{
	char	*tmp;
	int		printlen;

	printlen = ft_strlen(*print);
	if (!flags.precision && flags.prec_specified && (*print[0] == '0')
			&& !flags.hashtag)
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

t_toprint	*spec_o(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	intmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'o');
	nb = get_cast_x(flags.cast, ap);
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
