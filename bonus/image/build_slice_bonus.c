/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_slice_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:26:51 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:44:39 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_build_world_slice_bonus
 *	-------------------------
 *	Fills in the image to be printed the world according to the column as one 
 *	slice in the image (includes door building)
 *
 *	data: General data structure for the program
 *	wall_pos: Position where the ray hit a wall
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_world_slice_bonus(t_data *data, t_pos *wall_pos,
		float distance, int column)
{
	t_door	*door;
	t_pos	temp_pos;
	t_pos	*player_pos;

	if (data->c_data->c_pos->obstacle_type == 'D')
	{
		player_pos = data->player->grid_position;
		ft_copy_pos(data->c_data->c_pos, &temp_pos);
		ft_adjust_pos_to_wall(&temp_pos, data->c_data->dir_vect);
		ft_get_door(data, temp_pos.x, temp_pos.y);
		door = data->c_data->curr_door;
		if (door->side == 'h')
			ft_build_door_h_slice(data, door, distance, column);
		else
			ft_build_door_v_slice(data, door, distance, column);
	}
	else if (data->c_data->c_pos->obstacle_type == '1')
	{
		ft_build_world_wall_slice(data, wall_pos, distance, column);
	}	
}

/*
 *	Function: ft_build_world_wall_slice
 *	-------------------------
 *	Fills in the image to be printed the world according to the column as one 
 *	slice in the image. Here the function also prints a textured
 *	floor and ceiling and the wall only
 *
 *	data: General data structure for the program
 *	wall_pos: Position where the ray hit a wall
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_world_wall_slice(t_data *data, t_pos *wall_pos,
		float distance, int column)
{
	t_slice_data	slice_data;
	int				projected_height;

	projected_height = ((data->wall_height / distance) * data->dist_proj_plane);
	slice_data.img_line = data->img->address + (column * 4);
	if (distance > 32)
	{
		ft_set_data_ceiling(data, &slice_data, 0, projected_height);
		ft_build_ceiling_slice_sprite(data, data->img, &slice_data);
	}
	ft_set_data_collision(data, &slice_data, wall_pos);
	if (distance <= 32)
		slice_data.limit = (data->win_half_height) - (projected_height >> 1);
	ft_set_data_wall(data, &slice_data, slice_data.limit, projected_height);
	ft_build_wall_slice(data, data->img, &slice_data);
	if (distance > 32)
	{
		ft_set_data_floor(data, &slice_data, (data->win_half_height)
			+ (projected_height >> 1));
		ft_build_floor_slice_sprite(data, data->img, &slice_data);
	}
}

/*
 *	Function: ft_build_ceiling_slice_sprite
 *	-------------------------
 *	Builds a slice part with a textured ceiling
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *	
 */

void	ft_build_ceiling_slice_sprite(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	t_pos		ceiling_pos;
	char		*img_line;
	int			y;
	int			limit;

	y = 0;
	img_line = slice_data->img_line;
	limit = slice_data->limit;
	while (y <= limit)
	{
		ft_get_ceiling_pos(data, &ceiling_pos, y);
		slice_data->offset_x = (int)(ceiling_pos.x) % 64;
		slice_data->offset_y = (int)(ceiling_pos.y) % 64;
		slice_data->sprite_line = (int)slice_data->offset_y
			* data->i_ceiling->size_line;
		*(unsigned int *)img_line = ft_get_color_from_rgb(
				data->i_ceiling->address + (slice_data->offset_x * 4)
				+ slice_data->sprite_line);
		img_line += img->size_line;
		y++;
	}
}

/*
 *	Function: ft_build_floor_slice_sprite
 *	-------------------------
 *	Builds a slice part with a textured floor
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *	
 */

void	ft_build_floor_slice_sprite(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	t_pos		floor_pos;
	char		*img_line;
	int			y;
	int			limit;

	y = slice_data->img_y - 1;
	img_line = slice_data->img_line + img->size_line * y;
	limit = slice_data->limit;
	while (++y <= limit)
	{
		ft_get_floor_pos(data, &floor_pos, y);
		slice_data->offset_x = (int)(floor_pos.x) % 64;
		slice_data->offset_y = (int)(floor_pos.y) % 64;
		if (slice_data->offset_y > -1 && slice_data->offset_x > -1)
		{
			slice_data->sprite_line = (int)slice_data->offset_y
				* data->i_floor->size_line;
			*(unsigned int *)img_line = ft_get_color_from_rgb(
					data->i_floor->address + (slice_data->offset_x * 4)
					+ slice_data->sprite_line);
		}
		img_line += img->size_line;
	}
}
