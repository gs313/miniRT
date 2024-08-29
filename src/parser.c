/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 16:34:38 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// parse ambient light
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
	// scene->amb.ratio = ft_atof(tokens[1]);
	// char **colors = ft_split(tokens[2], ',');
	// scene->amb.r = ft_atoi(colors[0]);
	// scene->amb.g = ft_atoi(colors[1]);
	// scene->amb.b = ft_atoi(colors[2]);
	ft_free_split(colors);

	printf("Parsed Ambient light: intensity=%f, color=(%d, %d, %d)\n",
				scene->amb.ratio, scene->amb.r, scene->amb.g, scene->amb.b);
}

// parse camera
void	parse_camera(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
			tokens[0], tokens[1], tokens[2], tokens[3]);

	char	**coords = ft_split(tokens[1], ',');
	t_vector	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
						ft_atof(coords[2]));
	ft_free_split(coords);
	char	**dir = ft_split(tokens[2], ',');
	t_vector	direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]),
							ft_atof(dir[2]));
	ft_free_split(dir);
	scene->cam = camera_init(coord, direction, ft_atoi(tokens[3]));
	// char **coords = ft_split(tokens[1], ',');
	// scene->cam.coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2]));
	// ft_free_split(coords);
	// char **dir = ft_split(tokens[2], ',');
	// scene->cam.dir = vec_init(ft_atof(dir[0]), ft_atof(dir[1]), ft_atof(dir[2]));
	// ft_free_split(dir);
	// scene->cam.dec = ft_atoi(tokens[3]);
	printf("Parsed Camera: coord=(%f, %f, %f), direction=(%f, %f, %f), fov=%d\n",
			coord.x, coord.y, coord.z, direction.x, direction.y, direction.z ,
			ft_atoi(tokens[3]));
}

// parse light
void	parse_light(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n", tokens[0],
			tokens[1], tokens[2], tokens[3]);
	
	char	**coords = ft_split(tokens[1], ',');
	t_vector	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
						ft_atof(coords[2]));
	ft_free_split(coords);
	scene->light = light_init(coord, ft_atof(tokens[2]));
	// char **coords = ft_split(tokens[1], ',');
	// scene->light.coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2]));
	// ft_free_split(coords);
	// scene->light.ratio = ft_atof(tokens[2]);
	printf("Parsed Light: coord=(%f, %f, %f), intensity=%f\n", coord.x, coord.y, coord.z,
			ft_atof(tokens[2]));
}

void	parse_sphere(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n", tokens[0],
			tokens[1], tokens[2], tokens[3]);
	
	char **coords = ft_split(tokens[1], ',');
	t_vector coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
					ft_atof(coords[2]));
	ft_free_split(coords);
	double diameter = ft_atof(tokens[2]);
	char **colors = ft_split(tokens[3], ',');
	t_color color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
					ft_atoi(colors[2]));
	ft_free_split(colors);
	scene->obj[scene->obj_count] = sphere_init(scene->obj_count, coord,
									color, diameter);
	scene->obj_count++;
	printf("Parsed Sphere: coord=(%f, %f, %f), diameter=%f, color=(%d, %d, %d)\n",
		coord.x, coord.y, coord.z, diameter, color.r, color.g, color.b);
}

void	parse_plane(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
			tokens[0], tokens[1], tokens[2], tokens[3]);
	
	char **coords = ft_split(tokens[1], ',');
	t_vector coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
					ft_atof(coords[2]));
	ft_free_split(coords);
	char **dir = ft_split(tokens[2], ',');
	t_vector direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]),
						ft_atof(dir[2]));
	ft_free_split(dir);
	char **colors = ft_split(tokens[3], ',');
	t_color color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
					ft_atoi(colors[2]));
	ft_free_split(colors);
	scene->obj[scene->obj_count] = plane_init(scene->obj_count, coord,
									direction, color);
	scene->obj_count++;
	printf("Parsed Plane: coord=(%f, %f, %f), direction=(%f, %f, %f), color=(%d, %d, %d)\n",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z, color.r, color.g, color.b);
}

void	parse_cylinder(t_scene *scene, char **tokens)
{
	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s, tokens[4]=%s, tokens[5]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);
	
	char **coords = ft_split(tokens[1], ',');
	t_vector coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
					ft_atof(coords[2]));
	ft_free_split(coords);
	char **dir = ft_split(tokens[2], ',');
	t_vector direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]),
						ft_atof(dir[2]));
	ft_free_split(dir);
	double diameter = ft_atof(tokens[3]);
	double height = ft_atof(tokens[4]);
	char **colors = ft_split(tokens[5], ',');
	t_color color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
					ft_atoi(colors[2]));
	ft_free_split(colors);
	scene->obj[scene->obj_count] = cylinder_init(scene->obj_count, coord,
					cylinder_attr_init(direction, diameter, height), color);
	scene->obj_count++;
	printf("Parsed Cylinder: coord=(%f, %f, %f), direction=(%f, %f, %f), diameter=%f, height=%f, color=(%d, %d, %d)\n",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z, diameter, height, color.r, color.g, color.b);

}

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
