/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:54:50 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/16 10:57:03 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vec_norm(t_vector a)
{
	double		len;
	t_vector	res;

	len = vec_len(a);
	res.x = a.x / len;
	res.y = a.y / len;
	res.z = a.z / len;
	return (res);
}
