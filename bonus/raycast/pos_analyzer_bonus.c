/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_analyzer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:06 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 09:55:29 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

///*
// *	Function: ft_get_door_collision
// *	-------------------------
// *	Check if the ray landed on a wall, a door or not
// *
// *	data: General data structure
// *	ray_pos: Position of the ray
// *	map: Map of the game
// *	dir_vect: Direction vector of the ray
// *
// *	Boolean if a wall or door is hit or not
// */
//
//void	ft_get_door_collision(t_door *door,
//		t_pos *door_collision, double ratio)
//{
//	t_pos	*start;
//	t_pos	*end;
//
//	start = door->surface->start;
//	end = door->surface->end;
//	door_collision->x = start->x + ratio * (end->x - start->x);
//	door_collision->y = start->y + ratio * (end->y - start->y);
//}
