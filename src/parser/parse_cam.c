/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:15:11 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_camera(t_scene *scene, char **tokens)
{
	char		**coords;
	t_vector	coord;
	char		**dir;
	t_vector	direction;

	printf("Debug: tokens[0]=%s, tokens[1]=%s, tokens[2]=%s, tokens[3]=%s\n",
		tokens[0], tokens[1], tokens[2], tokens[3]);
	coords = ft_split(tokens[1], ',');
	coord = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
			ft_atof(coords[2]));
	ft_free_split(coords);
	dir = ft_split(tokens[2], ',');
	direction = vec_init(ft_atof(dir[0]), ft_atof(dir[1]), ft_atof(dir[2]));
	ft_free_split(dir);
	scene->cam = camera_init(coord, direction, ft_atoi(tokens[3]));
	printf("Parsed Cam: coord=(%f, %f, %f), direction=(%f, %f, %f),dec=%d\n",
		coord.x, coord.y, coord.z, direction.x, direction.y, direction.z,
		ft_atoi(tokens[3]));
}
