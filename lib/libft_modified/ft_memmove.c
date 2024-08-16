/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:48:54 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/19 22:08:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
		while (len-- > 0)
			*d++ = *s++;
	return (dst);
}
