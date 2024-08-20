/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:35 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/20 21:18:34 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	sphere_init(t_object *obj, t_vector coord, unsigned int r, unsigned int g, unsigned int b, double d)
{
	obj->type = 1;
	obj->coord = coord;
	obj->r = r;
	obj->g = g;
	obj->b = b;
	obj->d = d;
}

