/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:14:39 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_line(t_scene *scene, char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0')
		return;

	char **tokens = ft_split(line, ' ');
	if (tokens == NULL)
	{
		free(tokens);
		printf("Error: ft_split returned NULL\n");
		return;
	}
	
	printf("\nParsing token: %s\n", tokens[0]);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		parse_ambient(scene, tokens);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		parse_camera(scene, tokens);
	else if (ft_strncmp(tokens[0], "L", 1) == 0)
		parse_light(scene, tokens);
	else if (ft_strncmp(tokens[0], "sp", 2) == 0)
		parse_sphere(scene, tokens);
	else if (ft_strncmp(tokens[0], "pl", 2) == 0)
		parse_plane(scene, tokens);
	else if (ft_strncmp(tokens[0], "cy", 2) == 0)
		parse_cylinder(scene, tokens);
	else
	{
		printf("\nError: No oject found Or Unrecognized object type '%s' \n", tokens[0]);
		// ft_free_split(tokens);
		// exit(EXIT_FAILURE);
	}
	ft_free_split(tokens);
}

void	parse_rt_file(t_scene *scene, const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(scene, line);
		free(line);
	}
	close(fd);
}