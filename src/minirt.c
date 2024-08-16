/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/16 18:42:04 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//this main is just for drawing
int	main (void)
{
	void	*mlx;
	char	*buffer;
	void	*img;
	void	*window;

	mlx = init_mlx();
	mlx_loop(mlx);
	return (0);
}
