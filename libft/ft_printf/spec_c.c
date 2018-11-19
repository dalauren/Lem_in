/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:54 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:57:55 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			padding_c(t_flags flags, char **print, int sign_len, int nul)
{
	char	fill;
	char	*tmp;
	int		printlen;

	printlen = ft_strlen(*print) + nul;
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

static int	get_cast_c(char *cast, va_list ap, char **ret)
{
	wint_t tmp;

	if (!ft_strncmp(cast, "l", 1))
	{
		tmp = va_arg(ap, wint_t);
		if (!(*ret = ft_wchar_to_charptr(tmp)))
			return (0);
		return (1);
	}
	if (!(*ret = (char*)malloc(sizeof(char))))
		return (0);
	**ret = (char)va_arg(ap, int);
	return (1);
}

t_toprint	*spec_c(const char *format, va_list ap)
{
	t_toprint	*ret;
	t_flags		flags;
	int			null_chr;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	null_chr = 0;
	flag_parser(&flags, format, 'c');
	if (!(get_cast_c(flags.cast, ap, &(ret->str))))
		return (NULL);
	if (!ret->str[0])
		null_chr = 1;
	if (!(padding_c(flags, &ret->str, 0, null_chr)))
		return (NULL);
	ret->len = ft_strlen(ret->str) + null_chr;
	return (ret);
}
