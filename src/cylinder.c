/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:16:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/25 22:58:25 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// t_object	cylinder_init(int id, t_vector coord, t_vector dir, unsigned int r, unsigned int g, unsigned int b, double d, double h)
// {
// 	t_object	cylinder;

// 	cylinder.id = id;
// 	cylinder.type = CYLINDER;
// 	cylinder.coord = coord;
// 	cylinder.dir = dir;
// 	cylinder.r = r;
// 	cylinder.g = g;
// 	cylinder.b = b;
// 	cylinder.d = d;
// 	cylinder.h = h;
// 	return (cylinder);
// }
void	cylinder_init(int id, t_object *obj, t_vector coord, t_vector dir, unsigned int r, unsigned int g, unsigned int b, double d, double h)
{
	obj->id = id;
	obj->type = CYLINDER;
	obj->coord = coord;
	obj->dir = dir;
	obj->r = r;
	obj->g = g;
	obj->b = b;
	obj->d = d;
	obj->h = h;
}
t_hit	hit_cylinder(t_object obj, t_vector origin, t_vector dir)
{
	t_hit	hit;
	t_vector	oc;
	// t_vector	co;
	double		a;
	double		b;
	double		c;
	double		discr;
	double		t;
	double		t1;
	double		t2;

	hit = hit_init();
	oc = vec_sub(origin, obj.coord);
	// co = vec_sub(obj.coord, origin);
	a = vec_dot(dir, dir) - pow(vec_dot(dir, obj.dir), 2);
	b = 2 * (vec_dot(dir, oc) - vec_dot(dir, obj.dir) * vec_dot(oc, obj.dir));
	c = vec_dot(oc, oc) - pow(vec_dot(oc, obj.dir), 2) - obj.d * obj.d;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (hit);
	t1 = (-b - sqrt(discr)) / (2.0 * a);
	t2 = (-b + sqrt(discr)) / (2.0 * a);
	if (t1 < 0 && t2 < 0)
		return (hit);
	t = (t1 < t2) ? t1 : t2;
	if (t < 0)
		t = (t1 > t2) ? t1 : t2;
	if (t < 0)
		return (hit);
	hit.obj_id = obj.id;
	hit.hitpoint = vec_add(origin, vec_scale(dir, t));
	hit.distance = t;
	return (hit);
}
