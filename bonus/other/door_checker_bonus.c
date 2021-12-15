/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:52:13 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 09:39:59 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_player_in_door_range
 *	-------------------------
 *	Checks if the player is in the door range so he can interact
 *
 *	player_pos: Player position
 *	door: Door to print
 *
 *	Returns: Success state
 */

int	ft_player_in_door_range(t_pos *player_pos, t_door *door)
{
	if (door->side == 'h')
	{
		if (fabs(player_pos->y - door->surface->start->y) <= 1)
			return (SUCCESS);
	}
	else
	{
		if (fabs(player_pos->x - door->surface->start->x) <= 1)
			return (SUCCESS);
	}
	return (FAILURE);
}

/*
 *	Function: ft_check_player_facing_door
 *	-------------------------
 *	Checks if the player is in front of a door
 *
 *	map: Map of the game
 *	door: Door to print
 *	player_pos: Player position
 *	dir_vect: Player center of vision direction vector 
 *
 *	Returns: Boolean weither he is front of a doot or not
 */

int	ft_check_player_facing_door(t_map *map, t_door *door,
		t_pos *player_pos, t_vect *dir_vect)
{
	return (
		(door->side == 'v'
			&& !(player_pos->x - (int)player_pos->x < 0.5
				&& ft_check_player_door_area(map, player_pos)
				&& dir_vect->x == -1 )
			&& !(player_pos->x - (int)player_pos->x >= 0.5
				&& ft_check_player_door_area(map, player_pos)
				&& dir_vect->x == 1 )
		)
		|| (door->side == 'h'
			&& !(player_pos->y - (int)player_pos->y >= 0.5
				&& ft_check_player_door_area(map, player_pos)
				&& dir_vect->y == 1 )
			&& !(player_pos->y - (int)player_pos->y < 0.5
				&& ft_check_player_door_area(map, player_pos)
				&& dir_vect->y == -1 ))
	);
}

/*
 *	Function: ft_check_player_door_area
 *	-------------------------
 *	Check if the map cell where the player is is a door
 *
 *	map: Map of the game
 *	player_pos: Player position
 *
 *	Returns: Weither the player is in a door or not
 */

int	ft_check_player_door_area(t_map *map, t_pos *player_pos)
{
	int	i;
	int	in_door_area;

	i = 0;
	in_door_area = 0;
	while (map->door_list[i])
	{
		if (map->door_list[i]->pos->x == (int)player_pos->x
			&& map->door_list[i]->pos->y == (int)player_pos->y)
			in_door_area = 1;
		i++;
	}
	return (in_door_area);
}

/*
 *	Function: ft_check_door_open
 *	-------------------------
 *	Checks if a door is openned or not
 *
 *	map: Map of the game
 *	player_pos: Player position
 *
 *	Returns: Weither the door is openned
 */

int	ft_check_door_open(t_data *data, int x, int y)
{
	if (data->map->self[y][x] == 'D')
	{
		ft_get_door(data, x, y);
		return (data->c_data->curr_door->status == 1);
	}
	return (0);
}
