/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:58:38 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:58:39 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision_s(t_flags flags, char **print)
{
	int		len;
	char	*tmp;

	if (!flags.precision && !flags.prec_specified)
		return (1);
	len = flags.precision;
	if (!(tmp = ft_strnew(len)))
		return (0);
	ft_strncpy(tmp, *print, len);
	free(*print);
	*print = tmp;
	return (1);
}

static int	get_cast_s(char *cast, va_list ap, char **ret)
{
	wchar_t *tmp;
	char	*tmp2;
	char	*unicode_tmp;
	int		i;

	if (!ft_strncmp(cast, "l", 1))
	{
		if (!(tmp = va_arg(ap, wchar_t*)))
			return (-1);
		if (!(*ret = ft_strnew(0)))
			return (0);
		i = -1;
		while (tmp[++i])
		{
			if (!(unicode_tmp = ft_wchar_to_charptr(tmp[i])))
				return (0);
			if (!(*ret = ft_strjoinfree(*ret, unicode_tmp)))
				return (0);
		}
		return (1);
	}
	if (!(tmp2 = va_arg(ap, char*)))
		return (-1);
	return (!(*ret = ft_strdup(tmp2))) ? 0 : 1;
}

t_toprint	*spec_s(const char *format, va_list ap)
{
	t_toprint	*ret;
	t_flags		flags;
	int			nul;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flag_parser(&flags, format, 's');
	if (!(nul = get_cast_s(flags.cast, ap, &ret->str)))
		return (NULL);
	if (nul == -1)
	{
		if (!(ret->str = ft_strdup("(null)")))
			return (NULL);
	}
	if (!(precision_s(flags, &ret->str)))
		return (NULL);
	if (!(padding(flags, &ret->str, 0)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
