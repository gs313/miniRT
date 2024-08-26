/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:21:07 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/27 02:43:41 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/libvec/vector.h"
# include "../lib/MLX42/include/MLX42/MLX42.h" // MLX42 library header
# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define TRUE 1
# define FALSE 0
# define SMALL_NUM 0.00000001f
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color;

typedef struct s_camera
{
	t_vector		coord;
	t_vector		dir;
	unsigned int	dec;

}	t_camera;

typedef struct s_cylinder_attr
{
	t_vector	dir;
	double		d;
	double		h;
	double		t;
	double		t1;
	double		t2;
	double		t_cap;
	t_vector	hitpoint;
	double		hit_height;
}	t_cylinder_attr;

typedef struct s_object
{
	int				id;
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
}	t_light;

typedef struct s_viewport
{
	t_vector		delta_u;
	t_vector		delta_v;
	t_vector		pixel00_loc;
}	t_viewport;

typedef struct s_hit
{
	int			obj_id;
	t_vector	hitpoint;
	double		distance;
	int			is_disk;
}	t_hit;

typedef struct s_scene
{
	t_camera		cam;
	t_object		*obj;
	unsigned int	obj_count;
	t_amblight		amb;
	t_light			light;
	t_viewport		view;
	float			img_width;
	float			img_height;
	mlx_t			*mlx;
	mlx_image_t		*img;
}	t_scene;

//camera.c
t_camera		camera_init(t_vector coord, t_vector dir, unsigned int dec);
void			viewport_init(t_scene *scene);
int				render(t_scene *scene);
uint32_t		trace_ray(t_scene *scene, t_vector origin, t_vector dir);

// sphere.c
t_object		sphere_init(int id, t_vector coord, t_color color, double d);
t_hit			hit_sphere(t_object obj, t_vector origin, t_vector dir);

// color.c
int32_t			rgb_to_int(int32_t r, int32_t g, int32_t b);
int32_t			cal_color(t_hit hit, t_scene *scene);
int				is_shadow(t_scene *scene, t_vector origin,
					t_vector dir, t_hit hit);
t_color			color_init(unsigned int r, unsigned int g, unsigned int b);
int32_t			cal_util1(t_scene *scene, double dot, t_hit hit, t_vector hit_light);

//hit.c
t_hit			hit_init(void);
t_hit			hit_closest(t_scene *scene, t_vector origin, t_vector dir);

//scene.c
t_amblight		amblight_init(double ratio, unsigned int r, unsigned int g,
					unsigned int b);
t_light			light_init(t_vector coord, double ratio);
t_scene			scene_init(unsigned int nb_obj);

//plane.c
t_object		plane_init(int id, t_vector coord, t_vector dir, t_color color);
t_hit			hit_plane(t_object obj, t_vector origin, t_vector dir);

//cylinder.c
t_cylinder_attr	cylinder_attr_init(t_vector dir, double d, double h);
t_object		cylinder_init(int id, t_vector coord,
					t_cylinder_attr attr, t_color color);
t_hit			hit_cylinder(t_object obj, t_vector origin, t_vector dir);

#endif
