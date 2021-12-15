/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:23:38 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 21:32:18 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_listen_mouse_viewing
 *	-------------------------
 *	Allow to look with the mouse
 *
 *	data: General data structure 
 *
 *	Returns: Success state
 */

/*int	ft_listen_mouse_viewing(t_data *data)
 *{
 *	t_grid_pos	new_pos;
 *	int			speed;
 *
 *	if (data->mouse_control == 1)
 *	{
 *		mlx_mouse_get_pos(data->mlx_ptr,
 *			data->mlx_win, &new_pos.x, &new_pos.y);
 *		ft_reset_mouse(data);
 *		if (new_pos.x != data->win_half_width)
 *		{
 *			speed = abs(new_pos.x - data->win_half_width) / data->speed;
 *			if (speed > 3)
 *				speed = 3;
 *			if (new_pos.x > data->mouse_pos->x)
 *				ft_look_right(data, speed);
 *			else
 *				ft_look_left(data, speed);
 *			ft_print_image_bonus(data);
 *		}
 *	}
 *	return (SUCCESS);
 *}
 */

int	ft_listen_mouse_viewing(t_data *data)
{
	t_grid_pos	new_pos;
	int			speed;

	if (data->mouse_control == 1)
	{
		mlx_mouse_get_pos(data->mlx_ptr,
			data->mlx_win, &new_pos.x, &new_pos.y);
		if (new_pos.x != data->mouse_pos->x)
		{
			speed = abs(new_pos.x - data->mouse_pos->x);
			if (speed > 10)
				speed = 10;
			if (new_pos.x > data->mouse_pos->x)
				ft_look_right(data, speed);
			else
				ft_look_left(data, speed);
			ft_print_image_bonus(data);
		}
		mlx_mouse_get_pos(data->mlx_ptr, data->mlx_win,
			&data->mouse_pos->x, &data->mouse_pos->y);
	}
	return (SUCCESS);
}

/*
 *	Function: ft_reset_mouse
 *	-------------------------
 *	Reset the mouse position to the center of the screen
 *
 *	key: Key hit by the user
 *	data: General data structure 
 *
 */

void	ft_reset_mouse(t_data *data)
{
	mlx_mouse_move(data->mlx_ptr, data->mlx_win,
		data->win_half_width, data->win_half_height);
}

/*
 *	Function: ft_release_mouse_control
 *	-------------------------
 *	Allow the use of the mouse for mouse viewing or not
 *	
 *	data: General data structure 
 *
 */

void	ft_release_mouse_control(t_data *data)
{
	if (data->mouse_control == 1)
	{
		mlx_mouse_show(data->mlx_ptr, data->mlx_win);
		data->mouse_control = 0;
	}
	else
	{
		mlx_mouse_hide(data->mlx_ptr, data->mlx_win);
		data->mouse_control = 1;
	}
}

/*
 *	Function: ft_listen_mouse_click_bonus
 *	-------------------------
 *	Listens for the mouse click event with free bonus function
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_listen_mouse_click_bonus(t_data *data)
{
	ft_clean_exit_bonus(data);
	return (SUCCESS);
}
