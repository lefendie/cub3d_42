/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:52:34 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 17:42:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_collision_bonus
 *	-------------------------
 *	Check if the ray landed on a wall, a door or not
 *
 *	data: General data structure
 *	ray_pos: Position of the ray
 *	map: Map of the game
 *	dir_vect: Direction vector of the ray
 *
 *	Boolean if a wall or door is hit or not
 */

int	ft_collision_bonus(t_data *data,
		t_pos *ray_pos, char **map, t_vect *dir_vect)
{
	t_pos	temp_pos;
	int		x;
	int		y;
	int		hit;

	ft_copy_pos(ray_pos, &temp_pos);
	ft_adjust_pos_to_wall(&temp_pos, dir_vect);
	x = (int)temp_pos.x;
	y = (int)temp_pos.y;
	if (x < 0)
		x = 0;
	data->ceiling_color = 0;
	hit = (map[y][x] == '1' || map[y][x] == 'D');
	if (hit)
		ray_pos->obstacle_type = map[y][x];
	return (hit);
}

/*
 *	Function: ft_get_door_collision_vertical
 *	-------------------------
 *	Gives to v_pos the collision to the current_door
 *
 *	data: General data structure
 *	c_data: Contains raycast data
 *
 *	Returns: Distance from the player to the door/wall
 */

int	ft_get_door_collision_vertical(t_data *data, t_data_collision *c_data)
{
	double	increment;
	double	distance;
	t_pos	*vertical_pos;

	vertical_pos = c_data->v_pos;
	increment = (fabs(c_data->tan_angle)) / 2;
	increment *= c_data->dir_vect->y;
	vertical_pos->y += increment;
	distance = fabs((data->player->pixel_position->y - vertical_pos->y
				* data->wall_width) / c_data->sin_angle);
	distance = distance * c_data->cos_correct_angle;
	return (distance);
}

/*
 *	Function: ft_get_door_collision_horizontal
 *	-------------------------
 *	Gives to h_pos the collision to the current_door
 *
 *	data: General data structure
 *	c_data: Contains raycast data
 *
 *	Returns: Distance from the player to the door/wall
 */

int	ft_get_door_collision_horizontal(t_data *data, t_data_collision *c_data)
{
	double	increment;
	double	distance;
	t_pos	*horizontal_pos;

	horizontal_pos = c_data->h_pos;
	increment = (fabs(1 / c_data->tan_angle)) / 2;
	increment *= c_data->dir_vect->x;
	horizontal_pos->x += increment;
	distance = ft_get_distance_from_player(data, horizontal_pos, c_data);
	return (distance);
}
