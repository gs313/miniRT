/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 09:07:48 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_plane(t_scene *scene, char **tokens)
{
	t_vector	coord;
	t_vector	direction;
	t_color		color;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL
		|| tokens[3] == NULL)
	{
		printf("Error: Plane position, direction or color is NULL\n");
		return ;
	}
	coord = parse_vector(tokens[1]);
	validate_vector_range(coord, MIN_COORD, MAX_COORD);
	direction = parse_vector(tokens[2]);
	validate_vector_range(direction, -1.0, 1.0);
	color = parse_color(tokens[3]);
	scene->obj[scene->obj_count] = plane_init(scene->obj_count, coord,
			direction, color);
	scene->obj_count++;
	printf("Parsed Plane: coord=(%f,%f,%f), direction=(%f,%f,%f), ", coord.x,
		coord.y, coord.z, direction.x, direction.y, direction.z);
	printf("color=(%d,%d,%d)\n", color.r, color.g, color.b);
}
