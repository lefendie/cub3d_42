/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:42:17 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 17:44:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_set_door_surface
 *	-------------------------
 *	Set the initial door surface it takes
 *
 *	map: Map of the game
 *	door: Current door
 *
 */

void	ft_set_door_surface(char **map, t_door *door)
{
	int	x;
	int	y;

	x = door->pos->x;
	y = door->pos->y;
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
	{
		door->side = 'h';
		ft_set_pos(door->surface->start, door->pos->x, (door->pos->y) + 0.5);
		ft_set_pos(door->surface->end, (door->pos->x) + 1,
			(door->pos->y) + 0.5);
	}
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
	{
		door->side = 'v';
		ft_set_pos(door->surface->start, (door->pos->x) + 0.5, door->pos->y);
		ft_set_pos(door->surface->end, (door->pos->x) + 0.5, door->pos->y + 1);
	}
}

/*
 *	Function: ft_set_door_surface
 *	-------------------------
 *	Reset the initial door surface it had
 *
 *	door: Current door
 *
 */

void	ft_reset_door_surface(t_door *door)
{
	if (door->side == 'h')
	{
		ft_set_pos(door->surface->start, door->pos->x, (door->pos->y) + 0.5);
		ft_set_pos(door->surface->end, (door->pos->x) + 1,
			(door->pos->y) + 0.5);
	}
	else
	{
		ft_set_pos(door->surface->start, (door->pos->x) + 0.5, door->pos->y);
		ft_set_pos(door->surface->end, (door->pos->x) + 0.5, door->pos->y + 1);
	}
}

/*
 *	Function: ft_shift_door_surface
 *	-------------------------
 *	Change the door surface to make it look like it openned
 *
 *	door: Current door
 *
 */

void	ft_shift_door_surface(t_door *door)
{
	if (door->side == 'h')
	{
		ft_set_pos(door->surface->start, door->pos->x + 0.75,
			(door->pos->y) + 0.5);
		ft_set_pos(door->surface->end, (door->pos->x) + 1.75,
			(door->pos->y) + 0.5);
	}
	else
	{
		ft_set_pos(door->surface->start, (door->pos->x) + 0.5,
			door->pos->y + 0.75);
		ft_set_pos(door->surface->end, (door->pos->x) + 0.5,
			door->pos->y + 1.75);
	}
}
