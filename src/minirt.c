/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/26 17:09:45 by scharuka         ###   ########.fr       */
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
	// void	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Tutorial Window", true);
	// mlx_image_t	*img = mlx_new_image(mlx, 640, 360);
	t_scene	scene;
	// scene = scene_init(1);
	//two spheres
	scene = scene_init(1);
	// cylinder_init(0,&scene.obj[0], vec_init(0, 0, 50), vec_init(0, 1, 1), 0, 255, 0, 5, 10);

	// sphere_init(0, &scene.obj[0], vec_init(-10, 0, 20), 0, 255, 0, 5);
	sphere_init(0, &scene.obj[0], vec_init(0, 0, 30), 0, 0, 255, 5);
	scene.light = light_init(vec_init(1,5,1), 0.5, 255, 0, 0);
	scene.amb = amblight_init(0.2, 255, 255, 255);
	// plane_init(0, &scene.obj[0], vec_init(0, -1, 0), vec_init(0, 1, 0), 0, 255, 0);
	scene.cam = camera_init(10, 0, 0, vec_init(0, 0, 1), 100);
	render(&scene);
	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
	// mlx_loop_hook(scene.mlx, (void*)render, &scene); 	// hook function for key press events
	mlx_loop_hook(scene.mlx, hook, scene.mlx); 	// hook function for key press events
	mlx_loop(scene.mlx);
	mlx_terminate(scene.mlx);
	return (0);
}
