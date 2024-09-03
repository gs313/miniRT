/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:39:25 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 10:35:01 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	validate_double_range(double value, double min, double max)
{
	if (value < min || value > max)
	{
		printf("Error: Value %f out of range [%f, %f]\n", value, min, max);
		exit(EXIT_FAILURE);
	}
	return (true);
}

bool	validate_int_range(int value, int min, int max)
{
	if (value < min || value > max)
	{
		printf("Error: Value %d out of range [%d, %d]\n", value, min, max);
		exit(EXIT_FAILURE);
	}
	return (true);
}

void	validate_rgb(t_color color)
{
	if (!validate_int_range(color.r, 0, 255) || !validate_int_range(color.g,
			0, 255) || !validate_int_range(color.b, 0, 255))
	{
		printf("Error: RGB values out of range [0, 255]\n");
		exit(EXIT_FAILURE);
	}
}

void	validate_vector_range(t_vector vec, double min, double max)
{
	if (!validate_double_range(vec.x, min, max) || !validate_double_range(vec.y,
			min, max) || !validate_double_range(vec.z, min, max))
	{
		printf("Error: Vector values out of range [%f, %f]\n", min, max);
		exit(EXIT_FAILURE);
	}
}
