/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 23:41:17 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_lines(t_scene *scene, int fd, bool *parsed)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\0' || line[0] == '#' || ft_isspace(line[0]))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		parse_line(scene, line, parsed);
		free(line);
		line = get_next_line(fd);
	}
}

void	parse_rt_file(t_scene *scene, const char *filename)
{
	int		fd;
	bool	parsed;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	parsed = false;
	parse_lines(scene, fd, &parsed);
	if (!parsed)
	{
		printf("\nError: No valid data was parsed\n\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	parse_line(t_scene *scene, char *line, bool *parsed)
{
	char	**tokens;

	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0')
		return ;
	tokens = ft_split(line, ' ');
	if (tokens == NULL)
	{
		free(tokens);
		printf("Error: ft_split returned NULL\n");
		return ;
	}
	parse_token(scene, tokens, parsed);
}

void	parse_token(t_scene *scene, char **tokens, bool *parsed)
{
	if ((ft_strncmp(tokens[0], "A", 1) == 0)
		|| (ft_strncmp(tokens[0], "C", 1) == 0)
		|| (ft_strncmp(tokens[0], "L", 1) == 0)
		|| (ft_strncmp(tokens[0], "sp", 2) == 0)
		|| (ft_strncmp(tokens[0], "pl", 2) == 0)
		|| (ft_strncmp(tokens[0], "cy", 2) == 0))
	{
		printf("\nParsing token: %s\n", tokens[0]);
		if (ft_strncmp(tokens[0], "A", 1) == 0)
			parse_ambient(scene, tokens, parsed);
		else if (ft_strncmp(tokens[0], "C", 1) == 0)
			parse_camera(scene, tokens, parsed);
		else if (ft_strncmp(tokens[0], "L", 1) == 0)
			parse_light(scene, tokens, parsed);
		else if (ft_strncmp(tokens[0], "sp", 2) == 0)
			parse_sphere(scene, tokens, parsed);
		else if (ft_strncmp(tokens[0], "pl", 2) == 0)
			parse_plane(scene, tokens, parsed);
		else if (ft_strncmp(tokens[0], "cy", 2) == 0)
			parse_cylinder(scene, tokens, parsed);
	}
	ft_free_split(tokens);
}
