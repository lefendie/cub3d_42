/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manjaro </var/spool/mail/manjaro>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:53:24 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/07 17:34:06 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_set_data_ceiling
 *	-------------------------
 *	Set the slice data for the ceiling part
 *
 *	data: General data structure where the map variable is located
 *	slice_data: Data relative to the slice to be built in the image
 *	img_y: Row position for the current slice
 *	projected_height: Projected height for the wall
 *
 */

void	ft_set_data_ceiling(t_data *data, t_slice_data *slice_data, int img_y,
		int projected_height)
{
	slice_data->img_y = img_y;
	slice_data->limit = (data->win_half_height) - (projected_height >> 1);
}

/*
 *	Function: ft_set_data_wall
 *	-------------------------
 *	Set the slice data for the wall part
 *
 *	data: General data structure where the map variable is located
 *	slice_data: Data relative to the slice to be built in the image
 *	img_y: Row position for the current slice
 *	projected_height: Projected height for the wall
 *
 */

void	ft_set_data_wall(t_data *data, t_slice_data *slice_data, int img_y,
		int projected_height)
{
	slice_data->img_y = img_y;
	slice_data->limit = (data->win_half_height) + (projected_height >> 1);
	slice_data->increment = (float)data->wall_width / projected_height;
}

/*
 *	Function: ft_set_data_floor
 *	-------------------------
 *	Set the slice data for the floor part
 *
 *	data: General data structure where the map variable is located
 *	slice_data: Data relative to the slice to be built in the image
 *	img_y: Row position for the current slice
 *	projected_height: Projected height for the wall
 *
 */

void	ft_set_data_floor(t_data *data, t_slice_data *slice_data, int img_y)
{
	slice_data->img_y = img_y;
	slice_data->limit = data->win_height;
}

/*
 *	Function: ft_set_data_collision
 *	-------------------------
 *	Set the slice data for the wall and chooses which column from
 *	the sprite to print according to collision data
 *
 *	data: General data structure where the map variable is located
 *	slice_data: Data relative to the slice to be built in the image
 *	wall_pos: Position where the ray hit a wall
 *
 */

void	ft_set_data_collision(t_data *data, t_slice_data *slice_data,
		t_pos *wall_pos)
{
	if (wall_pos->collision_side == 'v')
	{
		if (data->c_data->current_angle > data->a_const->up_angle
			&& data->c_data->current_angle < data->a_const->down_angle)
			slice_data->offset_x = data->wall_width - (int)(wall_pos->y
					* data->wall_height) % data->wall_width;
		else
			slice_data->offset_x = (int)(wall_pos->y
					* data->wall_height) % data->wall_width;
		slice_data->collision_side = 'v';
	}
	else if (wall_pos->collision_side == 'h')
	{
		if (data->c_data->current_angle > M_PI)
			slice_data->offset_x = data->wall_width - (int)(wall_pos->x
					* data->wall_width) % data->wall_width;
		else
			slice_data->offset_x = (int)(wall_pos->x
					* data->wall_width) % data->wall_width;
		slice_data->collision_side = 'h';
	}
}
