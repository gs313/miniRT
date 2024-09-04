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

void	parse_cylinder(t_scene *scene, char **tok, bool *parsed)
{
	t_vector	coord;
	t_vector	direction;
	double		diameter;
	double		height;
	t_color		color;

	*parsed = true;
	printf("Debug: tokens = [0]=%s, [1]=%s, [2]=%s, [3]=%s, [4]=%s, [5]=%s\n",
		tok[0], tok[1], tok[2], tok[3], tok[4], tok[5]);
	coord = parse_vector(tok[1]);
	validate_vector_range(coord, MIN_COORD, MAX_COORD);
	direction = parse_vector(tok[2]);
	validate_vector_range(direction, -1.0, 1.0);
	diameter = ft_atof(tok[3]);
	validate_double_range(diameter, 0.0, MAX_COORD);
	height = ft_atof(tok[4]);
	validate_double_range(height, 0.0, MAX_COORD);
	color = parse_color(tok[5]);
	scene->obj[scene->obj_count] = cylinder_init(scene->obj_count, coord,
			cylinder_attr_init(direction, diameter, height), color);
	scene->obj_count++;
	printf("Parsed Cylinder: coord=(%f, %f, %f), direction=(%f, %f, %f), ",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z);
	printf("diameter=%f, height=%f, color=(%d, %d, %d)\n", diameter, height,
		color.r, color.g, color.b);
}
