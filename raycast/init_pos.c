/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:57:26 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 16:09:51 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_first_horizontal_pos
 *	-------------------------
 *	Get the first horizontal raycast position from the player
 *
 *	grid_pos: Position where starts the ray
 *	c_data: Contains raycast data
 *
 */

void	ft_first_horizontal_pos(t_pos *grid_pos, t_data_collision *c_data)
{
	t_pos	*horizontal_pos;

	horizontal_pos = c_data->h_pos;
	if (c_data->current_angle < M_PI)
		horizontal_pos->y = (int)grid_pos->y;
	else
		horizontal_pos->y = (int)(grid_pos->y) + 1;
	horizontal_pos->x = grid_pos->x + (grid_pos->y - horizontal_pos->y)
		/ c_data->tan_angle;
	horizontal_pos->collision_side = 'h';
}

/*
 *	Function: ft_first_vertical_pos
 *	-------------------------
 *	Get the first vertical raycast position from the player
 *
 *	grid_pos: Position where starts the ray
 *	c_data: Contains raycast data
 *
 */

void	ft_first_vertical_pos(t_pos *grid_pos, t_data_collision *c_data)
{
	t_pos	*vertical_pos;

	vertical_pos = c_data->v_pos;
	if (c_data->dir_vect->x == -1)
		vertical_pos->x = (int)grid_pos->x;
	else
		vertical_pos->x = (int)(grid_pos->x) + 1;
	vertical_pos->y = grid_pos->y + (grid_pos->x - vertical_pos->x)
		* c_data->tan_angle;
	vertical_pos->collision_side = 'v';
}
