/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:43:41 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/16 10:53:33 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_len2(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	vec_len(t_vector a)
{
	return (sqrt(vec_len2(a)));
}