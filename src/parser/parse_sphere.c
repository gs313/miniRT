/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:15:01 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_sphere(t_scene *scene, char **tokens)
{
	t_vector	coord;
	double		diameter;
	t_color		color;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	coord = parse_vector(tokens[1]);
	diameter = ft_atof(tokens[2]);
	color = parse_color(tokens[3]);
	scene->obj[scene->obj_count] = sphere_init(scene->obj_count, coord,
			color, diameter);
	scene->obj_count++;
	printf("Parsed Sphere: coord=(%f,%f,%f), diameter=%f, color=(%d,%d,%d)\n",
		coord.x, coord.y, coord.z, diameter, color.r, color.g, color.b);
}

// void	parse_sphere(t_scene *scene, char **tokens)
// {
// 	char		**coords;
// 	t_vector	coord;
// 	double		diameter;
// 	char		**colors;
// 	t_color		color;

// 	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
// 		tokens[0], tokens[1], tokens[2], tokens[3]);
// 	coords = ft_split(tokens[1], ',');
// 	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
// 			ft_atof(coords[2]));
// 	ft_free_split(coords);
// 	diameter = ft_atof(tokens[2]);
// 	colors = ft_split(tokens[3], ',');
// 	color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
// 			ft_atoi(colors[2]));
// 	ft_free_split(colors);
// 	scene->obj[scene->obj_count] = sphere_init(scene->obj_count, coord,
// 			color, diameter);
// 	scene->obj_count++;
// 	printf("Parsed Sphere: coord=(%f,%f,%f), diameter=%f, color=(%d,%d,%d)\n",
// 		coord.x, coord.y, coord.z, diameter, color.r, color.g, color.b);
// }

// void	parse_plane(t_scene *scene, char **tokens)
// {
// 	char		**coords;
// 	t_vector	coord;
// 	char		**dir;
// 	t_vector	direction;
// 	char		**colors;
// 	t_color		color;

// 	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
// 		tokens[0], tokens[1], tokens[2], tokens[3]);
// 	coords = ft_split(tokens[1], ',');
// 	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
// 			ft_atof(coords[2]));
// 	ft_free_split(coords);
// 	dir = ft_split(tokens[2], ',');
// 	direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]),
// 			ft_atof(dir[2]));
// 	ft_free_split(dir);
// 	colors = ft_split(tokens[3], ',');
// 	color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
// 			ft_atoi(colors[2]));
// 	ft_free_split(colors);
// 	scene->obj[scene->obj_count] = plane_init(scene->obj_count, coord,
// 			direction, color);
// 	scene->obj_count++;
// printf("Parsed Plane: coord=(%f,%f,%f), direction=(%f,%f,%f), ", coord.x,
// 	coord.y, coord.z, direction.x, direction.y, direction.z);
// printf("color=(%d,%d,%d)\n", color.r, color.g, color.b);
// }

// void	parse_cylinder(t_scene *scene, char **tokens)
// {
// printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s, ",
// 	tokens[0], tokens[1], tokens[2], tokens[3]);
// printf("tokens[4]=%s, tokens[5]=%s\n", tokens[4], tokens[5]);
// 	char **coords = ft_split(tokens[1], ',');
// 	t_vector coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
// 					ft_atof(coords[2]));
// 	ft_free_split(coords);
// 	char **dir = ft_split(tokens[2], ',');
// 	t_vector direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]),
// 						ft_atof(dir[2]));
// 	ft_free_split(dir);
// 	double diameter = ft_atof(tokens[3]);
// 	double height = ft_atof(tokens[4]);
// 	char **colors = ft_split(tokens[5], ',');
// 	t_color color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
// 					ft_atoi(colors[2]));
// 	ft_free_split(colors);
// 	scene->obj[scene->obj_count] = cylinder_init(scene->obj_count, coord,
// 					cylinder_attr_init(direction, diameter, height), color);
// 	scene->obj_count++;
// printf("Parsed Cylinder: coord=(%f, %f, %f), direction=(%f, %f, %f), ",
// 	coord.x, coord.y, coord.z, direction.x, direction.y, direction.z);
// printf("diameter=%f, height=%f, color=(%d, %d, %d)\n", diameter, height,
// 	color.r, color.g, color.b);
// }