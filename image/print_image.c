/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:33:13 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/16 10:26:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_create_new_image
 *	-------------------------
 *	Creates a new image from mlx and gives it to data
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_create_new_image(t_data *data)
{
	t_img_data	*img;

	img = data->img;
	img->self = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	img->address = mlx_get_data_addr(img->self, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (SUCCESS);
}

/*
 *	Function: ft_build_new_image
 *	-------------------------
 *	Use raycast to fill each column of the image with the right color texture
 *	We pass distance + 1 when building the slice so that the raycast can be
 *	made even though we are very close to the wall
 *
 *	data: General data structure where the map variable is located
 *
 */

void	ft_build_image(t_data *data)
{
	double	current_angle;
	double	right_angle;
	t_pos	*collision_pos;
	int		distance;
	int		column;

	right_angle = data->a_const->right_angle;
	column = data->win_width + 1;
	current_angle = ft_increment_angle(0, data->view_angle - (data->fov / 2),
			right_angle);
	while (--column >= 0)
	{
		ft_set_angle_values(data->c_data, data, current_angle);
		ft_set_dir_vector(data->c_data, data->a_const);
		distance = ft_get_dda_collision(data, data->c_data);
		collision_pos = data->c_data->c_pos;
		ft_build_world_slice(data, collision_pos, distance + 1, column);
		current_angle = ft_increment_angle(current_angle,
				data->angle_increment, right_angle);
	}
}

/*
 *	Function: ft_print_image
 *	-------------------------
 *	Make the image and prints it inside the window
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_print_image(t_data *data)
{
	ft_build_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->self,
		0, 0);
	return (SUCCESS);
}

/*
 *	Function: ft_get_color_from_rgb
 *	-------------------------
 *	Simplify the conversion from a string color to a rgb formated int color
 *
 *	char_rgb: String that contains a color
 *
 *	Returns: Color in int format
 */

int	ft_get_color_from_rgb(char *char_rgb)
{
	if (*char_rgb)
		return ((int)*(char_rgb + 3) << 24 | (int)*(char_rgb + 2) << 16
			| (int)*(char_rgb + 1) << 8 | (int)*(char_rgb));
	return (0);
}
