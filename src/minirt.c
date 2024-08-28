/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/29 03:26:24 by ookamonu         ###   ########.fr       */
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

// int	main(void)
// {
// 	// void *mlx = mlx_init();
// 	// void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
// 	// void	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Tutorial Window", true);
// 	// mlx_image_t	*img = mlx_new_image(mlx, 640, 360);
// 	t_scene	scene;
// 	// scene = scene_init(1);
// 	scene = scene_init(3);
// 	scene.obj[0] = cylinder_init(0, vec_init(0, 10, 50), cylinder_attr_init(vec_init(1, 1, 1), 10, 20), color_init(255, 0, 0));
// 	scene.obj[1] = plane_init(1, vec_init(0, 5, 0), vec_init(0, 1, 0), color_init(0, 255, 0));
// 	scene.obj[2] = sphere_init(2, vec_init(0, 0, 30), color_init(0, 0, 255), 5);
// 	scene.light = light_init(vec_init(0,-5,0), 0.6);
// 	scene.amb = amblight_init(0.2, 255, 255, 255);
// 	scene.cam = camera_init(vec_init(0,0,0), vec_init(0, 0, 1), 100);
// 	render(&scene);
// 	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
// 	// mlx_loop_hook(scene.mlx, (void*)render, &scene); 	// hook function for key press events
// 	mlx_loop_hook(scene.mlx, hook, scene.mlx); 	// hook function for key press events
// 	mlx_loop(scene.mlx);
// 	mlx_terminate(scene.mlx);
// 	return (0);
// }

unsigned int	count_objs(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	unsigned int count = 0;
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		char **tokens = ft_split(line, ' ');
		if (tokens[0] != NULL && ft_strlen(tokens[0]) > 0)
		{
			if (ft_strncmp(tokens[0], SPHERE, 2) == 0 ||
				ft_strncmp(tokens[0], PLANE, 2) == 0 ||
				ft_strncmp(tokens[0], CYLINDER, 2) == 0)
				count++;
		}
		ft_free_split(tokens);
		free(line);
	}
	close(fd);
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <scene.rt>\n", argv[0]);
		return (1);
	}
	
	t_scene scene = scene_init(count_objs(argv[1]));
	parse_rt_file(&scene, argv[1]);

	render(&scene);
	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
	mlx_loop_hook(scene.mlx, hook, scene.mlx);
	mlx_loop(scene.mlx);
	mlx_terminate(scene.mlx);
	return (0);
}