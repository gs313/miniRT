/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:34:21 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 09:32:24 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*anext;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	ans = ft_lstnew(f(lst -> content));
	if (!ans)
		return (NULL);
	anext = ans;
	next = lst -> next;
	while (next != NULL)
	{
		anext -> next = ft_lstnew(f(next -> content));
		if (!anext)
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		next = next -> next;
		anext = anext -> next;
	}
	return (ans);
}
