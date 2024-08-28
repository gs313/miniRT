/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:55:48 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 02:50:43 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vec_scale(t_vector a, double b)
{
	t_vector	res;

	res.x = a.x * b;
	res.y = a.y * b;
	res.z = a.z * b;
	return (res);
}
