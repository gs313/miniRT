/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:28:19 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 00:34:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (lst == NULL || f == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		(f)(node -> content);
		node = node -> next;
	}
}
