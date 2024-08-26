/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:11:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 02:54:28 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	start;

	i = ft_strlen(dst);
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	start = i;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i - start])
		{
			dst[i] = src[i - start];
			i++;
		}
		dst[i] = '\0';
	}
	return (start + ft_strlen(src));
}
