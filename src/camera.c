/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:34:25 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/03 21:42:59 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	camera_init(t_vector coord, t_vector dir, unsigned int dec)
{
	t_camera	cam;

	cam.coord = coord;
	cam.dir = dir;
	cam.dec = dec;
	return (cam);
}

void	viewport_init(t_scene *scene)
{
	t_viewport	view;
	t_vector	u;
	t_vector	v;
	double		viewport_width;
	double		viewport_height;

	u = vec_norm(vec_cross(scene->cam.dir, vec_init(0, 1, 0)));
	v = vec_norm(vec_cross(u, scene->cam.dir));
	viewport_width = 2.0f * tan((scene->cam.dec * M_PI / 180) / 2);
	viewport_height = viewport_width / ((double)WIN_WIDTH / (double)WIN_HEIGHT);
	view.delta_u = vec_scale(u, (viewport_width / (double)WIN_WIDTH));
	view.delta_v = vec_scale(v, (viewport_height / (double)WIN_HEIGHT));
	view.pixel00_loc = vec_add(scene->cam.coord, vec_norm(scene->cam.dir));
	view.pixel00_loc = vec_sub(view.pixel00_loc,
			vec_scale(u, viewport_width / 2));
	view.pixel00_loc = vec_sub(view.pixel00_loc,
			vec_scale(v, viewport_height / 2));
	view.pixel00_loc = vec_add(view.pixel00_loc, vec_scale(view.delta_u, 0.5));
	view.pixel00_loc = vec_add(view.pixel00_loc, vec_scale(view.delta_v, 0.5));
	scene->view = view;
}

int	render(t_scene *scene)
{
	t_vector	pixel_loc;
	t_vector	ray_dir;
	uint32_t	color;
	int			x;
	int			y;

	// is_camera_inside_object(scene->cam, scene->obj, scene->obj_count);
	viewport_init(scene);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_loc = vec_add(scene->view.pixel00_loc,
					vec_scale(scene->view.delta_u, x));
			pixel_loc = vec_add(pixel_loc, vec_scale(scene->view.delta_v, y));
			ray_dir = vec_norm(vec_sub(pixel_loc, scene->cam.coord));
			color = trace_ray(scene, scene->cam.coord, ray_dir);
			mlx_put_pixel(scene->img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

uint32_t	background_color(t_vector dir)
{
	double	t;

	t = 0.5 * (dir.y + 1.0);
	return (rgb_to_int((1.0 - t) * 255, (1.0 - t) * 255, 255));
}

uint32_t	trace_ray(t_scene *scene, t_vector origin, t_vector dir)
{
	t_hit		hit;
	uint32_t	color;

	hit = hit_closest(scene, origin, dir);
	if (hit.obj_id == -1)
		return (background_color(dir));
	color = cal_color(hit, scene);
	return (color);
}
