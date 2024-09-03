/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:34:23 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/03 08:16:03 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	**ft_split(char const *str, char c)
// {
// 	int		i = 0, j = 0, k = 0;
// 	char	*word;
// 	char	**splitted;
// 	if (!str)
// 		return (NULL);
// 	splitted = malloc(sizeof(char *) * 5000);
// 	if (!splitted)
// 		return (NULL);
// 	while (str[i] != '\0')
// 	{
// 		while (ft_isspace(str[i]) || str[i] == c)
// 			i++;
// 		if (!str[i])
// 			break;
// 		word = malloc(sizeof(char) * 1000);
// 		if (!word)
// 		{
// 			for (int l = 0; l < k; l++)
// 				free(splitted[l]);
// 			free(splitted);
// 			return (NULL);
// 		}
// 		while (str[i] && !(ft_isspace(str[i]) || str[i] == c))
// 		{
// 			word[j++] = str[i++];
// 		}
// 		word[j] = '\0';
// 		j = 0;
// 		splitted[k++] = word;
// 	}
// 	splitted[k] = NULL;
// 	return (splitted);
// }

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]) || str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !(ft_isspace(str[i]) || str[i] == c))
				i++;
		}
	}
	return (count);
}

char	**ft_allocate_words(int word_count)
{
	char	**words;

	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	return (words);
}

char	*ft_extract_word(char const *str, char c, int *i)
{
	int		j;
	char	*word;

	j = 0;
	word = malloc(sizeof(char) * 1000);
	if (!word)
		return (NULL);
	while (str[*i] && !(ft_isspace(str[*i]) || str[*i] == c))
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_extract_words(char const *str, char c, char **words)
{
	int		i;
	int		k;
	char	*word;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]) || str[i] == c)
			i++;
		if (!str[i])
			break ;
		word = ft_extract_word(str, c, &i);
		if (!word)
			return (NULL);
		words[k] = word;
		k++;
	}
	words[k] = NULL;
	return (words);
}

char	**ft_split(char const *str, char c)
{
	char	**words;
	int		word_count;
	int		l;

	if (!str)
		return (NULL);
	word_count = ft_count_words(str, c);
	words = ft_allocate_words(word_count);
	if (!words)
		return (NULL);
	if (!ft_extract_words(str, c, words))
	{
		l = 0;
		while (l < word_count)
		{
			free(words[l]);
			l++;
		}
		free(words);
		return (NULL);
	}
	return (words);
}

// static size_t	word_length(char const *s, char c)
// {
// 	size_t	l;

// 	l = 0;
// 	while (*s && *s != c)
// 	{
// 		s++;
// 		l++;
// 	}
// 	return (l);
// }

// static size_t	word_count(char const *s, char c)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s != c && *s)
// 			count++;
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	return (count);
// }

// static char	*wordcpy(char const *s, char c)
// {
// 	size_t	wl;
// 	char	*temp;

// 	wl = word_length(s, c);
// 	temp = malloc((wl + 1) * sizeof(char));
// 	ft_memcpy(temp, s, wl);
// 	temp[wl] = '\0';
// 	return (temp);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**ans;
// 	size_t	wc;
// 	size_t	ac;

// 	if (s == NULL)
// 		return (NULL);
// 	wc = word_count(s, c);
// 	ans = malloc (sizeof(char *) * (wc + 1));
// 	if (!ans)
// 		return (NULL);
// 	ac = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s != c && *s)
// 		{
// 			ans[ac] = wordcpy(s, c);
// 			ac++;
// 		}
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	ans[wc] = NULL;
// 	return (ans);
// }
