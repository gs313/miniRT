/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:51:59 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/29 00:16:38 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_amblight	amblight_init(double ratio, unsigned int r,
				unsigned int g, unsigned int b)
{
	t_amblight	amb;

	amb.ratio = ratio;
	amb.r = r;
	amb.g = g;
	amb.b = b;
	return (amb);
}

t_light	light_init(t_vector coord, double ratio)
{
	t_light	light;

	light.coord = coord;
	light.ratio = ratio;
	return (light);
}

t_scene	scene_init(unsigned int nb_obj)
{
	t_scene	scene;

	scene.cam = camera_init(vec_init(0, 0, 0), vec_init(0, 0, 1), 90);
	scene.obj = malloc(sizeof(t_object) * (nb_obj + 1));
	//scene.obj_count = nb_obj;
	scene.obj_count = 0;
	scene.amb = amblight_init(0.5, 255, 255, 255);
	scene.light = light_init(vec_init(0, 0, 0), 0.5);
	scene.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "====<< MiniRT >>====", true);	
	scene.img = mlx_new_image(scene.mlx, WIN_WIDTH, WIN_HEIGHT);
	return (scene);
}
