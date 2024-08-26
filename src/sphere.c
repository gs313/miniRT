/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/26 23:16:52 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	sphere_init(int id, t_object *obj, t_vector coord, unsigned int r, unsigned int g, unsigned int b, double d)
{
	obj->id = id;
	obj->type = 1;
	obj->coord = coord;
	obj->coord.x = -coord.x;
	obj->coord.y = -coord.y;
	obj->r = r;
	obj->g = g;
	obj->b = b;
	obj->d = d;
}

t_hit	hit_sphere(t_object obj, t_vector origin, t_vector dir)
{
	t_hit	hit;
	t_vector oc;
	double a;
	double b;
	double c;
	double discr;
	double t;

	hit = hit_init();
	oc = vec_sub(origin, obj.coord);
	a = vec_dot(dir, dir);
	b = 2.0 * vec_dot(oc, dir);
	c = vec_dot(oc, oc) - obj.d * obj.d;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (hit);
	t = (-b - sqrt(discr)) / (2.0 * a);
	if (t < 0)
		t = (-b + sqrt(discr)) / (2.0 * a);
	if (t < 0)
		return (hit);
	hit.obj_id = obj.id;
	hit.hitpoint = vec_add(origin, vec_scale(dir, t));
	hit.distance = t;
	return (hit);
}
