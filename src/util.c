/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:24:30 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 10:28:50 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

t_quard		set_quard(t_object obj, t_vector origin, t_vector dir)
{
	t_quard		quard;
	t_vector	oc;

	oc = vec_sub(origin, obj.coord);
	quard.a = vec_dot(dir, dir) - pow(vec_dot(dir, obj.dir), 2);
	quard.b = 2 * (vec_dot(dir, oc) - vec_dot(dir, obj.dir) * vec_dot(oc, obj.dir));
	quard.c = vec_dot(oc, oc) - pow(vec_dot(oc, obj.dir), 2) - obj.d * obj.d;
	quard.discr = quard.b * quard.b - 4 * quard.a * quard.c;
	return (quard);
}
