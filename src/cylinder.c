/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/26 15:25:42 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	cylinder_init(int id, t_object *obj, t_vector coord, t_vector dir, unsigned int r, unsigned int g, unsigned int b, double d, double h)
{
	obj->id = id;
	obj->type = CYLINDER;
	obj->coord = coord;
	obj->dir = vec_norm(dir);
	obj->r = r;
	obj->g = g;
	obj->b = b;
	obj->d = d;
	obj->h = h;
}

#include "../inc/minirt.h"

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
			return (hit);
		}
	}
	return (hit);
}
