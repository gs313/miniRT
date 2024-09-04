/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:30 by scharuka         ###   ########.fr       */
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

bool	is_object(const char *token)
{
	return (ft_strncmp(token, "sp", 2) == 0
		|| ft_strncmp(token, "pl", 2) == 0
		|| ft_strncmp(token, "cy", 2) == 0);
}

unsigned int	count_objs(int fd)
{
	char			*line;
	unsigned int	count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\0' || line[0] == '#' || ft_isspace(line[0]))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_object(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	check_file_extension(const char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 2 || file[len - 1] != 't' || file[len - 2] != 'r'
		|| file[len - 3] != '.')
	{
		printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_scene			scene;
	int				fd;

	if (argc != 2)
	{
		printf("Usage: %s <scene.rt>\n", argv[0]);
		return (1);
	}
	check_file_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	scene = scene_init(count_objs(fd));
	parse_rt_file(&scene, argv[1]);
	printf("obj_count: %d\n", scene.obj_count);

	// scene.obj[0] = plane_init(0, vec_init(0, 0, 0), vec_init(0, 0, 1), color_init(0, 0, 255));
	render(&scene);
	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
	mlx_loop_hook(scene.mlx, hook, scene.mlx);
	mlx_loop(scene.mlx);
	free_scene(&scene);
	return (0);
}

// int	main(void)
// {
// 	// void *mlx = mlx_init();
// 	// void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
// 	// void	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Tutorial Window", true);
// 	// mlx_image_t	*img = mlx_new_image(mlx, 640, 360);
// 	t_scene	scene;
// 	// scene = scene_init(1);

// 	//good one test
// 	// scene = scene_init(3);
// 	// scene.obj[0] = cylinder_init(0, vec_init(0, 10, 50), cylinder_attr_init(vec_init(1, 1, 1), 10, 20), color_init(255, 0, 0));
// 	// scene.obj[1] = plane_init(1, vec_init(0, 5, 0), vec_init(0, 1, 0), color_init(0, 255, 0));
// 	// scene.obj[2] = sphere_init(2, vec_init(0, 0, 30), color_init(0, 0, 255), 5);
// 	// scene.light = light_init(vec_init(0,-5,0), 0.6);
// 	// scene.amb = amblight_init(0.2, 255, 255, 255);
// 	// scene.cam = camera_init(vec_init(0,0,0), vec_init(0, 0, 1), 100);

// 	//cy.rt
// 	// scene = scene_init(9);
// 	// scene.obj[0] = cylinder_init(0, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(1, 0, 0), 2, 6), color_init(255, 0, 0));
// 	// scene.obj[1] = cylinder_init(1, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0, 1, 0), 2, 6), color_init(255, 0, 0));
// 	// scene.obj[2] = cylinder_init(2, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0, 0, 1), 2, 6), color_init(255, 0, 0));
// 	// scene.obj[3] = cylinder_init(3, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0.70710678118, 0.70710678118, 0), 1, 7 ), color_init(0, 0, 255));
// 	// scene.obj[4] = cylinder_init(4, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0.70710678118, -0.70710678118, 0), 1, 7 ), color_init(0, 0, 255));
// 	// scene.obj[5] = cylinder_init(5, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0, 0.70710678118, 0.70710678118), 1, 7 ), color_init(0, 0, 255));
// 	// scene.obj[6] = cylinder_init(6, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0, -0.70710678118, 0.70710678118), 1, 7 ), color_init(0, 0, 255));
// 	// scene.obj[7] = cylinder_init(7, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(0.70710678118, 0, 0.70710678118), 1, 7 ), color_init(0, 0, 255));
// 	// scene.obj[8] = cylinder_init(8, vec_init(0,0,0),
// 	// 	cylinder_attr_init(vec_init(-0.70710678118, 0, 0.70710678118), 1, 7 ), color_init(0, 0, 255));
// 	// scene.light = light_init(vec_init(0,0,0), 0.6);
// 	// scene.amb = amblight_init(0.2, 255, 255, 255);
// 	// scene.cam = camera_init(vec_init(0,0,-15), vec_init(0, 0, 1), 50);

// 	scene = scene_init(2);
// 	scene.obj_count = 2;
// 	scene.obj[0] = sphere_init(0, vec_init(0, 0, 0), color_init(255, 0, 0), 5);
// 	scene.obj[1] = sphere_init(1, vec_init(0, 0, 10), color_init(0, 0, 255), 10);
// 	scene.light = light_init(vec_init(0,-5,-10), 1);
// 	scene.amb = amblight_init(0.2, 255, 255, 255);
// 	scene.cam = camera_init(vec_init(0,0,-30), vec_init(0, 0, 1), 100);



// 	render(&scene);
// 	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
// 	// mlx_loop_hook(scene.mlx, (void*)render, &scene); 	// hook function for key press events
// 	mlx_loop_hook(scene.mlx, hook, scene.mlx); 	// hook function for key press events
// 	mlx_loop(scene.mlx);
// 	mlx_terminate(scene.mlx);
// 	return (0);
// }
