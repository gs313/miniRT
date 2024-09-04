/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 10:48:02 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cylinder_attr	cylinder_attr_init(t_vector dir, double d, double h)
{
	t_cylinder_attr	attr;

	attr.dir = dir;
	attr.d = d;
	attr.h = h;
	return (attr);
}

t_object	cylinder_init(int id, t_vector coord,
					t_cylinder_attr attr, t_color color)
{
	t_object	obj;

	obj.id = id;
	obj.type = CYLINDER;
	obj.coord = coord;
	// obj.coord.x = -coord.x;
	// obj.coord.y = -coord.y;
	obj.dir = vec_norm(attr.dir);
	obj.r = color.r;
	obj.g = color.g;
	obj.b = color.b;
	obj.d = attr.d;
	obj.h = attr.h;
	return (obj);
}

t_hit	hit_cap(t_object obj, t_vector origin, t_vector dir, double t)
{
	t_hit		hit;
	t_vector	hitpoint;

	hit = hit_init();
	hitpoint = vec_add(origin, vec_scale(dir, t));
	if (vec_len(vec_sub(hitpoint, obj.coord)) <= obj.d)
		return (set_hit(obj, hitpoint, t, TRUE));
	return (hit);
}

t_cylinder_attr	set_cy_attr(t_object obj, t_vector origin,
					t_vector dir, t_quard quard)
{
	t_cylinder_attr	attr;

	attr.dir = vec_norm(obj.dir);
	attr.t2 = (-quard.b + sqrt(quard.discr)) / (2.0 * quard.a);
	attr.t1 = (-quard.b - sqrt(quard.discr)) / (2.0 * quard.a);
	return (attr);
}

t_hit	hit_cylinder(t_object obj, t_vector origin, t_vector dir)
{
	t_hit			hit;
	t_quard			quard;
	t_cylinder_attr	attr;

	hit = hit_init();
	quard = set_quard(obj, origin, dir);
	attr = set_cy_attr(obj, origin, dir, quard);
	if (quard.discr >= 0)
	{
		if (attr.t1 >= 0 || attr.t2 >= 0)
		{
			quard.t = ft_min(attr.t1, attr.t2);
			if (quard.t < 0)
				quard.t = ft_max(attr.t1, attr.t2);
			attr.hitpoint = vec_add(origin, vec_scale(dir, quard.t));
			attr.hit_height = vec_dot(vec_sub(attr.hitpoint,
						obj.coord), obj.dir);
			if (attr.hit_height >= 0 && attr.hit_height <= obj.h)
				return (set_hit(obj, attr.hitpoint, quard.t, FALSE));
		}
	}
	hit = hit_cap(obj, origin, dir, (vec_dot(obj.dir,
					vec_sub(obj.coord, origin))) / vec_dot(obj.dir, dir));
	return (hit);
}
