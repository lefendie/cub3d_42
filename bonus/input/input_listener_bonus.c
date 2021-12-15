/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_listener_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 07:41:30 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/20 21:30:45 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_listen_viewing_bonus
 *	-------------------------
 *	Listens for the key relatives for the viewing of the user
 *	with the ability to look down and up
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_viewing_bonus(int key, t_data *data)
{
	int	speed;

	speed = data->speed;
	if (key == 65363)
		ft_look_right(data, speed);
	if (key == 65361)
		ft_look_left(data, speed);
	if (key == 65362)
	{
		data->win_half_height += speed;
		if (data->win_half_height > data->win_height)
			data->win_half_height = data->win_height;
	}
	if (key == 65364)
	{
		data->win_half_height -= speed;
		if (data->win_half_height < 0)
			data->win_half_height = 0;
	}
	return (0);
}

/*
 *	Function: ft_listen_action
 *	-------------------------
 *	Listen to action from the user, releasing the mouse or interacting with
 *	a door
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_action(int key, t_data *data)
{
	if (key == 'r')
		ft_release_mouse_control(data);
	if (key == 'e')
	{
		ft_interact_with_door(data);
		ft_print_image_bonus(data);
	}	
	return (0);
}

/*
 *	Function: ft_listen_motion_bonus
 *	-------------------------
 *	Listens for the key relatives for the motion of the user with door
 *	collision included
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_motion_bonus(int key, t_data *data)
{
	t_player	*player;
	double		view_angle;
	int			speed;

	speed = data->speed;
	view_angle = data->view_angle;
	player = data->player;
	if (key == 'w' || key == 'z')
		ft_move_forward_bonus(data, view_angle, speed);
	else if (key == 'a' || key == 'q')
		ft_strafe_left_bonus(data, view_angle, speed);
	else if (key == 's')
		ft_move_backward_bonus(data, view_angle, speed);
	else if (key == 'd')
		ft_strafe_right_bonus(data, view_angle, speed);
	return (0);
}

/*
 *	Function: ft_listen_key_just_pressed_bonus
 *	-------------------------
 *	Listens for the key just pressed event with door openning
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_key_just_pressed_bonus(int key, t_data *data)
{
	ft_log_data(key, data);
	if (key == 0xFF1B)
		ft_clean_exit_bonus(data);
	ft_listen_action(key, data);
	ft_print_image_bonus(data);
	return (0);
}

/*
 *	Function: ft_listen_key_pressed_bonus
 *	-------------------------
 *	Listens for the key pressed event with bonus
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_key_pressed_bonus(int key, t_data *data)
{
	ft_listen_viewing_bonus(key, data);
	ft_listen_motion_bonus(key, data);
	ft_print_image_bonus(data);
	return (0);
}
