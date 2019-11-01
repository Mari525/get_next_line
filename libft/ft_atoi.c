/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:38:22 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					neg;
	unsigned long int	res;
	int					i;

	neg = 1;
	res = 0;
	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (res >= 9223372036854775807 && neg == 1)
			return (-1);
		else if (res > 9223372036854775807 && neg == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * neg));
}
