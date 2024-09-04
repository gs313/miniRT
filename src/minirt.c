/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/04 17:37:18 by scharuka         ###   ########.fr       */
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
	render(&scene);
	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
	mlx_loop_hook(scene.mlx, hook, scene.mlx);
	mlx_loop(scene.mlx);
	free_scene(&scene);
	return (0);
}
