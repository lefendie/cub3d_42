/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_viewing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:16:36 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 14:12:25 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_look_right
 *	-------------------------
 *	Makes the player vision rotate to the right
 *
 *	data: General data structure where the map variable is located
 *	speed: Speed of the player
 *
 */

void	ft_look_right(t_data *data, int speed)
{
	data->view_angle -= data->a_const->degree_to_radian * speed;
	if (data->view_angle < 0)
		data->view_angle = data->a_const->right_angle;
}

/*
 *	Function: ft_look_left
 *	-------------------------
 *	Makes the player vision rotate to the right
 *
 *	data: General data structure where the map variable is located
 *	speed: Speed of the player
 *
 */

void	ft_look_left(t_data *data, int speed)
{
	data->view_angle += data->a_const->degree_to_radian * speed;
	if (data->view_angle > data->a_const->right_angle)
		data->view_angle = 0;
}
