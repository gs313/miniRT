/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:33:07 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/24 04:35:41 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit	hit_init(void)
{
	t_hit	hit;

	hit.obj_id = -1;
	hit.hitpoint = vec_init(0, 0, 0);
	hit.distance = INFINITY;
	return (hit);
}

t_hit	hit_closest(t_scene *scene, t_vector origin, t_vector dir)
{
	t_hit	hit;
	t_hit	tmp;
	int		i;

	hit = hit_init();
	i = 0;
	while (i < scene->obj_count)
	{
		tmp = hit_sphere(scene->obj[i], origin, dir);
		if (tmp.distance < hit.distance)
			hit = tmp;
		i++;
	}
	return (hit);
}