/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:59:37 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 08:01:42 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	check_set(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	b;
	size_t	e;

	if (! s1 || ! set)
		return (NULL);
	b = 0;
	e = ft_strlen(s1) - 1;
	while (check_set(set, s1[b]))
		b++;
	while (check_set(set, s1[e]) && b < e)
		e--;
	ans = malloc(sizeof(char) * (e - b + 2));
	if (!ans)
		return (NULL);
	ft_memcpy(ans, s1 + b, e - b + 1);
	ans[e - b + 1] = '\0';
	return (ans);
}
