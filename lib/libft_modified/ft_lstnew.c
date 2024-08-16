/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:49:21 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/19 23:53:58 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = malloc (sizeof(t_list));
	if (!ans)
		return (NULL);
	ans -> content = content;
	ans -> next = NULL;
	return (ans);
}
