/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:38:10 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 14:38:11 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_toprint
{
	char	*str;
	size_t	len;
}					t_toprint;

typedef t_toprint*	(*t_func)(const char *format, va_list ap);

typedef struct		s_convert
{
	char	flag;
	t_func	fun;
}					t_convert;

typedef struct		s_flags
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hashtag;
	int		padding;
	int		precision;
	int		prec_specified;
	char	*cast;
}					t_flags;
t_convert			*conv_init(void);
t_toprint			*newtoprint(void);
int					toprintcat(t_toprint **tp1, t_toprint *tp2,
		int free_tmpstr);
t_flags				*flag_parser(t_flags *flags, const char *format,
		const char spec);
int					padding(t_flags flags, char **print, int sign_len);
int					precision(t_flags flags, char **print);
int					ft_printf(const char *format, ...);
int					precision_s(t_flags flags, char **print);
intmax_t			sign_d(t_flags flags, char **print, intmax_t nb);
intmax_t			get_cast_d(const char *cast, va_list ap, char spec);
int					padding_d(t_flags flags, char **print, char *tmp);
uintmax_t			get_cast_x(const char *cast, va_list ap);
int					hashtag_x(t_flags flags, char **print, uintmax_t nb);
int					padding_x(t_flags flags, char **print, char *tmp);
int					hashtag_o(t_flags flags, char **print, uintmax_t nb);
int					padding_o(t_flags flags, char **pint, char *tmp);
int					precision_o(t_flags flags, char **print);
int					padding_c(t_flags flags, char **print, int sign_len,
		int nul);

t_toprint			*spec_mod(const char *format, va_list ap);
t_toprint			*spec_c(const char *format, va_list ap);
t_toprint			*spec_s(const char *format, va_list ap);
t_toprint			*spec_d(const char *format, va_list ap);
t_toprint			*spec_i(const char *format, va_list ap);
t_toprint			*spec_x(const char *format, va_list ap);
t_toprint			*spec_u(const char *format, va_list ap);
t_toprint			*spec_o(const char *format, va_list ap);
t_toprint			*spec_p(const char *format, va_list ap);
t_toprint			*spec_big_x(const char *format, va_list ap);
t_toprint			*spec_big_s(const char *format, va_list ap);
t_toprint			*spec_big_u(const char *format, va_list ap);
t_toprint			*spec_big_o(const char *format, va_list ap);
t_toprint			*spec_big_d(const char *format, va_list ap);
t_toprint			*spec_big_c(const char *format, va_list ap);
t_toprint			*spec_undefined(const char *format);

#endif
