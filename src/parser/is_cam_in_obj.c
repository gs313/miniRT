/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cam_in_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:39:25 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 21:40:58 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	is_camera_inside_sphere(t_camera cam, t_object obj)
{
	double	distance;

	distance = sqrt(pow(cam.coord.x - obj.coord.x, 2)
			+ pow(cam.coord.y - obj.coord.y, 2)
			+ pow(cam.coord.z - obj.coord.z, 2));
	printf("Debug: Sphere - Camera distance: %f, Sphere radius: %f\n",
		distance, obj.d / 2);
	if (distance < obj.d / 2)
	{
		printf("Error: Camera is inside a sphere\n");
		exit(EXIT_FAILURE);
	}
	return (false);
}

bool	is_camera_inside_cylinder(t_camera cam, t_object obj)
{
	t_vector	cam_to_axis;
	double		projection;
	t_vector	closest_point;
	double		distance;

	cam_to_axis = vec_sub(cam.coord, obj.coord);
	projection = vec_dot(cam_to_axis, obj.dir);
	closest_point = vec_add(obj.coord, vec_scale(obj.dir, projection));
	distance = vec_len(vec_sub(cam.coord, closest_point));
	if (distance < obj.d / 2 && projection >= 0 && projection <= obj.h)
	{
		printf("Error: Camera is inside a cylinder\n");
		exit(EXIT_FAILURE);
	}
	return (false);
}

bool	is_camera_inside_plane(t_camera cam, t_object obj)
{
	t_vector	cam_to_plane;
	double		distance;

	cam_to_plane = vec_sub(cam.coord, obj.coord);
	distance = vec_dot(cam_to_plane, obj.dir);
	if (fabs(distance) < 1e-6)
	{
		printf("Error: Camera is inside a plane\n");
		exit(EXIT_FAILURE);
	}
	return (false);
}

void	is_camera_inside_object(t_camera cam, t_object *obj,
		unsigned int obj_count)
{
	unsigned int	i;

	i = 0;
	while (i < obj_count)
	{
		if (obj[i].type == SPHERE)
		{
			is_camera_inside_sphere(cam, obj[i]);
		}
		else if (obj[i].type == CYLINDER)
		{
			is_camera_inside_cylinder(cam, obj[i]);
		}
		else if (obj[i].type == PLANE)
		{
			is_camera_inside_plane(cam, obj[i]);
		}
		i++;
	}
}
