/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:44:51 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest_char;
	unsigned char	*src_char;
	unsigned char	c_char;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	c_char = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		if (dest_char[i] == c_char)
			return (&((unsigned char *)dest)[i + 1]);
		i++;
	}
	return (NULL);
}
