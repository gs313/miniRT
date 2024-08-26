/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:55 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 00:54:04 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_object	plane_init(int id, t_vector coord, t_vector dir, t_color color)
{
	t_object	obj;

	obj.id = id;
	obj.type = PLANE;
	obj.coord = coord;
	obj.dir = vec_norm(dir);
	obj.r = color.r;
	obj.g = color.g;
	obj.b = color.b;
	return (obj);
}

t_hit	hit_plane(t_object obj, t_vector origin, t_vector dir)
{
	t_hit	hit;
	double	denom;
	double	t;

	hit = hit_init();
	denom = vec_dot(vec_norm(obj.dir), vec_norm(dir));
	if (fabs(denom) > SMALL_NUM)
	{
		t_vector p0l0 = vec_sub(obj.coord, origin);
		t = vec_dot(p0l0, vec_norm(obj.dir)) / denom;
		if (t >= 0.0f)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = vec_add(origin, vec_scale(dir, t));
			hit.distance = t;
		}
	}
	return (hit);
}
