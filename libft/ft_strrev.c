/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:31:27 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/22 12:31:29 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str) - 1;
	while (++i <= (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}
	return (str);
}
