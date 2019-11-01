/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:30:41 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int	words;
	int space;
	int i;

	words = 0;
	space = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && space == 1)
		{
			words++;
			space = 0;
		}
		else if (str[i] == c)
			space = 1;
		i++;
	}
	return (words);
}
