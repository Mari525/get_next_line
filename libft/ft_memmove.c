/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:36:35 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if (!dest && !src)
		return (NULL);
	i = 0;
	csrc = (unsigned char*)src;
	cdest = (unsigned char*)dest;
	if (csrc < cdest)
	{
		while (++i <= n)
			cdest[n - i] = csrc[n - i];
	}
	else
	{
		while (n-- > 0)
			*(cdest++) = *(csrc++);
	}
	return (dest);
}
