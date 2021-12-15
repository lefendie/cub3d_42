/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:06 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 16:00:57 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_same_grid_pos
 *	-------------------------
 *	Checks if two grid_pos positions are the same 
 *
 *	first_pos: First position to test
 *	second_pos: Second position to test
 *
 *	Returns: Boolean if they are the same or not
 */

int	ft_same_grid_pos(t_grid_pos *first_pos, t_grid_pos *second_pos)
{
	if (first_pos->x == second_pos->x && first_pos->y == second_pos->y)
		return (1);
	return (0);
}

/*
 *	Function: ft_get_dir_ray_from_player
 *	-------------------------
 *	Get the distance between the player and a position
 *
 *	data: General data structure
 *	evaluated_position: Position away from the player
 *	c_data: Contains raycast data
 *
 *	Returns: Distance between the player and the evaluated_position
 */

float	ft_get_distance_from_player(t_data *data,
		t_pos *evaluated_position, t_data_collision *c_data)
{
	float	distance;	

	distance = fabs((data->player->pixel_position->x - evaluated_position->x
				* data->wall_width) / c_data->cos_angle);
	distance = distance * c_data->cos_correct_angle;
	return (distance);
}
