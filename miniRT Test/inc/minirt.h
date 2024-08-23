#ifndef MINIRT_H
#define MINIRT_H

#include <MLX42/MLX42.h>
#include "../lib/libvec/vector.h"
#include <stdbool.h>
#include <stdint.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

// typedef struct {
// 	double x, y, z;
// } t_vector;

typedef struct {
	t_vector coord;
	t_vector dir;
	unsigned int fov;
    //double dec; // the dec member
} t_camera;

typedef struct {
	t_vector coord;
	t_vector normal;
	uint8_t color[3];
} t_plane;

typedef struct {
	t_vector coord;
	double radius;
	uint8_t color[3];
} t_sphere;

typedef struct {
	t_vector coord;
	t_vector dir;
	double diameter;
	double height;
	uint8_t color[3];
} t_cylinder;

// New definition in your header file (e.g., inc/minirt.h)
typedef struct {
    t_vector delta_u;
    t_vector delta_v;
    t_vector pixel00_loc;
} t_viewport;

typedef struct {
	t_camera camera;
	t_plane *planes;
    int num_spheres; // Add this field
	t_sphere *spheres;
    int num_cylinders; // Add this line
	t_cylinder *cylinders;
    t_viewport view; // Add the view field to the t_scene structure
	// Add other objects and lights as needed
} t_scene;



void camera_init(t_camera *cam, double x, double y, double z, t_vector dir, unsigned int fov);
void viewport_init(t_scene *scene);
void sphere_init(t_sphere *sphere, double x, double y, double z, double radius, uint8_t r, uint8_t g, uint8_t b);
void plane_init(t_plane *plane, double x, double y, double z, t_vector normal, uint8_t r, uint8_t g, uint8_t b);
void cylinder_init(t_cylinder *cylinder, double x, double y, double z, t_vector dir, double diameter, double height, uint8_t r, uint8_t g, uint8_t b);
void parse_scene(const char *filename, t_scene *scene);
void render_scene(mlx_image_t *img, t_scene *scene);


typedef struct {
    t_vector origin;
    t_vector direction;
} t_ray;

typedef struct {
    bool hit;
    double distance;
    t_sphere *object;
} t_intersection;

t_vector normalize(t_vector v);
t_intersection intersect_ray_sphere(t_ray ray, t_sphere *sphere);
t_vector subtract(t_vector a, t_vector b);
double dot(t_vector a, t_vector b);
uint32_t calculate_color(t_scene *scene, uint32_t x, uint32_t y, uint32_t img_width, uint32_t img_height);

#endif
