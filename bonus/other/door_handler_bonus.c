/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:41:46 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 09:44:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_get_door
 *	-------------------------
 *	Gives to the current door of data the door corresponding to the 
 *	coordinates in parameter
 *
 *	data: General data structure 
 *	x: x position in the map
 *	y: y position in the map
 *
 */

void	ft_get_door(t_data *data, int x, int y)
{
	int	wall_not_found;
	int	i;

	wall_not_found = 1;
	i = 0;
	while (wall_not_found && data->map->door_list[i])
	{
		if (data->map->door_list[i]->pos->x == x
			&& data->map->door_list[i]->pos->y == y)
		{
			data->c_data->curr_door = data->map->door_list[i];
			wall_not_found = 0;
		}	
		i++;
	}
}

/*
 *	Function: ft_change_door_status
 *	-------------------------
 *	Change the door status corresponding to weither it's open or not
 *
 *	door: Door to verify
 *
 */

void	ft_change_door_status(t_door *door)
{
	if (door->status == 0)
	{
		ft_shift_door_surface(door);
		door->status = 1;
	}
	else if (door->status == 1)
	{
		ft_reset_door_surface(door);
		door->status = 0;
	}
}

/*
 *	Function: ft_interact_with_door
 *	-------------------------
 *	Interact with the current door of data openning or closing it
 *
 *	data: General data structure 
 *
 */

void	ft_interact_with_door(t_data *data)
{
	t_door	*door;

	ft_set_angle_values(data->c_data, data, data->view_angle);
	ft_first_vertical_pos(data->player->grid_position, data->c_data);
	ft_first_horizontal_pos(data->player->grid_position, data->c_data);
	ft_collision_pos(data->c_data);
	ft_collision_bonus(data, data->c_data->c_pos, data->map->self,
		data->c_data->dir_vect);
	ft_adjust_pos_to_wall(data->c_data->c_pos, data->c_data->dir_vect);
	printf("interacting\n");
	if (data->c_data->c_pos->obstacle_type == 'D' )
	{
		ft_get_door(data, data->c_data->c_pos->x, data->c_data->c_pos->y);
		door = data->c_data->curr_door;
		if ((door->side == 'h' && data->c_data->h_pos->x > door->pos->x
				&& data->c_data->h_pos->x < door->pos->x + 1)
			&& ft_player_in_door_range(data->player->grid_position, door))
			ft_change_door_status(data->c_data->curr_door);
		if ((door->side == 'v' && data->c_data->v_pos->y > door->pos->y
				&& data->c_data->v_pos->y < door->pos->y + 1)
			&& ft_player_in_door_range(data->player->grid_position, door))
		{
			ft_change_door_status(data->c_data->curr_door);
		}
	}
}
