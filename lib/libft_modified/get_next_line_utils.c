/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:35 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 14:59:43 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	int		i;
	char	*ans;

	if (!s1 || !s2)
		return (0);
	i = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (NULL);
	ft_memcpy(ans, s1, (size_t)ft_strlen(s1));
	ft_memcpy(ans + (size_t)ft_strlen(s1), s2, (size_t)ft_strlen(s2));
	ans[i] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (ans);
}

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
