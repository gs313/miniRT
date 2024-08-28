/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:46:16 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 02:53:08 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	l;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
