/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:04:18 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*res;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start + len)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strncpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
