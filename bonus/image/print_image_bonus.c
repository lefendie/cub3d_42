/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:43:56 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/23 10:53:02 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_print_image_bonus
 *	-------------------------
 *	Make the image and prints it inside the window for the bonus part
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_print_image_bonus(t_data *data)
{
	ft_build_image_bonus(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->self,
		0, 0);
	return (0);
}

/*
 *	Function: ft_build_image_bonus
 *	-------------------------
 *	Use raycast to fill each column of the image with the right color texture
 *	for the bonus part
 *	We pass distance + 1 when building the slice so that the raycast can be
 *	made even though we are very close to the wall
 *
 *	data: General data structure where the map variable is located
 *
 */

void	ft_build_image_bonus(t_data *data)
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
		distance = ft_get_dda_collision_bonus(data, data->c_data);
		collision_pos = data->c_data->c_pos;
		ft_build_world_slice_bonus(data, collision_pos, distance + 1, column);
		current_angle = ft_increment_angle(current_angle,
				data->angle_increment, right_angle);
	}
}
