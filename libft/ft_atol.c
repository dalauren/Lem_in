/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:36:56 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/03 11:38:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\r') ||
			(c == '\v') || (c == '\f') || (c == ' '))
		return (1);
	return (0);
}

long int	ft_atol(const char *str)
{
	int			i;
	intmax_t	nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (skip(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((nb * 10) < nb)
			return ((sign == 1) ? -1 : 0);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return ((long int)(nb * sign));
}
