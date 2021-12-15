/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:09:34 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 14:17:27 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_set_grid_pos
 *	-------------------------
 *	Set the values for a grid_pos variable
 *
 *	grid_pos: grid_pos variable
 *	x: x position
 *	y: y position
 *
 */

void	ft_set_grid_pos(t_grid_pos *grid_pos, int x, int y)
{
	grid_pos->x = x;
	grid_pos->y = y;
}

/*
 *	Function: ft_set_pos
 *	-------------------------
 *	Set the values for a pos variable
 *
 *	pos: pos variable
 *	x: x position
 *	y: y position
 *
 */

void	ft_set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}
