/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 00:42:51 by scharuka         ###   ########.fr       */
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
	t_hit	hit;
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discr;
	double		t;
	double		t1;
	double		t2;
	double		t_cap;
	t_vector	hitpoint;

	hit = hit_init();
	oc = vec_sub(origin, obj.coord);
	a = vec_dot(dir, dir) - pow(vec_dot(dir, obj.dir), 2);
	b = 2 * (vec_dot(dir, oc) - vec_dot(dir, obj.dir) * vec_dot(oc, obj.dir));
	c = vec_dot(oc, oc) - pow(vec_dot(oc, obj.dir), 2) - obj.d * obj.d;
	discr = b * b - 4 * a * c;
	if (discr >= 0)
	{
		t1 = (-b - sqrt(discr)) / (2.0 * a);
		t2 = (-b + sqrt(discr)) / (2.0 * a);
		if (t1 >= 0 || t2 >= 0)
		{
			t = (t1 < t2) ? t1 : t2;
			if (t < 0)
				t = (t1 > t2) ? t1 : t2;
			if (t >= 0)
			{
				hitpoint = vec_add(origin, vec_scale(dir, t));
				double hit_height = vec_dot(vec_sub(hitpoint, obj.coord), obj.dir);
				if (hit_height >= 0 && hit_height <= obj.h)
				{
					hit.obj_id = obj.id;
					hit.hitpoint = hitpoint;
					hit.distance = t;
					return (hit);
				}
			}
		}
	}

	// Check for intersection with the top cap
	t_cap = (vec_dot(obj.dir, vec_sub(vec_add(obj.coord, vec_scale(obj.dir, obj.h)), origin))) / vec_dot(obj.dir, dir);
	if (t_cap >= 0)
	{
		hitpoint = vec_add(origin, vec_scale(dir, t_cap));
		if (vec_len(vec_sub(hitpoint, vec_add(obj.coord, vec_scale(obj.dir, obj.h)))) <= obj.d)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = hitpoint;
			hit.distance = t_cap;
			hit.is_disk = TRUE;
			return (hit);
		}
	}

	// Check for intersection with the bottom cap
	t_cap = (vec_dot(obj.dir, vec_sub(obj.coord, origin))) / vec_dot(obj.dir, dir);
	if (t_cap >= 0)
	{
		hitpoint = vec_add(origin, vec_scale(dir, t_cap));
		if (vec_len(vec_sub(hitpoint, obj.coord)) <= obj.d)
		{
			hit.obj_id = obj.id;
			hit.hitpoint = hitpoint;
			hit.distance = t_cap;
			hit.is_disk = TRUE;
			return (hit);
		}
	}
	return (hit);
}
