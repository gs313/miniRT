/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:39:25 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:14:56 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// int	validate_ambient(t_scene *scene)
// {
// 	if (scene->amb.ratio < 0.0 || scene->amb.ratio > 1.0)
// 	{
// 		printf("Error: Ambient light intensity must be between 0.0 and 1.0\n");
// 		return (FALSE);
// 	}
// 	if (scene->amb.r < 0 || scene->amb.r > 255 ||
// 		scene->amb.g < 0 || scene->amb.g > 255 ||
// 		scene->amb.b < 0 || scene->amb.b > 255)
// 	{
// 		printf("Error: Ambient light color must be between 0 and 255\n");
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }

// int	validate_light(t_scene *scene)
// {
// 	if (scene->light.ratio < 0.0 || scene->light.ratio > 1.0)
// 	{
// 		printf("Error: Light intensity must be between 0.0 and 1.0\n");
// 		return (FALSE);
// 	}
// 	if (scene->light.coord.x < -1000 || scene->light.coord.x > 1000 ||
// 		scene->light.coord.y < -1000 || scene->light.coord.y > 1000 ||
// 		scene->light.coord.z < -1000 || scene->light.coord.z > 1000)
// 	{
// 		printf("Error: Light coordinates must be between -1000 and 1000\n");
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }

// int	validate_camera(t_scene *scene)
// {
// 	if (scene->cam.dec < 0 || scene->cam.dec > 180)
// 	{
// 		printf("Error: Camera field of view must be between 0 and 180\n");
// 		return (FALSE);
// 	}
// 	if (scene->cam.coord.x < -1000 || scene->cam.coord.x > 1000 ||
// 		scene->cam.coord.y < -1000 || scene->cam.coord.y > 1000 ||
// 		scene->cam.coord.z < -1000 || scene->cam.coord.z > 1000)
// 	{
// 		printf("Error: Camera coordinates must be between -1000 and 1000\n");
// 		return (FALSE);
// 	}
// 	if (scene->cam.dir.x < -1 || scene->cam.dir.x > 1 ||
// 		scene->cam.dir.y < -1 || scene->cam.dir.y > 1 ||
// 		scene->cam.dir.z < -1 || scene->cam.dir.z > 1)
// 	{
// 		printf("Error: Camera direction must be between -1 and 1\n");
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }
