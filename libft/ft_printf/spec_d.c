/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:02 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:03 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	sign_d(t_flags flags, char **print, intmax_t nb)
{
	if (nb < 0)
		*print = ft_strdup("-");
	else if (flags.plus)
		*print = ft_strdup("+");
	else if (flags.space)
		*print = ft_strdup(" ");
	else
		*print = ft_strnew(0);
	if (!print)
		return (-1);
	return ((nb < 0) ? -nb : nb);
}

intmax_t	get_cast_d(const char *cast, va_list ap, char spec)
{
	int i;

	i = 0;
	if (ft_strcchr(cast, 'h', spec) && ft_strcchr(cast, 'l', spec))
		i++;
	if (!ft_strncmp(cast + i, "hh", 2))
		return ((signed char)va_arg(ap, int));
	if (!ft_strncmp(cast + i, "h", 1))
		return ((short)va_arg(ap, int));
	if (!ft_strncmp(cast + i, "ll", 2))
		return (va_arg(ap, long long));
	if (!ft_strncmp(cast + i, "l", 1))
		return (va_arg(ap, long));
	if (!ft_strncmp(cast + i, "j", 1))
		return (va_arg(ap, intmax_t));
	if (!ft_strncmp(cast + i, "z", 1))
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

int			padding_d(t_flags flags, char **print, char *tmp)
{
	if (flags.zero && !flags.precision)
	{
		if (!padding(flags, &tmp, ft_strlen(*print)))
			return (1);
		if (!(*print = ft_strjoinfree(*print, tmp)))
			return (1);
	}
	else
	{
		if (!(*print = ft_strjoinfree(*print, tmp)))
			return (1);
		if (!padding(flags, print, 0))
			return (1);
	}
	return (1);
}

t_toprint	*spec_d(const char *format, va_list ap)
{
	t_flags		flags;
	char		*tmp;
	intmax_t	nb;
	t_toprint	*ret;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'd');
	nb = get_cast_d(flags.cast, ap, 'd');
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
