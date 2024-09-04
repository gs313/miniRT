/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec_n_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:43:12 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/04 17:24:38 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vector	parse_vector(char *token)
{
	char		**coords;
	t_vector	vector;

	coords = ft_split(token, ',');
	if (coords[0] == NULL || coords[1] == NULL || coords[2] == NULL)
	{
		printf("Error: Vector is NULL\n");
		ft_free_split(coords);
		return (vec_init(0, 0, 0));
	}
	vector = vec_init(-ft_atof(coords[0]), -ft_atof(coords[1]),
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
	if (colors[0] == NULL || colors[1] == NULL || colors[2] == NULL)
	{
		printf("Error: Color is NULL\n");
		ft_free_split(colors);
		return (color_init(0, 0, 0));
	}
	ft_free_split(colors);
	validate_rgb(color);
	return (color);
}
