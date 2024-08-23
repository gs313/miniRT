
#include "../inc/minirt.h"

void	camera_init(t_camera *cam, double x, double y, double z, t_vector dir, unsigned int fov) {
	cam->coord = (t_vector){x, y, z};
	cam->dir = dir;
	cam->fov = fov;
}

void	viewport_init(t_scene *scene)
{
	t_camera *cam = &scene->camera; // Corrected the camera structure access
	t_viewport *view = &scene->view;

	// Calculate the aspect ratio
	double aspect_ratio = (double)WIN_WIDTH / (double)WIN_HEIGHT;

	// Calculate the viewport height and width
	double viewport_height = 2.0 * tan(cam->fov * M_PI / 360.0);
	double viewport_width = aspect_ratio * viewport_height;

	// Calculate the direction vectors for the viewport
	t_vector forward = cam->dir;
	t_vector right = vec_cross(forward, vec_init(0, 1, 0));
	t_vector up = vec_cross(right, forward);
	// t_vector right;
	// right.x = forward.y * 0 - 0 * forward.z;
	// right.y = 0 * forward.z - forward.x * 0;
	// right.z = forward.x * 1 - forward.y * 0;
	// t_vector up = vec_cross(right, forward);

	// Normalize the direction vectors
	right = vec_norm(right); // Updated to use vec_norm instead of vec_normalize
	up = vec_norm(up); // Updated to use vec_norm instead of vec_normalize

	// Scale the direction vectors by the viewport dimensions
	right = vec_scale(right, viewport_width / WIN_WIDTH);
	up = vec_scale(up, viewport_height / WIN_HEIGHT);

	// Calculate the location of the top-left corner of the viewport
	t_vector center = vec_add(cam->coord, forward);
	t_vector top_left = vec_sub(center, vec_scale(right, WIN_WIDTH / 2.0));
	top_left = vec_add(top_left, vec_scale(up, WIN_HEIGHT / 2.0));

	// Store the calculated values in the viewport structure
	view->delta_u = right;
	view->delta_v = vec_scale(up, -1); // Updated to use vec_scale with a negative value
	view->pixel00_loc = top_left;
}


/*void viewport_init(t_scene *scene) {
	// Calculate the aspect ratio
	double aspect_ratio = (double)WIN_WIDTH / (double)WIN_HEIGHT;

	// Calculate the viewport height and width in world space
	double viewport_height = 2.0 * tan((scene->cam.dec * M_PI / 180.0) / 2.0);
	double viewport_width = aspect_ratio * viewport_height;

	// Calculate the direction vectors for the viewport's horizontal and vertical axes
	t_vector horizontal = vec_init(viewport_width, 0, 0);
	t_vector vertical = vec_init(0, viewport_height, 0);

	// Calculate the location of the top-left corner of the viewport
	t_vector half_horizontal = vec_init(horizontal.x / 2, horizontal.y / 2, horizontal.z / 2);
	t_vector half_vertical = vec_init(vertical.x / 2, vertical.y / 2, vertical.z / 2);
	t_vector top_left = vec_subtract(vec_subtract(scene->cam.coord, half_horizontal), half_vertical);

	// Store the calculated values in the scene's viewport structure
	scene->view.delta_u = horizontal;
	scene->view.delta_v = vertical;
	scene->view.pixel00_loc = top_left;
}*/