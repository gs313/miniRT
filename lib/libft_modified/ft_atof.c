/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:21:46 by ookamonu          #+#    #+#             */
/*   Updated: 2024/09/03 08:21:06 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// double	ft_atof(const char *str)
// {
// 	double result = 0.0;
// 	double fraction = 0.0;
// 	int sign = 1;
// 	double divisor = 1.0;

// 	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		else if (*str == '+')
// 			sign = 1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 		result = result * 10.0 + (*str++ - '0');
// 	if (*str == '.')
// 	{
// 		str++;
// 		while (*str >= '0' && *str <= '9')
// 		{
// 			fraction = fraction * 10.0 + (*str++ - '0');
// 			divisor *= 10.0;
// 		}
// 		result += fraction / divisor;
// 	}
// 	return (result * sign);
// }

static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

static const char	*handle_sign(const char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		else if (*str == '+')
			*sign = 1;
		str++;
	}
	return (str);
}

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
		result = result * 10.0 + (*(*str)++ - '0');
	return (result);
}

static double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fraction = fraction * 10.0 + (*(*str)++ - '0');
			divisor *= 10.0;
		}
	}
	return (fraction / divisor);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	sign = 1;
	str = skip_whitespace(str);
	str = handle_sign(str, &sign);
	result = parse_integer_part(&str);
	result += parse_fractional_part(&str);
	return (result * sign);
}
