/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:52:34 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/12 15:53:16 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_collision_side
 *	-------------------------
 *	Gives the side where the ray landed on the wall
 *
 *	c_data: Contains raycast data
 *
 *	Returns: Side where the ray landed
 */

char	ft_collision_side(t_data_collision *c_data)
{
	if (c_data->dir_vect->x == -1)
	{
		if (c_data->h_pos->x > c_data->v_pos->x)
			return ('h');
		else
			return ('v');
	}
	else
	{
		 if (c_data->h_pos->x <= c_data->v_pos->x)
			return ('h');
		else
			return ('v');
	}
}

/*
 *	Function: ft_check_collision
 *	-------------------------
 *	Check if the ray landed on a wall or not
 *
 *	ray_pos: Position of the ray
 *	map: Map of the game
 *	dir_vect: Direction vector of the ray
 *
 *	Boolean if a wall is hit or not
 */

int	ft_check_collision(t_pos *ray_pos, char **map, t_vect *dir_vect)
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
	hit = ((map[y][x] > '0' && map[y][x] < '9'));
	if (hit)
		ray_pos->obstacle_type = map[y][x];
	return (hit);
}

/*
 *	Function: ft_collision_pos
 *	-------------------------
 *	Choose between the ray that land horizontal and the vertical one,
 *	which one is on the wall and copy the position to c_pos
 *
 *	c_data: Contains raycast data
 *
 *	Boolean if a wall is hit or not
 */

void	ft_collision_pos(t_data_collision *c_data)
{
	if (c_data->dir_vect->x == -1)
	{
		if (c_data->h_pos->x > c_data->v_pos->x)
			ft_copy_pos(c_data->h_pos, c_data->c_pos);
		else
			ft_copy_pos(c_data->v_pos, c_data->c_pos);
	}
	else
	{
		if (c_data->h_pos->x < c_data->v_pos->x)
			ft_copy_pos(c_data->h_pos, c_data->c_pos);
		else
			ft_copy_pos(c_data->v_pos, c_data->c_pos);
	}
}
