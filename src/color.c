/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:43:20 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/26 02:05:02 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int32_t rgb_to_int (int32_t r, int32_t g, int32_t b)
{
    return (r << 24 | g << 16 | b << 8 | 255);
}

int32_t cal_color (t_hit hit, t_vector ori, t_vector dir, t_scene *scene)
{
    float        dot;
    t_vector     hit_light;
    int          is_disk;
    t_vector     hit_normal;
    t_color      color;

    hit_light = vec_norm(vec_sub(scene->light.coord, hit.hitpoint));
    hit_normal = vec_norm(vec_sub(hit.hitpoint, scene->obj[hit.obj_id].coord));
    dot = vec_dot(hit_light, hit_normal);
    color.r = scene->obj[hit.obj_id].r * (1-dot) + (scene->light.r * dot);
    color.g = scene->obj[hit.obj_id].g * (1-dot) + (scene->light.g * dot);
    color.b = scene->obj[hit.obj_id].b * (1-dot) + (scene->light.b * dot);
    color.r = color.r * scene->light.ratio + scene->amb.r * scene->amb.ratio;
    color.g = color.g * scene->light.ratio + scene->amb.g * scene->amb.ratio;
    color.b = color.b * scene->light.ratio + scene->amb.b * scene->amb.ratio;
    return (rgb_to_int(color.r, color.g, color.b));
}
