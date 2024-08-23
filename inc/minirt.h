/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:21:07 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/23 23:27:31 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <stdio.h>
# include "../lib/libvec/vector.h"
# include "../lib/MLX42/include/MLX42/MLX42.h" // MLX42 library header
# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# define M_PI 3.14159265358979323846


typedef	struct s_camera
{
	double			x;
	double			y;
	double			z;
	t_vector		coord;
	t_vector		dir;
	unsigned int	dec;

}t_camera;

typedef struct s_object
{
	unsigned int	type;
	t_vector		coord;
	t_vector		dir;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			d;
	double			h;
}	t_object;

typedef struct s_amblight
{
	double			ratio;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_amblight;

typedef struct s_light
{
	t_vector		coord;
	double			ratio;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_light;

typedef struct s_viewport
{
	t_vector		delta_u;
	t_vector		delta_v;
	t_vector		pixel00_loc;
}	t_viewport;

typedef struct s_hit
{
	int			opj_id;
	t_vector	hitpoint;
	double		
} t_hit;
typedef struct s_scene
{
	t_camera		cam;
	t_object		*obj;
	unsigned int	obj_count;
	t_amblight		amb;
	t_light			*light;
	unsigned int	light_count;
	t_viewport		view;
	float			img_width;
	float			img_height;
	mlx_t			*mlx;
	mlx_image_t		*img;
}	t_scene;

//camera.c
void	camera_init(t_camera *cam, double x, double y, double z, t_vector dir, unsigned int dec);
void	viewport_init(t_scene *scene);

// sphere.c
void	sphere_init(t_object *obj, t_vector coord, unsigned int r, unsigned int g, unsigned int b, double d);

// color.c
int32_t rgb_to_int(int32_t r, int32_t g, int32_t b, int32_t a);

#endif
