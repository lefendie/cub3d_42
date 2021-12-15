/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_corner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:40:53 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/16 11:42:09 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_check_up_left_corner
 *	-------------------------
 *	Check if there is valid up left corner like
 *
 *			->111.
 *				100.
 *				....
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_up_left_corner(t_data *data, int x, int y,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	char		**map;

	map = data->map->self;
	if (map[y - 1][x] == '1' && map[y][x - 1] == '1'
		&& (map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != '0'
	&& map[y - 1][x - 1] != 'D'))
	{
		ft_set_grid_pos(&error_pos, x, y);
		free_func(data);
		ft_exit_with_error_func("Up Left corner not complete at",
			ft_debug_error_pos, (void *)&error_pos, 'r');
	}
}

/*
 *	Function: ft_check_down_left_corner
 *	-------------------------
 *	Check if there is valid down left corner like
 *
 *				....
 *				100.
 *			->111.
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_down_left_corner(t_data *data, int x, int y,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	char		**map;

	map = data->map->self;
	if (map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != '0'
			&& map[y + 1][x - 1] != 'D'))
	{
		ft_set_grid_pos(&error_pos, x, y);
		free_func(data);
		ft_exit_with_error_func("Down Left corner not complete at",
			ft_debug_error_pos, (void *)&error_pos, 'r');
	}
}

/*
 *	Function: ft_check_up_right_corner
 *	-------------------------
 *	Check if there is valid up right corner like
 *
 *				.111<-
 *				.001
 *				....
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_up_right_corner(t_data *data, int x, int y,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	char		**map;

	map = data->map->self;
	if (map[y - 1][x] == '1' && map[y][x + 1] == '1'
		&& (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != '0'
		&& map[y - 1][x + 1] != 'D'))
	{
		ft_set_grid_pos(&error_pos, x, y);
		free_func(data);
		ft_exit_with_error_func("Up Right corner not complete at",
			ft_debug_error_pos, (void *)&error_pos, 'r');
	}
}

/*
 *	Function: ft_check_down_right_corner
 *	-------------------------
 *	Check if there is valid down right corner like
 *
 *				....
 *				.001
 *				.111<-
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_down_right_corner(t_data *data, int x, int y,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	char		**map;

	map = data->map->self;
	if (map[y + 1][x] == '1' && map[y][x + 1] == '1'
		&& (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != '0'
		&& map[y + 1][x + 1] != 'D'))
	{
		free_func(data);
		ft_set_grid_pos(&error_pos, x, y);
		ft_exit_with_error_func("Down Right corner not complete at",
			ft_debug_error_pos, (void *)&error_pos, 'r');
	}
}

/*
 *	Function: ft_check_corner_hole
 *	-------------------------
 *	Check if there is an empty corner on the map
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_corner_hole(t_data *data, int y, int x,
		void (*free_func)(void *data))
{
	ft_check_up_left_corner(data, x, y, free_func);
	ft_check_down_left_corner(data, x, y, free_func);
	ft_check_up_right_corner(data, x, y, free_func);
	ft_check_down_right_corner(data, x, y, free_func);
}
