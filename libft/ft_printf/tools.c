/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:59:09 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 11:59:10 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_init_flag(t_convert *conv)
{
	conv[0].flag = 'c';
	conv[1].flag = '%';
	conv[2].flag = 's';
	conv[3].flag = 'd';
	conv[4].flag = 'i';
	conv[5].flag = 'x';
	conv[6].flag = 'X';
	conv[7].flag = 'u';
	conv[8].flag = 'o';
	conv[9].flag = 'S';
	conv[10].flag = 'U';
	conv[11].flag = 'O';
	conv[12].flag = 'D';
	conv[13].flag = 'C';
	conv[14].flag = 'p';
}

static void	conv_init_fun(t_convert *conv)
{
	conv[0].fun = &spec_c;
	conv[1].fun = &spec_mod;
	conv[2].fun = &spec_s;
	conv[3].fun = &spec_d;
	conv[4].fun = &spec_i;
	conv[5].fun = &spec_x;
	conv[6].fun = &spec_big_x;
	conv[7].fun = &spec_u;
	conv[8].fun = &spec_o;
	conv[9].fun = &spec_big_s;
	conv[10].fun = &spec_big_u;
	conv[11].fun = &spec_big_o;
	conv[12].fun = &spec_big_d;
	conv[13].fun = &spec_big_c;
	conv[14].fun = &spec_p;
	conv[15].fun = NULL;
}

t_convert	*conv_init(void)
{
	t_convert *conv;

	if (!(conv = (t_convert*)malloc(sizeof(t_convert) * 16)))
		return (NULL);
	conv_init_flag(conv);
	conv_init_fun(conv);
	return (conv);
}

t_toprint	*newtoprint(void)
{
	t_toprint	*ret;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (NULL);
	if (!(ret->str = ft_strnew(0)))
		return (NULL);
	ret->len = 0;
	return (ret);
}

int			toprintcat(t_toprint **tp1, t_toprint *tp2, int free_tmpstr)
{
	t_toprint *ret;

	if (!(ret = (t_toprint*)malloc(sizeof(t_toprint))))
		return (0);
	ret->len = (*tp1)->len + tp2->len;
	if (!(ret->str = ft_strnew(ret->len)))
		return (0);
	ft_strncpy(ret->str, (*tp1)->str, (*tp1)->len);
	ft_strncpy(ret->str + (*tp1)->len, tp2->str, tp2->len);
	free((*tp1)->str);
	free((*tp1));
	if (free_tmpstr)
		free(tp2->str);
	(*tp1) = ret;
	return (1);
}
