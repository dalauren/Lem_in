/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:59:03 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:59:04 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_cast_x(const char *cast, va_list ap)
{
	if (!ft_strncmp(cast, "hh", 2))
		return ((unsigned char)va_arg(ap, int));
	if (!ft_strncmp(cast, "h", 1))
		return ((unsigned short)va_arg(ap, int));
	if (!ft_strncmp(cast, "ll", 2))
		return (va_arg(ap, unsigned long long int));
	if (!ft_strncmp(cast, "l", 1))
		return (va_arg(ap, unsigned long int));
	if (!ft_strncmp(cast, "j", 1))
		return (va_arg(ap, uintmax_t));
	if (!ft_strncmp(cast, "z", 1))
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

int			hashtag_x(t_flags flags, char **print, uintmax_t nb)
{
	if (!flags.hashtag || !nb)
		return (1);
	free(*print);
	if (!(*print = ft_strdup("0x")))
		return (0);
	return (1);
}

int			padding_x(t_flags flags, char **print, char *tmp)
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

t_toprint	*spec_x(const char *format, va_list ap)
{
	t_flags		flags;
	t_toprint	*ret;
	char		*tmp;
	uintmax_t	nb;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flags = *flag_parser(&flags, format, 'x');
	nb = get_cast_x(flags.cast, ap);
	if (!(ret->str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_getuint_base(nb, 16)))
		return (NULL);
	if (!precision(flags, &tmp))
		return (NULL);
	if (!(hashtag_x(flags, &ret->str, nb)))
		return (NULL);
	if (!(padding_x(flags, &ret->str, tmp)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
