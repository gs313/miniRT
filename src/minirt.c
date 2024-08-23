/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/24 05:03:19 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	hook(void *param)	// for key press events (ESC and Q key)
{
	mlx_t	*mlx;
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(mlx, MLX_KEY_Q))
	{
		mlx_close_window(mlx);
	}
}

int	main(void)
{
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	void	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Tutorial Window", true);
	mlx_image_t	*img = mlx_new_image(mlx, 640, 360);
	t_scene	scene;
	scene = scene_init(1);
	sphere_init(&scene.obj[0], vec_init(0, 0, 1), 255, 0, 0, 0.5);
	render(&scene);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, hook, mlx); 	// hook function for key press events
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
