/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/20 21:18:42 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main()
{
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	void	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Tutorial Window", true);
	mlx_image_t	*img = mlx_new_image(mlx, 640, 360);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
