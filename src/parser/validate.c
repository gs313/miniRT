/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:39:25 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 09:56:50 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	validate_double_range(double value, double min, double max)
{
	if (value < min || value > max)
	{
		printf("Error: Value %f out of range [%f, %f]\n", value, min, max);
		exit(EXIT_FAILURE);
	}
	return (true);
}

bool	validate_int_range(int value, int min, int max)
{
	if (value < min || value > max)
	{
		printf("Error: Value %d out of range [%d, %d]\n", value, min, max);
		exit(EXIT_FAILURE);
	}
	return (true);
}

void	validate_rgb(t_color color)
{
	if (!validate_int_range(color.r, 0, 255) || !validate_int_range(color.g,
			0, 255) || !validate_int_range(color.b, 0, 255))
	{
		printf("Error: RGB values out of range [0, 255]\n");
		exit(EXIT_FAILURE);
	}
}

void	validate_vector_range(t_vector vec, double min, double max)
{
	if (!validate_double_range(vec.x, min, max) || !validate_double_range(vec.y,
			min, max) || !validate_double_range(vec.z, min, max))
	{
		printf("Error: Vector values out of range [%f, %f]\n", min, max);
		exit(EXIT_FAILURE);
	}
}

//check if camera is inside any object
// bool	is_camera_inside_object(t_camera cam, t_object *obj, unsigned int obj_count)
// {
// 	unsigned int i;
// 	i = 0;
// 	while (i < obj_count)
// 	{
// 		if (obj[i].type == SPHERE) // sphere
// 		{
// 			double distance = sqrt(pow(cam.coord.x - obj[i].coord.x, 2) +
// 								pow(cam.coord.y - obj[i].coord.y, 2) +
// 								pow(cam.coord.z - obj[i].coord.z, 2));
// 			if (distance < obj[i].d / 2)
// 			{
// 				return (true);
// 			}
// 		}
// 		else if (obj[i].type == CYLINDER) // calculate distance frm camera to cylinder's axis
// 		{
// 			t_vector	cam_to_axis;
// 			double		projection;
// 			t_vector	closest_point;
// 			cam_to_axis = vec_sub(cam.coord, obj[i].coord);
// 			projection = vec_dot(cam_to_axis, obj[i].dir);
// 			closest_point = vec_add(obj[i].coord, vec_scale(obj[i].dir, projection));
// 			double distance = vec_len(vec_sub(cam.coord, closest_point));
// 			if (distance < obj[i].d / 2 && projection >= 0 && projection <= obj[i].h)
// 			{
// 				return (true);
// 			}
// 		}
// 		else if (obj[i].type == PLANE) // camera is inside the plane
// 		{
// 			t_vector	cam_to_plane;
// 			double		distance;
// 			cam_to_plane = vec_sub(cam.coord, obj[i].coord);
// 			distance = vec_dot(cam_to_plane, obj[i].dir);
// 			if (distance > 0 && distance < obj[i].h)
// 			{
// 				return (true);
// 			}
// 		}
// 		i++;
// 	}
// 	return (false);
// }
