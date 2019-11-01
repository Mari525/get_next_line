/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:16:40 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_fill_array(char const *s, char c, char **res)
{
	int			begin;
	int			end;
	int			i;

	end = 0;
	i = 0;
	while (s[end])
	{
		begin = end;
		while (s[begin] == c && s[begin] != '\0')
			begin++;
		end = begin;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (end - begin != 0)
		{
			if (!(res[i++] = ft_words_malloc((char *)s + begin, end - begin)))
			{
				ft_free_array(res, i);
				return (NULL);
			}
		}
	}
	res[i] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	int			words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	res = ft_fill_array(s, c, res);
	return (res);
}
