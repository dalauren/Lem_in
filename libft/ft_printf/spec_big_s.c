/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_big_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:32 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/30 16:09:41 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*unicode_prec(t_flags flags, wchar_t *unicodes)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(0)))
		return (NULL);
	while (unicodes[i])
	{
		if (!(tmp = ft_wchar_to_charptr(unicodes[i])))
			return (NULL);
		if (((int)(ft_strlen(ret) + ft_strlen(tmp)) >
					flags.precision) && (flags.prec_specified))
			return (ret);
		if (!(ret = ft_strjoinfree(ret, tmp)))
			return (NULL);
		i++;
	}
	return (ret);
}

static int	get_cast_big_s(va_list ap, char **ret, t_flags flags)
{
	wchar_t *tmp;

	if (!(tmp = va_arg(ap, wchar_t*)))
	{
		if (!(*ret = ft_strdup("(null)")))
			return (0);
		return (1);
	}
	if (!(*ret = unicode_prec(flags, tmp)))
		return (0);
	return (1);
}

t_toprint	*spec_big_s(const char *format, va_list ap)
{
	t_toprint	*ret;
	t_flags		flags;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	flag_parser(&flags, format, 'S');
	if (!(get_cast_big_s(ap, &ret->str, flags)))
		return (NULL);
	if (!(precision_s(flags, &ret->str)))
		return (NULL);
	if (!(padding(flags, &ret->str, 0)))
		return (NULL);
	ret->len = ft_strlen(ret->str);
	return (ret);
}
