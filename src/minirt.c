/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:53:42 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/17 17:52:36 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//this main is just for drawing
// int	main (void)
// {
// 	void	*mlx = init_mlx()
// 	// char	*buffer;
// 	// void	*img;
// 	void	*window= mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
// 	// int		bits;
// 	// int		line_bytes;
// 	// int		endian;

// 	// mlx = init_mlx();
// 	// window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
// 	// img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
// 	// buffer = mlx_get_data_addr(img, &bits, &line_bytes, &endian);
// 	// //render
// 	// mlx_put_image_to_window(mlx, window, img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
    mlx_loop(mlx);
}
