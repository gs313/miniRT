/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:34:23 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 08:09:22 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	word_length(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
			s++;
			l++;
	}
	return (l);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*wordcpy(char const *s, char c)
{
	size_t	wl;
	char	*temp;

	wl = word_length(s, c);
	temp = malloc((wl + 1) * sizeof(char));
	ft_memcpy(temp, s, wl);
	temp[wl] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	wc;
	size_t	ac;

	if (s == NULL)
		return (NULL);
	wc = word_count(s, c);
	ans = malloc (sizeof(char *) * (wc + 1));
	if (!ans)
		return (NULL);
	ac = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			ans[ac] = wordcpy(s, c);
			ac++;
		}
		while (*s != c && *s)
			s++;
	}
	ans[wc] = NULL;
	return (ans);
}
