/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 09:44:58 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_ambient(t_scene *scene, char **tokens)
{
	t_color	colors;
	double	ratio;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s\n", tokens[0],
		tokens[1], tokens[2]);
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		printf("Error: Ambient light intensity or color is NULL\n");
		return ;
	}
	colors = parse_color(tokens[2]);
	ratio = ft_atof(tokens[1]);
	validate_double_range(ratio, 0.0, 1.0);
	scene->amb = amblight_init(ratio, colors.r, colors.g, colors.b);
	printf("Parsed Ambient light: intensity=%f, color=(%d, %d, %d)\n",
		scene->amb.ratio, scene->amb.r, scene->amb.g, scene->amb.b);
}

void	parse_light(t_scene *scene, char **tokens)
{
	t_vector	coord;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL)
	{
		printf("Error: Light position or intensity is NULL\n");
		return ;
	}
	coord = parse_vector(tokens[1]);
	validate_vector_range(coord, MIN_COORD, MAX_COORD);
	validate_double_range(ft_atof(tokens[2]), 0.0, 1.0);
	scene->light = light_init(coord, ft_atof(tokens[2]));
	printf("Parsed Light: coord=(%f, %f, %f), intensity=%f\n", coord.x, coord.y,
		coord.z, ft_atof(tokens[2]));
}
