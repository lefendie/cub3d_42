/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:02:43 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:32:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_build_world_slice
 *	-------------------------
 *	Fills in the image to be printed the world according to the column as one 
 *	slice in the image
 *
 *	data: General data structure for the program
 *	wall_pos: Position where the ray hit a wall
 *	distance: Distance from the player to wall_pos
 *	column: Column that will be filled for the image
 *
 */

void	ft_build_world_slice(t_data *data, t_pos *wall_pos,
		float distance, int column)
{
	t_slice_data	slice_data;
	int				projected_height;

	projected_height = ((data->wall_height / distance) * data->dist_proj_plane);
	slice_data.img_line = data->img->address + (column * 4);
	if (distance > 32)
	{
		ft_set_data_ceiling(data, &slice_data, 0, projected_height);
		ft_build_ceiling_slice(data, data->img, &slice_data);
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
		ft_build_floor_slice(data, data->img, &slice_data);
	}
}

/*
 *	Function: ft_build_ceiling_slice
 *	-------------------------
 *	Fills in the image to be printed the ceiling according to the column as one 
 *	slice in the image
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *
 */

void	ft_build_ceiling_slice(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	char	*img_ceiling_pos;
	int		y;
	int		limit;

	img_ceiling_pos = slice_data->img_line;
	y = slice_data->img_y;
	limit = slice_data->limit;
	while (y <= limit)
	{
		*(unsigned int *)img_ceiling_pos = data->ceiling_color;
		img_ceiling_pos += img->size_line;
		y++;
	}
}

/*
 *	Function: ft_build_wall_slice
 *	-------------------------
 *	Fills in the image to be printed the wall according to the column as one 
 *	slice in the image
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *
 */

void	ft_build_wall_slice(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	t_img_data	*sprite;
	float		offset_y;
	char		*img_line;
	int			y;
	int			limit;

	sprite = NULL;
	ft_get_sprite_address(data, &sprite, slice_data,
		data->c_data->current_angle);
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
	slice_data->sprite_line = (int)offset_y * sprite->size_line;
	slice_data->offset_y = offset_y;
	while (y++ <= limit)
		ft_fill_cell_wall(img, slice_data, &img_line, sprite);
}

/*
 *	Function: ft_build_floor_slice
 *	-------------------------
 *	Fills in the image to be printed the floor according to the column as one 
 *	slice in the image
 *
 *	data: General data structure for the program
 *	img: Image data that contains the image to print
 *	slice_data: Data relative to the slice to be built in the image
 *
 */

void	ft_build_floor_slice(t_data *data, t_img_data *img,
		t_slice_data *slice_data)
{
	char	*img_floor_pos;
	int		y;
	int		limit;

	y = slice_data->img_y;
	img_floor_pos = slice_data->img_line + img->size_line * y;
	limit = slice_data->limit;
	while (y <= limit)
	{
		*(unsigned int *)img_floor_pos = data->floor_color;
		img_floor_pos += img->size_line;
		y++;
	}
}

/*
 *	Function: ft_get_sprite_address
 *	-------------------------
 *	Gives the right wall to sprite to be built according to the
 *	cardinal points
 *
 *	data: General data structure for the program
 *	sprite: Image that will be used to build a slice
 *	slice_data: Data relative to the slice to be built in the image
 *	current_angle: Current angle for the ray
 *
 */

void	ft_get_sprite_address(t_data *data, t_img_data **sprite,
		t_slice_data *slice_data, double current_angle)
{
	if (slice_data->collision_side == 'v')
	{
		if (current_angle < data->a_const->down_angle
			&& current_angle > data->a_const->up_angle)
			*sprite = data->i_wall_we;
		else
			*sprite = data->i_wall_ea;
	}
	else
	{
		if (current_angle < data->a_const->left_angle)
			*sprite = data->i_wall_no;
		else
			*sprite = data->i_wall_so;
	}
}
