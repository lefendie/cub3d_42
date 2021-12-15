/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:53:25 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/20 12:31:09 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_listen_exit
 *	-------------------------
 *	Listens for the Esc key to cleanly close the program
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_exit(int key, t_data *data)
{
	if (key == 0xFF1B)
		ft_clean_exit(data);
	return (SUCCESS);
}

/*
 *	Function: ft_listen_motion
 *	-------------------------
 *	Listens for the key relatives for the motion of the user
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_motion(int key, t_data *data)
{
	t_player	*player;
	double		view_angle;
	int			speed;

	speed = data->speed;
	view_angle = data->view_angle;
	player = data->player;
	if (key == 'w' || key == 'z')
		ft_move_forward(data, view_angle, speed);
	else if (key == 'a' || key == 'q')
		ft_strafe_left(data, view_angle, speed);
	else if (key == 's')
		ft_move_backward(data, view_angle, speed);
	else if (key == 'd')
		ft_strafe_right(data, view_angle, speed);
	return (SUCCESS);
}

/*
 *	Function: ft_listen_viewing
 *	-------------------------
 *	Listens for the key relatives for the viewing of the user
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_viewing(int key, t_data *data)
{
	int	speed;

	speed = data->speed;
	if (key == 65363)
		ft_look_right(data, speed);
	if (key == 65361)
		ft_look_left(data, speed);
	return (SUCCESS);
}

/*
 *	Function: ft_listen_key_just_pressed
 *	-------------------------
 *	Listens for the key just pressed event
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_key_just_pressed(int key, t_data *data)
{
	ft_log_data(key, data);
	ft_listen_exit(key, data);
	return (SUCCESS);
}

/*
 *	Function: ft_listen_key_pressed
 *	-------------------------
 *	Listens for the key pressed event
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_listen_key_pressed(int key, t_data *data)
{
	ft_listen_viewing(key, data);
	ft_listen_motion(key, data);
	ft_print_image(data);
	return (SUCCESS);
}
