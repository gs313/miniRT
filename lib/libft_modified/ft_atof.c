/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:21:46 by ookamonu          #+#    #+#             */
/*   Updated: 2024/08/28 17:36:51 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double result = 0.0;
	double fraction = 0.0;
	int sign = 1;
	double divisor = 1.0;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else if (*str == '+')
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str++ - '0');
			divisor *= 10.0;
		}
		result += fraction / divisor;
	}
	return (result * sign);
}

/*
double	ft_atof(const char *str)
{
	double result = 0.0;
	double fraction = 0.0;
	int sign = 1;
	double divisor = 1.0;
	int decimal_point_seen = 0;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (decimal_point_seen)
			{
				fraction = fraction * 10.0 + (*str - '0');
				divisor *= 10.0;
			}
			else
			{
				result = result * 10.0 + (*str - '0');
			}
		}
		else if (*str == '.' && !decimal_point_seen)
		{
			decimal_point_seen = 1;
		}
		else
		{
			// printf("Error, invalid/extra character for ft_atof: %c\n", *str);
			break; // invalid character encountered
		}
		str++;
	}
	result += fraction / divisor;
	return result * sign;
}
*/

