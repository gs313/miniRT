/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:43:20 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 02:48:02 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	color_init(unsigned int r, unsigned int g, unsigned int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int32_t	rgb_to_int(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	is_shadow(t_scene *scene, t_vector origin, t_vector dir, t_hit hit)
{
	t_hit	shadow_hit;

	dir = vec_scale(dir, -1.0f);
	shadow_hit = hit_closest(scene, origin, dir);
	if (shadow_hit.obj_id == hit.obj_id)
		return (FALSE);
	return (TRUE);
}

int32_t	cal_color(t_hit hit, t_scene *scene)
{
	float		dot;
	t_vector	hit_light;
	t_vector	hit_normal;

	hit_light = vec_norm(vec_sub(scene->light.coord, hit.hitpoint));
	if (scene->obj[hit.obj_id].type == PLANE)
		hit_normal = vec_norm(scene->obj[hit.obj_id].dir);
	else if (scene->obj[hit.obj_id].type == SPHERE)
		hit_normal = vec_norm(vec_sub(hit.hitpoint,
					scene->obj[hit.obj_id].coord));
	else if (hit.is_disk)
		hit_normal = vec_norm(scene->obj[hit.obj_id].dir);
	else
	{
		hit_normal = vec_norm(vec_sub(hit.hitpoint,
					scene->obj[hit.obj_id].coord));
		hit_normal = vec_norm(vec_sub(hit_normal,
					vec_scale(scene->obj[hit.obj_id].dir,
						vec_dot(hit_normal,
							scene->obj[hit.obj_id].dir))));
	}
	dot = vec_dot(hit_light, hit_normal);
	return (cal_util1(scene, dot, hit, hit_light));
}

int32_t	cal_util1(t_scene *scene, double dot, t_hit hit, t_vector hit_light)

{
	t_color	color;

	if ((dot < 0.0f && scene->obj[hit.obj_id].type == PLANE)
		|| (scene->obj[hit.obj_id].type == CYLINDER && hit.is_disk
			&& vec_dot(vec_norm(scene->cam.dir),
				vec_norm(scene->obj[hit.obj_id].dir)) > 0.0f))
		dot = -dot;
	if (dot < 0.0f || is_shadow(scene, scene->light.coord, hit_light, hit))
		dot = 0.0f;
	color.r = scene->obj[hit.obj_id].r * dot * scene->light.ratio
		+ scene->amb.r * scene->amb.ratio;
	color.g = scene->obj[hit.obj_id].g * dot * scene->light.ratio
		+ scene->amb.g * scene->amb.ratio;
	color.b = scene->obj[hit.obj_id].b * dot * scene->light.ratio
		+ scene->amb.b * scene->amb.ratio;
	return (rgb_to_int(color.r, color.g, color.b));
}
