/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:47:05 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/17 03:31:54 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <limits.h>
#define SIZE_MAX UINT_MAX

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	a = (void *)malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}