/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_pos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:48:39 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/18 15:48:49 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_get_floor_pos
 *	-------------------------
 *	Get the floor pos where the ray would hit the ground
 *
 *	data: General data structure
 *	floor_pos: Position of the floor to set
 *	img_row: Row of the current slice
 *
 */

void	ft_get_floor_pos(t_data *data, t_pos *floor_pos, int img_row)
{
	float	floor_distance;

	floor_distance = PLAYER_HEIGHT / (img_row - (data->win_half_height));
	floor_distance = floor_distance * (data->dist_proj_plane
			/ data->c_data->cos_correct_angle);
	floor_pos->y = data->player->pixel_position->y - data->c_data->sin_angle
		* floor_distance;
	floor_pos->x = data->player->pixel_position->x + data->c_data->cos_angle
		* floor_distance;
}

/*
 *	Function: ft_get_ceiling_pos
 *	-------------------------
 *	Get the ceiling pos where the ray would hit the ground
 *
 *	data: General data structure
 *	ceiling_pos: Position of the floor to set
 *	img_row: Row of the current slice
 *
 */

void	ft_get_ceiling_pos(t_data *data, t_pos *ceiling_pos, int img_row)
{
	float	ceiling_distance;

	ceiling_distance = PLAYER_HEIGHT / ((data->win_half_height) - img_row);
	ceiling_distance = ceiling_distance * (data->dist_proj_plane
			/ data->c_data->cos_correct_angle);
	ceiling_pos->y = data->player->pixel_position->y - data->c_data->sin_angle
		* ceiling_distance;
	ceiling_pos->x = data->player->pixel_position->x + data->c_data->cos_angle
		* ceiling_distance;
}
