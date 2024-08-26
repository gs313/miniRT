/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 04:08:24 by scharuka         ###   ########.fr       */
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

t_object	cylinder_init(int id, t_vector coord, t_cylinder_attr attr, t_color color)
{
	t_object	obj;

	obj.id = id;
	obj.type = CYLINDER;
	obj.coord = coord;
	obj.coord.x = -coord.x;
	obj.coord.y = -coord.y;
	obj.dir = vec_norm(attr.dir);
	obj.r = color.r;
	obj.g = color.g;
	obj.b = color.b;
	obj.d = attr.d;
	obj.h = attr.h;
	return (obj);
}

t_hit	hit_cylinder(t_object obj, t_vector origin, t_vector dir)
{
	t_hit		hit;
	t_vector	oc;
	t_quard		quard;
	t_cylinder_attr	attr;

	hit = hit_init();
	oc = vec_sub(origin, obj.coord);
	attr.dir = vec_norm(obj.dir);
	quard.a = vec_dot(dir, dir) - pow(vec_dot(dir, obj.dir), 2);
	quard.b = 2 * (vec_dot(dir, oc) - vec_dot(dir, obj.dir) * vec_dot(oc, obj.dir));
	quard.c = vec_dot(oc, oc) - pow(vec_dot(oc, obj.dir), 2) - obj.d * obj.d;
	quard.discr = quard.b * quard.b - 4 * quard.a * quard.c;
	if (quard.discr >= 0)
	{
		attr.t1 = (-quard.b - sqrt(quard.discr)) / (2.0 * quard.a);
		attr.t2 = (-quard.b + sqrt(quard.discr)) / (2.0 * quard.a);
		if (attr.t1 >= 0 || attr.t2 >= 0)
		{
			quard.t = (attr.t1 < attr.t2) ? attr.t1 : attr.t2;
			if (quard.t < 0)
				quard.t = (attr.t1 > attr.t2) ? attr.t1 : attr.t2;
			if (quard.t >= 0)
			{
				attr.hitpoint = vec_add(origin, vec_scale(dir, quard.t));
				double hit_height = vec_dot(vec_sub(attr.hitpoint, obj.coord), obj.dir);
				if (hit_height >= 0 && hit_height <= obj.h)
				{
					hit.obj_id = obj.id;
					hit.hitpoint = attr.hitpoint;
					hit.distance = quard.t;
					return (hit);
				}
			}
		}
	}

	attr.t_cap = (vec_dot(obj.dir, vec_sub(vec_add(obj.coord, vec_scale(obj.dir, obj.h)), origin))) / vec_dot(obj.dir, dir);
	if (attr.t_cap >= 0)
	{
		attr.hitpoint = vec_add(origin, vec_scale(dir, attr.t_cap));
		if (vec_len(vec_sub(attr.hitpoint, vec_add(obj.coord, vec_scale(obj.dir, obj.h)))) <= obj.d)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = attr.hitpoint;
			hit.distance = attr.t_cap;
			hit.is_disk = TRUE;
			return (hit);
		}
	}

	attr.t_cap = (vec_dot(obj.dir, vec_sub(obj.coord, origin))) / vec_dot(obj.dir, dir);
	if (attr.t_cap >= 0)
	{
		attr.hitpoint = vec_add(origin, vec_scale(dir, attr.t_cap));
		if (vec_len(vec_sub(attr.hitpoint, obj.coord)) <= obj.d)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = attr.hitpoint;
			hit.distance = attr.t_cap;
			hit.is_disk = TRUE;
			return (hit);
		}
	}
	return (hit);
}
