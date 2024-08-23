#include "../inc/minirt.h"

void plane_init(t_plane *plane, double x, double y, double z, t_vector normal, uint8_t r, uint8_t g, uint8_t b) {
    plane->coord = (t_vector){x, y, z};
    plane->normal = normal;
    plane->color[0] = r;
    plane->color[1] = g;
    plane->color[2] = b;
}