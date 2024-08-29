/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec_n_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/29 18:15:01 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vector	parse_vector(char *token)
{
	char		**coords;
	t_vector	vector;

	coords = ft_split(token, ',');
	vector = vec_init(ft_atof(coords[0]), ft_atof(coords[1]),
			ft_atof(coords[2]));
	ft_free_split(coords);
	return (vector);
}

t_color	parse_color(char *token)
{
	char		**colors;
	t_color		color;

	colors = ft_split(token, ',');
	color = color_init(ft_atoi(colors[0]), ft_atoi(colors[1]),
			ft_atoi(colors[2]));
	ft_free_split(colors);
	return (color);
}
