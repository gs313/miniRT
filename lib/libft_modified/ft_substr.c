/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:14:57 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 14:52:20 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	reallen;

	if (s == NULL)
		return (NULL);
	reallen = len;
	if (start > ft_strlen(s))
		reallen = 0;
	else if (ft_strlen(s) - start < len)
		reallen = ft_strlen(s) - start;
	ans = malloc(sizeof(char) * (reallen + 1));
	if (!ans || ans == NULL)
		return (NULL);
	if (!ans)
		return (NULL);
	ans = ft_memcpy(ans, (s + start), reallen);
	ans[reallen] = '\0';
	return (ans);
}
