/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:01:53 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 14:11:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_adjust_to_wall
 *	-------------------------
 *	Collision function that allows proper collision for
 *	the user with the walls
 *
 *	player_pos: Position of the player
 *	next_pos: Next position of the player from motion key input
 *	map: Map of the game
 *
 *	Returns: Success state
 */

int	ft_adjust_to_wall(t_pos *player_pos, t_pos *next_pos, char **map)
{
	int	x;
	int	y;
	int	n_x;
	int	n_y;

	x = (int)player_pos->x;
	y = (int)player_pos->y;
	n_x = (int)next_pos->x;
	n_y = (int)next_pos->y;
	if (map[n_y][x] != '1' && map[n_y][x] != 'D')
	{
		player_pos->y = next_pos->y;
		if (map[n_y][n_x] != '1' && map[n_y][n_x] != 'D')
			player_pos->x = next_pos->x;
		return (SUCCESS);
	}
	else if (map[y][n_x] != '1' && map[y][n_x] != 'D')
	{
		player_pos->x = next_pos->x;
		if (map[n_y][n_x] != '1' && map[n_y][n_x] != 'D')
			player_pos->y = next_pos->y;
		return (SUCCESS);
	}
	return (FAILURE);
}

/*
 *	Function: ft_move_forward
 *	-------------------------
 *	Moves the player forward according to the speed
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_move_forward(t_data *data, double view_angle, int speed)
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
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_strafe_left
 *	-------------------------
 *	Makes the player strafe left according to the speed
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_strafe_left(t_data *data, double view_angle, int speed)
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
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_move_backward
 *	-------------------------
 *	Moves the player backward according to the speed
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_move_backward(t_data *data, double view_angle, int speed)
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
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}

/*
 *	Function: ft_strafe_right
 *	-------------------------
 *	Makes the player strafe right according to the speed
 *
 *	data: General data structure where the map variable is located
 *	view_angle: Center of the vision of the user
 *	speed: Speed of the player
 *
 */

void	ft_strafe_right(t_data *data, double view_angle, int speed)
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
	player->pixel_position->x = player->grid_position->x * data->wall_width;
	player->pixel_position->y = player->grid_position->y * data->wall_height;
}
