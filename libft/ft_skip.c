/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:01:47 by dalauren          #+#    #+#             */
/*   Updated: 2018/01/22 18:12:50 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip(char *str, char *to_skip)
{
	int i;
	int j;
	int is_present;

	i = -1;
	while (str[++i])
	{
		j = -1;
		is_present = 0;
		while (to_skip[++j])
			is_present = (to_skip[j] == str[i]) ? 1 : is_present;
		if (!(is_present))
			break ;
	}
	return (str + i);
}
