/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:34:25 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/20 21:18:22 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	camera_init(t_camera *cam, double x, double y, double z, t_vector dir, unsigned int dec)
{
	cam->x = x;
	cam->y = y;
	cam->z = z;
	cam->dir = dir;
	cam->dec = dec;
}

void	viewport_init()
{
	int focus = 1;
}
