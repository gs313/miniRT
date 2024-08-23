#include "../inc/minirt.h"

void sphere_init(t_sphere *sphere, double x, double y, double z, double radius, uint8_t r, uint8_t g, uint8_t b) {
    sphere->coord = (t_vector){x, y, z};
    sphere->radius = radius;
    sphere->color[0] = r;
    sphere->color[1] = g;
    sphere->color[2] = b;
}
