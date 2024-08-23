
#include "../inc/minirt.h"
#include <stdlib.h>
#include <stdio.h> // the necessary header for puts

// function to close the window with ESC or Q key
void	hook(void *param)
{
	mlx_t *mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(mlx, MLX_KEY_Q))
	{
		mlx_close_window(mlx);
	}
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <scene_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *scene_file = argv[1];

    mlx_t *mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
    if (!mlx) {
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }

    mlx_image_t *img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!img) {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }

    if (mlx_image_to_window(mlx, img, 0, 0) == -1) {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }

    t_scene scene;
    parse_scene(scene_file, &scene);

    // Debug print to verify scene parsing
    printf("Number of spheres: %d\n", scene.num_spheres);
    for (int i = 0; i < scene.num_spheres; ++i) {
        printf("Sphere %d: coord=(%f, %f, %f), radius=%f, color=(%d, %d, %d)\n",
               i, scene.spheres[i].coord.x, scene.spheres[i].coord.y, scene.spheres[i].coord.z,
               scene.spheres[i].radius, scene.spheres[i].color[0], scene.spheres[i].color[1], scene.spheres[i].color[2]);
    }

    viewport_init(&scene); // Ensure viewport is initialized

    render_scene(img, &scene);

    // Set the hook function for key press events
    mlx_loop_hook(mlx, hook, mlx);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}

// int main(int argc, char *argv[]) {
// 	if (argc != 2) {
// 		fprintf(stderr, "Usage: %s <scene_file>\n", argv[0]);
// 		return EXIT_FAILURE;
// 	}

// 	const char *scene_file = argv[1];

// 	mlx_t *mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
// 	if (!mlx) {
// 		puts(mlx_strerror(mlx_errno));
// 		return EXIT_FAILURE;
// 	}

// 	mlx_image_t *img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
// 	if (!img) {
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return EXIT_FAILURE;
// 	}

// 	if (mlx_image_to_window(mlx, img, 0, 0) == -1) {
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return EXIT_FAILURE;
// 	}

// 	t_scene scene;
// 	parse_scene(scene_file, &scene);

// 	// Debug print to verify scene parsing
// 	printf("Number of spheres: %d\n", scene.num_spheres);
// 	for (int i = 0; i < scene.num_spheres; ++i) {
// 		printf("Sphere %d: coord=(%f, %f, %f), radius=%f, color=(%d, %d, %d)\n",
// 			   i, scene.spheres[i].coord.x, scene.spheres[i].coord.y, scene.spheres[i].coord.z,
// 			   scene.spheres[i].radius, scene.spheres[i].color[0], scene.spheres[i].color[1], scene.spheres[i].color[2]);
// 	}

// 	render_scene(img, &scene);

// 	// Set the hook function for key press events
// 	mlx_loop_hook(mlx, hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return EXIT_SUCCESS;
// }
