/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:55:02 by scharuka          #+#    #+#             */
/*   Updated: 2022/08/20 08:13:22 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	digit_needed(long long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		digit++;
		n = -n;
	}
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*ans;
	size_t		dg;
	long long	nb;

	nb = n;
	dg = digit_needed(nb);
	ans = malloc((dg + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	if (nb < 0)
	{
		ans[0] = '-';
		nb = -nb;
	}
	ans[dg] = '\0';
	dg--;
	while (1)
	{
		ans[dg] = (nb % 10) + '0';
		nb /= 10;
		dg--;
		if (nb == 0)
			return (ans);
	}
	return (ans);
}
