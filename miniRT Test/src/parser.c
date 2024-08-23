
#include "../inc/minirt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_scene(const char *filename, t_scene *scene) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[256];
    scene->num_spheres = 0; // Initialize the number of spheres

    // First pass: count the number of spheres
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "sp ", 3) == 0) {
            scene->num_spheres++;
        }
    }

    // Allocate memory for spheres
    scene->spheres = malloc(scene->num_spheres * sizeof(t_sphere));
    if (!scene->spheres) {
        fprintf(stderr, "Error: Could not allocate memory for spheres\n");
        exit(EXIT_FAILURE);
    }

    // Second pass: parse the scene
    rewind(file);
    int sphere_index = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "A ", 2) == 0) {
            // Parse ambient light
        } else if (strncmp(line, "C ", 2) == 0) {
            // Parse camera
            double x, y, z;
            t_vector dir;
            unsigned int fov;
            sscanf(line, "C %lf,%lf,%lf %lf,%lf,%lf %u", &x, &y, &z, &dir.x, &dir.y, &dir.z, &fov);
            camera_init(&scene->camera, x, y, z, dir, fov);
        } else if (strncmp(line, "sp ", 3) == 0) {
            // Parse sphere
            double x, y, z, radius;
            uint8_t r, g, b;
            sscanf(line, "sp %lf,%lf,%lf %lf %hhu,%hhu,%hhu", &x, &y, &z, &radius, &r, &g, &b);
            sphere_init(&scene->spheres[sphere_index], x, y, z, radius, r, g, b);
            sphere_index++;
        }
    }

    fclose(file);
}

// #include "../inc/minirt.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void parse_scene(const char *filename, t_scene *scene) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         fprintf(stderr, "Error: Could not open file %s\n", filename);
//         exit(EXIT_FAILURE);
//     }

//     char line[256];
//     scene->num_spheres = 0; // Initialize the number of spheres

//     // First pass: count the number of spheres
//     while (fgets(line, sizeof(line), file)) {
//         if (strncmp(line, "sp ", 3) == 0) {
//             scene->num_spheres++;
//         }
//     }

//     // Allocate memory for spheres
//     scene->spheres = malloc(scene->num_spheres * sizeof(t_sphere));
//     if (!scene->spheres) {
//         fprintf(stderr, "Error: Could not allocate memory for spheres\n");
//         exit(EXIT_FAILURE);
//     }

//     // Second pass: parse the scene
//     rewind(file);
//     int sphere_index = 0;
//     while (fgets(line, sizeof(line), file)) {
//         if (strncmp(line, "A ", 2) == 0) {
//             // Parse ambient light
//         } else if (strncmp(line, "C ", 2) == 0) {
//             // Parse camera
//             double x, y, z;
//             t_vector dir;
//             unsigned int fov;
//             sscanf(line, "C %lf,%lf,%lf %lf,%lf,%lf %u", &x, &y, &z, &dir.x, &dir.y, &dir.z, &fov);
//             camera_init(&scene->camera, x, y, z, dir, fov);
//         } else if (strncmp(line, "sp ", 3) == 0) {
//             // Parse sphere
//             double x, y, z, radius;
//             uint8_t r, g, b;
//             sscanf(line, "sp %lf,%lf,%lf %lf %hhu,%hhu,%hhu", &x, &y, &z, &radius, &r, &g, &b);
//             sphere_init(&scene->spheres[sphere_index], x, y, z, radius, r, g, b);
//             sphere_index++;
//         }
//     }

//     fclose(file);
// }

// // void parse_scene(const char *filename, t_scene *scene) {
// //     FILE *file = fopen(filename, "r");
// //     if (!file) {
// //         fprintf(stderr, "Error: Could not open file %s\n", filename);
// //         exit(EXIT_FAILURE);
// //     }

// //     char line[256];
// //     while (fgets(line, sizeof(line), file)) {
// //         if (strncmp(line, "A ", 2) == 0) {
// //             // Parse ambient light
// //         } else if (strncmp(line, "C ", 2) == 0) {
// //             // Parse camera
// //             double x, y, z;
// //             t_vector dir;
// //             unsigned int fov;
// //             sscanf(line, "C %lf,%lf,%lf %lf,%lf,%lf %u", &x, &y, &z, &dir.x, &dir.y, &dir.z, &fov);
// //             camera_init(&scene->camera, x, y, z, dir, fov);
// //         } else if (strncmp(line, "L ", 2) == 0) {
// //             // Parse light
// //         } else if (strncmp(line, "pl ", 3) == 0) {
// //             // Parse plane
// //             double x, y, z;
// //             t_vector normal;
// //             uint8_t r, g, b;
// //             sscanf(line, "pl %lf,%lf,%lf %lf,%lf,%lf %hhu,%hhu,%hhu", &x, &y, &z, &normal.x, &normal.y, &normal.z, &r, &g, &b);
// //             plane_init(&scene->planes[0], x, y, z, normal, r, g, b); // Assuming only one plane for simplicity
// //         } else if (strncmp(line, "sp ", 3) == 0) {
// //             // Parse sphere
// //             double x, y, z, radius;
// //             uint8_t r, g, b;
// //             sscanf(line, "sp %lf,%lf,%lf %lf %hhu,%hhu,%hhu", &x, &y, &z, &radius, &r, &g, &b);
// //             sphere_init(&scene->spheres[0], x, y, z, radius, r, g, b); // Assuming only one sphere for simplicity
// //         } else if (strncmp(line, "cy ", 3) == 0) {
// //             // Parse cylinder
// //             double x, y, z, diameter, height;
// //             t_vector dir;
// //             uint8_t r, g, b;
// //             sscanf(line, "cy %lf,%lf,%lf %lf,%lf,%lf %lf %lf %hhu,%hhu,%hhu", &x, &y, &z, &dir.x, &dir.y, &dir.z, &diameter, &height, &r, &g, &b);
// //             cylinder_init(&scene->cylinders[0], x, y, z, dir, diameter, height, r, g, b); // Assuming only one cylinder for simplicity
// //         }
// //     }
// //     fclose(file);
// // }
