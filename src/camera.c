/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:34:25 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/24 04:50:08 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	camera_init(t_camera *cam, double x, double y, double z, t_vector dir, unsigned int dec)
{
	cam->x = x;
	cam->y = y;
	cam->z = z;
	cam->dir = dir;
	cam->dec = dec;
}

void	viewport_init(t_scene *scene)
{
	t_vector	u = vec_norm(vec_cross(scene->cam.dir, vec_init(0, 1, 0)));
	t_vector	v = vec_norm(vec_cross(u, scene->cam.dir));
	double		aspect_ratio = (double)WIN_WIDTH / (double)WIN_HEIGHT;
	double		viewport_width = 2.0f * tan((scene->cam.dec * M_PI / 180) / 2);
	double		viewport_height = viewport_width / aspect_ratio;
	scene->view.delta_u = vec_scale(u, (viewport_width/(double)WIN_WIDTH));
	scene->view.delta_v = vec_scale(v, (viewport_height/(double)WIN_HEIGHT));
	scene->view.pixel00_loc = vec_add(scene->cam.coord , vec_norm(scene->cam.dir));
	scene->view.pixel00_loc = vec_sub(scene->view.pixel00_loc, vec_scale(u, viewport_width/2));
	scene->view.pixel00_loc = vec_sub(scene->view.pixel00_loc, vec_scale(v, viewport_height/2));
	scene->view.pixel00_loc = vec_add(scene->view.pixel00_loc, vec_scale(scene->view.delta_u, 0.5));
	scene->view.pixel00_loc = vec_add(scene->view.pixel00_loc, vec_scale(scene->view.delta_v, 0.5));
	//still need to test
}

int		render (t_scene *scene)
{
	t_vector	pixel_loc;
	t_vector	ray_dir;
	uint32_t	color;
	int			x;
	int			y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_loc = vec_add(scene->view.pixel00_loc, vec_scale(scene->view.delta_u, x));
			pixel_loc = vec_add(pixel_loc, vec_scale(scene->view.delta_v, y));
			ray_dir = vec_norm(vec_sub(pixel_loc, scene->cam.coord));
			color = trace_ray(scene, scene->cam.coord, ray_dir);
			mlx_pixel_put(scene->img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

uint32_t	trace_ray(t_scene *scene, t_vector origin, t_vector dir)
{
	t_hit	hit;
	uint32_t color;

	hit = hit_closest(scene, origin, dir);
	if (hit.obj_id == -1)
		return (rgb_to_int(0, 0, 0, 0));
	color = rgb_to_int(scene->obj[hit.obj_id].r, scene->obj[hit.obj_id].g, scene->obj[hit.obj_id].b, 0);
	return (color);
}
