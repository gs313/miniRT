#include "../inc/minirt.h"
#include <math.h>
#include <stdio.h> // for debug prints

void render_scene(mlx_image_t *img, t_scene *scene) {
    // Implement the ray tracing algorithm
    // For each pixel in the image, cast a ray and determine the color
    for (uint32_t i = 0; i < img->width; ++i) {
        for (uint32_t y = 0; y < img->height; ++y) {
            // Cast ray and determine color based on the scene
            printf("Rendering pixel (%u, %u)\n", i, y); // Debug print
            uint32_t color = calculate_color(scene, i, y, img->width, img->height); // Pass image dimensions
            mlx_put_pixel(img, i, y, color);
        }
    }
}

uint32_t calculate_color(t_scene *scene, uint32_t x, uint32_t y, uint32_t img_width, uint32_t img_height) {
    // Convert pixel coordinates to normalized device coordinates
    double ndc_x = (2.0 * x) / img_width - 1.0;
    double ndc_y = 1.0 - (2.0 * y) / img_height;

    // Create a ray from the camera through the pixel
    t_ray ray;
    ray.origin = scene->camera.coord;
    ray.direction = (t_vector){ndc_x, ndc_y, -1.0}; // Assuming a simple camera looking along the -Z axis
    ray.direction = normalize(ray.direction);

    // Debug print to verify ray direction
    printf("Ray direction for pixel (%u, %u): (%f, %f, %f)\n", x, y, ray.direction.x, ray.direction.y, ray.direction.z);

    // Check for intersections with objects in the scene
    t_intersection closest_intersection;
    closest_intersection.distance = INFINITY;
    closest_intersection.hit = false; // Initialize hit to false
    for (int i = 0; i < scene->num_spheres; ++i) {
        t_sphere *sphere = &scene->spheres[i];
        t_intersection intersection = intersect_ray_sphere(ray, sphere);
        if (intersection.hit && intersection.distance < closest_intersection.distance) {
            closest_intersection = intersection;
        }
    }

    // Determine the color based on the closest intersection
    if (closest_intersection.hit) {
        t_sphere *hit_sphere = closest_intersection.object;
        printf("Hit sphere at (%f, %f, %f) with color (%d, %d, %d)\n",
               hit_sphere->coord.x, hit_sphere->coord.y, hit_sphere->coord.z,
               hit_sphere->color[0], hit_sphere->color[1], hit_sphere->color[2]); // Debug print
        return (hit_sphere->color[0] << 16) | (hit_sphere->color[1] << 8) | hit_sphere->color[2];
    } else {
        // Background color
        return 0x000000; // Black
    }
}

// Function to normalize a vector
t_vector normalize(t_vector v) {
    double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return (t_vector){v.x / length, v.y / length, v.z / length};
}

// Function to check for intersection between a ray and a sphere
t_intersection intersect_ray_sphere(t_ray ray, t_sphere *sphere) {
    t_intersection result;
    result.hit = false;
    result.distance = INFINITY; // Initialize distance to INFINITY

    t_vector oc = subtract(ray.origin, sphere->coord);
    double a = dot(ray.direction, ray.direction);
    double b = 2.0 * dot(oc, ray.direction);
    double c = dot(oc, oc) - sphere->radius * sphere->radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double t = (-b - sqrt(discriminant)) / (2.0 * a);
        if (t > 0) {
            result.hit = true;
            result.distance = t;
            result.object = sphere;
        }
    }

    return result;
}

// Function to subtract two vectors
t_vector subtract(t_vector a, t_vector b) {
    return (t_vector){a.x - b.x, a.y - b.y, a.z - b.z};
}

// Function to calculate the dot product of two vectors
double dot(t_vector a, t_vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// void render_scene(mlx_image_t *img, t_scene *scene) {
//     // Implement the ray tracing algorithm
//     // For each pixel in the image, cast a ray and determine the color
//     for (uint32_t i = 0; i < img->width; ++i) {
//         for (uint32_t y = 0; y < img->height; ++y) {
//             // Cast ray and determine color based on the scene
//             printf("Rendering pixel (%u, %u)\n", i, y); // Debug print
//             uint32_t color = calculate_color(scene, i, y, img->width, img->height); // Pass image dimensions
//             mlx_put_pixel(img, i, y, color);
//         }
//     }
// }

// uint32_t calculate_color(t_scene *scene, uint32_t x, uint32_t y, uint32_t img_width, uint32_t img_height) {
//     // Convert pixel coordinates to normalized device coordinates
//     double ndc_x = (2.0 * x) / img_width - 1.0;
//     double ndc_y = 1.0 - (2.0 * y) / img_height;

//     // Create a ray from the camera through the pixel
//     t_ray ray;
//     ray.origin = scene->camera.coord;
//     ray.direction = (t_vector){ndc_x, ndc_y, -1.0}; // Assuming a simple camera looking along the -Z axis
//     ray.direction = normalize(ray.direction);

//     // Check for intersections with objects in the scene
//     t_intersection closest_intersection;
//     closest_intersection.distance = INFINITY;
//     closest_intersection.hit = false; // Initialize hit to false
//     for (int i = 0; i < scene->num_spheres; ++i) {
//         t_sphere *sphere = &scene->spheres[i];
//         t_intersection intersection = intersect_ray_sphere(ray, sphere);
//         if (intersection.hit && intersection.distance < closest_intersection.distance) {
//             closest_intersection = intersection;
//         }
//     }

//     // Determine the color based on the closest intersection
//     if (closest_intersection.hit) {
//         t_sphere *hit_sphere = closest_intersection.object;
//         printf("Hit sphere at (%f, %f, %f) with color (%d, %d, %d)\n",
//                hit_sphere->coord.x, hit_sphere->coord.y, hit_sphere->coord.z,
//                hit_sphere->color[0], hit_sphere->color[1], hit_sphere->color[2]); // Debug print
//         return (hit_sphere->color[0] << 16) | (hit_sphere->color[1] << 8) | hit_sphere->color[2];
//     } else {
//         // Background color
//         return 0x000000; // Black
//     }
// }

// // Function to normalize a vector
// t_vector normalize(t_vector v) {
//     double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
//     return (t_vector){v.x / length, v.y / length, v.z / length};
// }

// // Function to check for intersection between a ray and a sphere
// t_intersection intersect_ray_sphere(t_ray ray, t_sphere *sphere) {
//     t_intersection result;
//     result.hit = false;
//     result.distance = INFINITY; // Initialize distance to INFINITY

//     t_vector oc = subtract(ray.origin, sphere->coord);
//     double a = dot(ray.direction, ray.direction);
//     double b = 2.0 * dot(oc, ray.direction);
//     double c = dot(oc, oc) - sphere->radius * sphere->radius;
//     double discriminant = b * b - 4 * a * c;

//     if (discriminant > 0) {
//         double t = (-b - sqrt(discriminant)) / (2.0 * a);
//         if (t > 0) {
//             result.hit = true;
//             result.distance = t;
//             result.object = sphere;
//         }
//     }

//     return result;
// }

// // Function to subtract two vectors
// t_vector subtract(t_vector a, t_vector b) {
//     return (t_vector){a.x - b.x, a.y - b.y, a.z - b.z};
// }

// // Function to calculate the dot product of two vectors
// double dot(t_vector a, t_vector b) {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }