/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:21:07 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 00:28:06 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (lst == NULL || del == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		(del)(node -> content);
		*lst = node ->next;
		free(node);
		node = *lst;
	}
}
