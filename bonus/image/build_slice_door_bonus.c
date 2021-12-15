/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_slice_door_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:40 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 14:25:52 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_build_door_h_slice
 *	-------------------------
 *	Builds a horizontal door slice with the ceiling and floor
 *
 *	data: General data structure for the program
 *	door: Door to print
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_door_h_slice(t_data *data, t_door *door,
		float distance, int column)
{
	t_pos	temp_pos;

	ft_copy_pos(data->c_data->h_pos, &temp_pos);
	distance = ft_get_door_collision_horizontal(data, data->c_data);
	if (data->c_data->h_pos->x > door->surface->start->x
		&& data->c_data->h_pos->x < door->pos->x + 1)
		ft_build_world_door_slice(data, distance, column);
	else
	{
		ft_copy_pos(&temp_pos, data->c_data->h_pos);
		distance = ft_continue_dda_collision_bonus(data, data->c_data);
		ft_build_world_slice_bonus(data, data->c_data->c_pos, distance, column);
	}
}

/*
 *	Function: ft_build_door_v_slice
 *	-------------------------
 *	Builds a vertical door slice with the ceiling and floor
 *
 *	data: General data structure for the program
 *	door: Door to print
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_door_v_slice(t_data *data, t_door *door,
		float distance, int column)
{
	t_pos	temp_pos;

	ft_copy_pos(data->c_data->v_pos, &temp_pos);
	distance = ft_get_door_collision_vertical(data, data->c_data);
	if (data->c_data->v_pos->y > door->surface->start->y
		&& data->c_data->v_pos->y < door->pos->y + 1)
		ft_build_world_door_slice(data, distance, column);
	else
	{
		ft_copy_pos(&temp_pos, data->c_data->v_pos);
		distance = ft_continue_dda_collision_bonus(data, data->c_data);
		ft_build_world_slice_bonus(data, data->c_data->c_pos, distance, column);
	}	
}

/*
 *	Function: ft_build_door_slice
 *	-------------------------
 *	Fills in the image to be printed the world according to the column as one 
 *	slice in the image. Here the function also prints a textured
 *	floor and ceiling and the door only
 *
 *	data: General data structure for the program
 *	wall_pos: Position where the ray hit a wall
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_world_door_slice(t_data *data, float distance, int column)
{
	int				projected_height;
	t_slice_data	slice_data;

	projected_height = ((data->wall_height / distance) * data->dist_proj_plane);
	slice_data.img_line = data->img->address + (column * 4);
	if (distance > 32)
	{
		ft_set_data_ceiling(data, &slice_data, 0, projected_height);
		ft_build_ceiling_slice_sprite(data, data->img, &slice_data);
	}
	ft_set_data_wall(data, &slice_data, slice_data.limit, projected_height);
	slice_data.limit = (data->win_half_height) - (projected_height >> 1);
	ft_set_data_door(data, &slice_data, slice_data.limit, projected_height);
	ft_build_door_slice(data, data->img, &slice_data);
	if (distance > 32)
	{
		ft_set_data_floor(data, &slice_data, (data->win_half_height)
			+ (projected_height >> 1));
		ft_build_floor_slice_sprite(data, data->img, &slice_data);
	}
}

/*
 *	Function: ft_set_data_door
 *	-------------------------
 *	Set the slice data when a door is going to be printed
 *
 *	data: General data structure for the program
 *	slice_data: Data relative to the slice to be built in the image
 *	img_y: Row position for the current slice
 *	projected_height: Projected height for the door
 *
 */

void	ft_set_data_door(t_data *data,
		t_slice_data *slice_data, int img_y, int projected_height)
{
	slice_data->img_y = img_y;
	slice_data->limit = (data->win_half_height) + (projected_height >> 1);
	if (data->c_data->c_pos->collision_side == 'v')
	{
		slice_data->offset_x = (int)(data->c_data->v_pos->y
				* data->wall_height) % data->wall_width;
		if (data->c_data->curr_door->status == 1)
			slice_data->offset_x = slice_data->offset_x
				+ (data->wall_width / 3) % data->wall_width;
		slice_data->collision_side = 'v';
	}
	else if (data->c_data->c_pos->collision_side == 'h')
	{
		slice_data->offset_x = (int)(data->c_data->h_pos->x
				* data->wall_width) % data->wall_width;
		if (data->c_data->curr_door->status == 1)
			slice_data->offset_x = slice_data->offset_x
				+ (data->wall_width / 3) % data->wall_width;
		slice_data->collision_side = 'h';
	}
}

/*
 *	Function: ft_build_door_slice
 *	-------------------------
 *	Fills in the image to be printed the door according to the column as one 
 *	slice in the image
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *
 */

void	ft_build_door_slice(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	float		offset_y;
	char		*img_line;
	int			y;
	int			limit;

	y = slice_data->img_y - 1;
	offset_y = 0;
	slice_data->sprite_line = 0;
	limit = slice_data->limit;
	if (y < 0)
	{
		offset_y += slice_data->increment * abs(y);
		y = 0;
	}
	if (limit > data->win_height)
		limit = data->win_height;
	img_line = slice_data->img_line + (img->size_line * y);
	slice_data->sprite_line = (int)offset_y * data->i_door->size_line;
	slice_data->offset_y = offset_y;
	while (y++ < limit)
		ft_fill_cell_door(img, slice_data, &img_line, data->i_door);
}
