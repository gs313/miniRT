/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:41:02 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 14:58:17 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_stbuff(char *stbuff)
{
	if (stbuff != NULL)
		free(stbuff);
	return (NULL);
}

void	change_buf(char *buf, char *next)
{
	int	i;

	i = 0;
	while (next[i] != '\0')
	{
		buf[i] = next[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

char	*check_stbuff(char *stbuff, char *line)
{
	char	*tmp;
	char	*nextline;

	if (stbuff != NULL)
	{
		nextline = ft_strchr(stbuff, '\n');
		if (nextline)
		{
			tmp = ft_substr(stbuff, 0, ((nextline - stbuff) + 1));
			line = ft_strjoin_f(line, tmp);
			free(tmp);
			change_buf(stbuff, nextline + 1);
		}
		else
		{
			line = ft_strjoin_f(line, stbuff);
		}
	}
	return (line);
}

char	*initial(char **stbuff)
{
	char	*line;

	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	if (*stbuff == NULL)
	{
		*stbuff = malloc(BUFFER_SIZE + 1);
		if (*stbuff != NULL)
			**stbuff = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stbuff[OPEN_MAX + 1];
	char		*line;
	int			byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = initial(&stbuff[fd]);
	while (1)
	{
		line = check_stbuff(stbuff[fd], line);
		if (stbuff[fd] == NULL || ft_strchr(line, '\n') || byte == 0)
			break ;
		byte = read(fd, stbuff[fd], BUFFER_SIZE);
		if (byte < 0)
			return (NULL);
		stbuff[fd][byte] = '\0';
	}
	if (line[0] == '\0')
		line = free_stbuff(line);
	if (line == NULL || byte == 0)
		stbuff[fd] = free_stbuff(stbuff[fd]);
	return (line);
}
