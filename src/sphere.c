/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/04 17:22:31 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_object	sphere_init(int id, t_vector coord, t_color color, double d)
{
	t_object	obj;

	obj.id = id;
	obj.type = SPHERE;
	obj.coord = coord;
	obj.r = color.r;
	obj.g = color.g;
	obj.b = color.b;
	obj.d = d;
	return (obj);
}

t_hit	hit_sphere(t_object obj, t_vector origin, t_vector dir)
{
	t_hit		hit;
	t_vector	oc;
	t_quard		quard;

	hit = hit_init();
	oc = vec_sub(origin, obj.coord);
	quard.a = vec_dot(dir, dir);
	quard.b = 2.0 * vec_dot(oc, dir);
	quard.c = vec_dot(oc, oc) - obj.d * obj.d;
	quard.discr = quard.b * quard.b - 4 * quard.a * quard.c;
	if (quard.discr < 0)
		return (hit);
	quard.t = (-quard.b - sqrt(quard.discr)) / (2.0 * quard.a);
	if (quard.t < 0)
		quard.t = (-quard.b + sqrt(quard.discr)) / (2.0 * quard.a);
	if (quard.t < 0)
		return (hit);
	hit.obj_id = obj.id;
	hit.hitpoint = vec_add(origin, vec_scale(dir, quard.t));
	hit.distance = quard.t;
	return (hit);
}
