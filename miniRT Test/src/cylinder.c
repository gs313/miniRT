#include "../inc/minirt.h"

void cylinder_init(t_cylinder *cylinder, double x, double y, double z, t_vector dir, double diameter, double height, uint8_t r, uint8_t g, uint8_t b) {
    cylinder->coord = (t_vector){x, y, z};
    cylinder->dir = dir;
    cylinder->diameter = diameter;
    cylinder->height = height;
    cylinder->color[0] = r;
    cylinder->color[1] = g;
    cylinder->color[2] = b;
}