/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 09:10:00 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_cylinder(t_scene *scene, char **tokens)
{
	t_vector	coord;
	t_vector	direction;
	double		diameter;
	double		height;
	t_color		color;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s, ",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	printf("tokens[4]=%s, tokens[5]=%s\n", tokens[4], tokens[5]);
	coord = parse_vector(tokens[1]);
	validate_vector_range(coord, MIN_COORD, MAX_COORD);
	direction = parse_vector(tokens[2]);
	validate_vector_range(direction, -1.0, 1.0);
	diameter = ft_atof(tokens[3]);
	validate_double_range(diameter, 0.0, MAX_COORD);
	height = ft_atof(tokens[4]);
	validate_double_range(height, 0.0, MAX_COORD);
	color = parse_color(tokens[5]);
	scene->obj[scene->obj_count] = cylinder_init(scene->obj_count, coord,
			cylinder_attr_init(direction, diameter, height), color);
	scene->obj_count++;
	printf("Parsed Cylinder: coord=(%f, %f, %f), direction=(%f, %f, %f), ",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z);
	printf("diameter=%f, height=%f, color=(%d, %d, %d)\n", diameter, height,
		color.r, color.g, color.b);
}
