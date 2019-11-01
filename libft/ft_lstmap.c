/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:32:21 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/28 11:35:33 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	res = (*f)(lst);
	if (!(res = ft_lstnew(res->content, res->content_size)))
		return (NULL);
	res->next = ft_lstmap(lst->next, f);
	if (!(res->next) && lst->next)
	{
		free(res->content);
		free(res);
		res = NULL;
	}
	return (res);
}
