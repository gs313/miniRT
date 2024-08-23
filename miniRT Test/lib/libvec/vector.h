/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:24:14 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 11:45:31 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "math.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	vec_init(double x, double y, double z);
t_vector	vec_add(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	vec_cross(t_vector a, t_vector b);
double		vec_dot(t_vector a, t_vector b);
t_vector	vec_scale(t_vector a, double b);
t_vector	vec_norm(t_vector a);
double		vec_len2(t_vector a);
double		vec_len(t_vector a);
#endif
