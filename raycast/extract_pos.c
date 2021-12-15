/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:48:22 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 15:50:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_adjust_pos_to_wall
 *	-------------------------
 *	Modify the position to get the next grid position without
 *	modifying too much the original position
 *
 *	pos: Pos to adjust
 *	dir_vect: Direction vector of the ray
 *
 */

void	ft_adjust_pos_to_wall(t_pos *pos, t_vect *dir_vect)
{
	if (pos->collision_side == 'v')
	{
		if (dir_vect->x == -1)
			pos->x -= 0.000001;
		else
			pos->x += 0.000001;
	}
	else
	{
		if (dir_vect->y == -1)
			pos->y -= 0.000001;
		else
			pos->y += 0.000001;
	}
}

/*
 *	Function: ft_copy_pos
 *	-------------------------
 *	Copy all the data from a position to another
 *
 *	pos_copy: Position to copy
 *	pos_copied: Position to paste
 *
 */

void	ft_copy_pos(t_pos *pos_copy, t_pos *pos_copied)
{
	pos_copied->x = pos_copy->x;
	pos_copied->y = pos_copy->y;
	pos_copied->collision_side = pos_copy->collision_side;
	pos_copied->obstacle_type = pos_copy->obstacle_type;
}
