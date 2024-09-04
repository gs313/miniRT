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

static int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (ft_isspace(str[i]) || str[i] == c))
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

static char	*ft_extract_word(char const *str, char c, int *i)
{
	int		start;
	int		len;
	char	*word;

	while (str[*i] && (ft_isspace(str[*i]) || str[*i] == c))
		(*i)++;
	start = *i;
	while (str[*i] && !(ft_isspace(str[*i]) || str[*i] == c))
		(*i)++;
	len = *i - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &str[start], len + 1);
	return (word);
}

static void	ft_free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**words;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	word_count = ft_count_words(str, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		words[j] = ft_extract_word(str, c, &i);
		if (!words[j])
		{
			ft_free_words(words, j);
			return (NULL);
		}
		j++;
	}
	words[j] = NULL;
	return (words);
}

/*int	ft_count_words(char const *str, char c)
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
}*/
