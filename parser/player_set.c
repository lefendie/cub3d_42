/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:54:54 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:38:54 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_initiate_player
 *	-------------------------
 *	Initiate the player data from the map configuration
 *
 *	data: General data structure where the map variable is located
 *	FOV: Field of view of the player
 *	speed: Speed of the player
 *
 *	Returns: Success state
 */

int	ft_initiate_player(t_data *data, int fov, int speed,
		void (*free_func)(void *data))
{
	data->player->pixel_position = NULL;
	ft_set_data_from_map(data, free_func);
	data->speed = speed;
	data->fov = fov;
	if (!ft_set_pixel_position(data->player, data->wall_height,
			data->wall_width))
		return (FAILURE);
	return (SUCCESS);
}

/*
 *	Function: ft_set_data_from_map
 *	-------------------------
 *	Get the position of the player from the map and fills the player data
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

void	ft_set_data_from_map(t_data *data, void (*free_func)(void *data))
{
	unsigned int	i;
	unsigned int	j;
	t_grid_pos		p_position;
	char			position;

	i = -1;
	j = -1;
	position = '\0';
	while (++i < data->map->map_size)
	{
		j = -1;
		while (data->map->self[i][++j])
		{
			if (data->map->self[i][j] == 'E' || data->map->self[i][j] == 'W'
					|| data->map->self[i][j] == 'S'
					|| data->map->self[i][j] == 'N')
			{	
				position = data->map->self[i][j];
				ft_set_grid_pos(&p_position, j, i);
				ft_set_player_position(data, &p_position, position, free_func);
			}
		}
	}
	if (!position)
		ft_exit_with_error_func("Player not found", free_func, data, 'r');
}

/*
 *	Function: ft_set_player_position
 *	-------------------------
 *	Set the player position from the map configuration
 *
 *	data: General data structure where the map variable is located
 *	i: Row index where the player position is found
 *	y: Column index where the player position is found
 *	position: Orientation of the player
 *
 *	Returns: Success state
 */

int	ft_set_player_position(t_data *data, t_grid_pos *p_position, char position,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	t_pos		*grid_position;

	if (data->view_angle != -1)
	{
		ft_set_grid_pos(&error_pos, p_position->x, p_position->y);
		free(data->player->pixel_position);
		free(data->player->grid_position);
		free_func(data);
		ft_exit_with_error_func("Many player positions found",
			ft_debug_error_pos, &error_pos, 'r');
	}
	ft_set_viewing_angle(position, data);
	grid_position = malloc(sizeof(t_pos));
	if (!(grid_position))
		return (FAILURE);
	grid_position->x = p_position->x + 0.5;
	grid_position->y = p_position->y + 0.5;
	data->player->grid_position = grid_position;
	return (SUCCESS);
}

/*
 *	Function: ft_set_viewing_angle
 *	-------------------------
 *	Set the center of the vision of the player according to
 *	the cardinal point
 *
 *	orientation: Cardinal point that defines the center of the vision
 *	data: General data structure where the map variable is located
 *
 */

void	ft_set_viewing_angle(char orientation, t_data *data)
{
	if (orientation == 'N')
		data->view_angle = M_PI / 2;
	else if (orientation == 'E')
		data->view_angle = 0;
	else if (orientation == 'S')
		data->view_angle = (3 * M_PI) / 2;
	else if (orientation == 'W')
		data->view_angle = M_PI;
}

/*
 *	Function: ft_set_pixel_position
 *	-------------------------
 *	Set the pixel position of the player according to its
 *	grid position
 *
 *	player: Data for the player
 *	wall_height: Height of a wall
 *	wall_width: Width of a wall
 *
 *	Returns: Success state
 */

int	ft_set_pixel_position(t_player *player, int wall_height, int wall_width)
{
	t_pos	*pixel_position;	

	pixel_position = malloc(sizeof(t_pos));
	if (!(pixel_position))
		return (FAILURE);
	pixel_position->x = (player->grid_position->x * wall_width);
	pixel_position->y = (player->grid_position->y * wall_height);
	player->pixel_position = pixel_position;
	return (SUCCESS);
}
