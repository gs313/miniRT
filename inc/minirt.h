/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:21:07 by scharuka          #+#    #+#             */
/*   Updated: 2024/09/03 22:05:15 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libvec/vector.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft_modified/libft.h"
# include "../lib/libft_modified/get_next_line.h"
# define WIN_WIDTH 900
# define WIN_HEIGHT 600
// # define WIN_WIDTH 1920
// # define WIN_HEIGHT 1080
# define MIN_COORD -10000.0
# define MAX_COORD 10000.0
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define LIGHT "L"
# define AMBIENT_LIGHT "A"
# define CAMERA "C"
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

typedef struct s_quard
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t;
}	t_quard;

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
int32_t			cal_util1(t_scene *scene, double dot, t_hit hit,
					t_vector hit_light);

//hit.c
t_hit			hit_init(void);
t_hit			hit_closest(t_scene *scene, t_vector origin, t_vector dir);
t_hit			set_hit(t_object obj, t_vector hitpoint,
					double distance, int is_disk);

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
t_hit			hit_cap(t_object obj, t_vector origin, t_vector dir, double t);

//util.c
double			ft_min(double a, double b);
double			ft_max(double a, double b);
t_quard			set_quard(t_object obj, t_vector origin, t_vector dir);
unsigned int	count_objs(int fd);
void			ft_free_split(char **split);

//parser
void			parse_rt_file(t_scene *scene, const char *filename);
void			parse_line(t_scene *scene, char *line);
void			parse_token(t_scene *scene, char **tokens);
void			parse_ambient(t_scene *scene, char **tokens);
void			parse_camera(t_scene *scene, char **tokens);
void			parse_light(t_scene *scene, char **tokens);
void			parse_sphere(t_scene *scene, char **tokens);
void			parse_plane(t_scene *scene, char **tokens);
void			parse_cylinder(t_scene *scene, char **tokens);
t_vector		parse_vector(char *token);
t_color			parse_color(char *token);
void			is_camera_inside_object(t_camera cam, t_object *obj,
					unsigned int obj_count);

// validate.c
bool			validate_double_range(double value, double min, double max);
bool			validate_int_range(int value, int min, int max);
void			validate_rgb(t_color color);
void			validate_vector_range(t_vector vec, double min, double max);

#endif
