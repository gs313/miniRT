/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:55 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/25 23:06:57 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
void	plane_init(int id, t_object *obj , t_vector coord, t_vector dir, unsigned int r, unsigned int g, unsigned int b)
{
	obj->id = id;
	obj->type = PLANE;
	obj->coord = coord;
	obj->dir = dir;
	obj->r = r;
	obj->g = g;
	obj->b = b;
}

t_hit	hit_plane(t_object obj, t_vector origin, t_vector dir)
{
	t_hit	hit;
	double	denom;
	double	t;

	hit = hit_init();
	denom = vec_dot(obj.dir, dir);
	if (denom > SMALL_NUM)
	{
		t_vector p0l0 = vec_sub(obj.coord, origin);
		t = vec_dot(p0l0, obj.dir) / denom;
		if (t >= 0.0f)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = vec_add(origin, vec_scale(dir, t));
			hit.distance = t;
		}
	}
	return (hit);
}
