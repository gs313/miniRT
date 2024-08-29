/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:15:07 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_ambient(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s\n", tokens[0],
			tokens[1], tokens[2]);
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		printf("Error: Ambient light intensity or color is NULL\n");
		return;
	}
	
	char	**colors = ft_split(tokens[2], ',');
	if (colors[0] == NULL || colors[1] == NULL || colors[2] == NULL)
	{
		printf("Error: Ambient light color is NULL\n");
		ft_free_split(colors);
		return;
	}
	scene->amb = amblight_init(ft_atof(tokens[1]), ft_atoi(colors[0]),
				ft_atoi(colors[1]), ft_atoi(colors[2]));
	ft_free_split(colors);

	printf("Parsed Ambient light: intensity=%f, color=(%d, %d, %d)\n",
				scene->amb.ratio, scene->amb.r, scene->amb.g, scene->amb.b);
}

void	parse_light(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n", tokens[0],
			tokens[1], tokens[2], tokens[3]);
	
	char	**coords = ft_split(tokens[1], ',');
	t_vector	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
						ft_atof(coords[2]));
	ft_free_split(coords);
	scene->light = light_init(coord, ft_atof(tokens[2]));
	printf("Parsed Light: coord=(%f, %f, %f), intensity=%f\n", coord.x, coord.y, coord.z,
			ft_atof(tokens[2]));
}
