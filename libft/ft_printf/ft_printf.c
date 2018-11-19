/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:57:00 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:22:59 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_toprint	*apply_format(const char *format, va_list ap,
		int *format_idx, t_convert *conv)
{
	int			i;
	int			j;
	t_toprint	*formated;

	j = ft_skip(format, "hljz #0+-.123456789") - format;
	i = 0;
	while (conv[i].fun)
	{
		if (format[j] == conv[i].flag)
		{
			if (!(formated = conv[i].fun(format, ap)))
				return (NULL);
			*format_idx += j + 2;
			return (formated);
		}
		++i;
	}
	if (format[j])
	{
		formated = spec_undefined(format);
		*format_idx += j + 2;
		return (formated);
	}
	*format_idx += j + 1;
	return (newtoprint());
}

static int			append_to_print(t_toprint **toprint,
		t_toprint **tmp, const char *start, const char *i)
{
	(**tmp).len = i - start;
	(**tmp).str = (char*)start;
	if (!(toprintcat(toprint, *tmp, 0)))
		return (0);
	free(*tmp);
	return (1);
}

static int			init(t_toprint **toprint,
		t_toprint **tmp, int *i, int *start)
{
	*i = 0;
	*start = 0;
	if (!(*toprint = newtoprint()))
		return (0);
	if (!(*tmp = (t_toprint*)malloc(sizeof(t_toprint))))
		return (0);
	return (1);
}

static t_toprint	*put_formated_str(const char *format,
		va_list ap, t_convert *conv)
{
	int			i;
	int			start;
	int			ret;
	t_toprint	*toprint;
	t_toprint	*tmp;

	if (!(init(&toprint, &tmp, &i, &start)))
		return (NULL);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = append_to_print(&toprint, &tmp, format + start, format + i);
			if (!(tmp = apply_format(format + i + 1, ap, &i, conv)) || !ret)
				return (NULL);
			if (!(toprintcat(&toprint, tmp, 1)))
				return (NULL);
			start = i;
		}
		else
			++i;
	}
	ret = append_to_print(&toprint, &tmp, format + start, format + i);
	return ((ret) ? toprint : NULL);
}

int					ft_printf(const char *format, ...)
{
	int			printed;
	t_toprint	*ret;
	t_convert	*conv;
	va_list		ap;

	if (!(conv = conv_init()))
		return (-1);
	va_start(ap, format);
	if (!(ret = put_formated_str(format, ap, conv)))
		return (-1);
	va_end(ap);
	printed = ret->len;
	ft_putnstrlen(ret->str, ret->len);
	free(ret->str);
	free(ret);
	free(conv);
	return (printed);
}
