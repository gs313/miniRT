/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:00:11 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 00:05:01 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*node;

	size = 0;
	node = lst;
	while (node != NULL)
	{
		node = node -> next;
		size++;
	}
	return (size);
}
