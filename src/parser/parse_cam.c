/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 11:29:50 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_camera(t_scene *scene, char **tokens)
{
	t_vector	coord;
	t_vector	direction;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL)
	{
		printf("Error: Camera position or direction is NULL\n");
		return ;
	}
	coord = parse_vector(tokens[1]);
	validate_vector_range(coord, MIN_COORD, MAX_COORD);
	direction = parse_vector(tokens[2]);
	validate_vector_range(direction, -1.0, 1.0);
	validate_double_range(ft_atof(tokens[3]), 0.0, 180.0);
	scene->cam = camera_init(coord, direction, ft_atoi(tokens[3]));
	printf("Parsed Cam: coord=(%f, %f, %f), direction=(%f, %f, %f),dec=%d\n",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z,
		ft_atoi(tokens[3]));
}
