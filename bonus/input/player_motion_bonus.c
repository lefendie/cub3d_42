/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motion_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:12:45 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/18 17:06:09 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_adjust_to_doow
 *	-------------------------
 *	Collision function that allows proper collision for
 *	the user with the doors
 *
 *	data: General data structure where the map variable is located
 *	player_pos: Position of the player
 *	next_pos: Next position of the player from motion key input
 *
 *	Returns: Success state
 */

void	ft_adjust_to_door(t_data *data, t_pos *player_pos, t_pos *next_pos)
{
	int	x;
	int	y;
	int	n_x;
	int	n_y;

	x = (int)player_pos->x;
	y = (int)player_pos->y;
	n_x = (int)next_pos->x;
	n_y = (int)next_pos->y;
	if (ft_check_door_open(data, x, n_y))
	{
		player_pos->y = next_pos->y;
		if (ft_check_door_open(data, n_x, n_y))
			player_pos->x = next_pos->x;
	}
	else if (ft_check_door_open(data, n_x, y))
	{
		player_pos->x = next_pos->x;
		if (ft_check_door_open(data, n_x, n_y))
			player_pos->y = next_pos->y;
	}
}

/*
 *	Function: ft_move_forward_bonus
 *	-------------------------
 *	Moves the player forward according to the speed with door collision
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_move_forward_bonus(t_data *data, double view_angle, int speed)
{
	t_player	*player;
	t_pos		next_pos;

	player = data->player;
	ft_set_dir_vector(data->c_data, data->a_const);
	next_pos.y = player->pixel_position->y - sin(view_angle) * speed;
	next_pos.x = player->pixel_position->x + cos(view_angle) * speed;
	next_pos.x = next_pos.x / data->wall_width;
	next_pos.y = next_pos.y / data->wall_height;
	ft_adjust_to_wall(data->player->grid_position, &next_pos, data->map->self);
	ft_adjust_to_door(data, data->player->grid_position, &next_pos);
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_strafe_left_bonuss
 *	-------------------------
 *	Makes the player strafe left according to the speed with door collision
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_strafe_left_bonus(t_data *data, double view_angle, int speed)
{
	t_player	*player;
	t_pos		next_pos;

	player = data->player;
	ft_set_dir_vector(data->c_data, data->a_const);
	next_pos.y = player->pixel_position->y + sin(view_angle - (M_PI / 2))
		* speed;
	next_pos.x = player->pixel_position->x - cos(view_angle - (M_PI / 2))
		* speed;
	next_pos.x = next_pos.x / data->wall_width;
	next_pos.y = next_pos.y / data->wall_height;
	ft_adjust_to_wall(data->player->grid_position, &next_pos, data->map->self);
	ft_adjust_to_door(data, data->player->grid_position, &next_pos);
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_move_backward_bonus
 *	-------------------------
 *	Moves the player backward according to the speed with door collision
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_move_backward_bonus(t_data *data, double view_angle, int speed)
{
	t_player	*player;
	t_pos		next_pos;

	player = data->player;
	ft_set_dir_vector(data->c_data, data->a_const);
	next_pos.y = player->pixel_position->y + sin(view_angle) * speed;
	next_pos.x = player->pixel_position->x - cos(view_angle) * speed;
	next_pos.x = next_pos.x / data->wall_width;
	next_pos.y = next_pos.y / data->wall_height;
	ft_adjust_to_wall(data->player->grid_position, &next_pos, data->map->self);
	ft_adjust_to_door(data, data->player->grid_position, &next_pos);
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_strafe_right_bonus
 *	-------------------------
 *	Makes the player strafe right according to the speed with door collision
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_strafe_right_bonus(t_data *data, double view_angle, int speed)
{
	t_player	*player;
	t_pos		next_pos;

	player = data->player;
	ft_set_dir_vector(data->c_data, data->a_const);
	next_pos.y = player->pixel_position->y - sin(view_angle - (M_PI / 2))
		* speed;
	next_pos.x = player->pixel_position->x + cos(view_angle - (M_PI / 2))
		* speed;
	next_pos.x = next_pos.x / data->wall_width;
	next_pos.y = next_pos.y / data->wall_height;
	ft_adjust_to_wall(data->player->grid_position, &next_pos, data->map->self);
	ft_adjust_to_door(data, data->player->grid_position, &next_pos);
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}
