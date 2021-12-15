/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:48:31 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:50:57 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_check_map_bonus
 *	-------------------------
 *	Checks the hole map for eventual errors in a bonus map
 *
 *	map: Map of the game
 *	max_y: Number max of rows in the map
 *
 */

void	ft_check_map_bonus(t_data *data, int max_y)
{
	char	**map;
	int		y;

	map = data->map->self;
	ft_check_map_char_bonus(data);
	y = 1;
	ft_check_only_wall(data, map[0], ft_free_map_incorrect_bonus);
	while (y < max_y - 1)
	{
		ft_check_map_line_bonus(data, y);
		y++;
	}
	ft_check_only_wall(data, map[max_y - 1], ft_free_map_incorrect_bonus);
}

/*
 *	Function: ft_check_map_line_bonus
 *	-------------------------
 *	Checks every row of the map for corner or wall holes in a bonus map
 *
 *	map: Map of the game
 *	y: y position of the checked value
 *
 */

void	ft_check_map_line_bonus(t_data *data, int y)
{
	char	**map;
	int		x;

	map = data->map->self;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'N'
				|| map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'D')
		{
			ft_check_wall_hole(data, y, x, ft_free_map_incorrect_bonus);
			ft_check_corner_hole(data, y, x, ft_free_map_incorrect_bonus);
		}
		if (map[y][x] == 'D')
			ft_check_valid_door(data, x, y);
		x++;
	}
}

/*
 *	Function: ft_check_map_char_bonus
 *	-------------------------
 *	Checks if the bonus map contains only the following
 *	0, 1, W, E, S, N, SPACE, \0, D
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

void	ft_check_map_char_bonus(t_data *data)
{
	unsigned int	i;
	t_grid_pos		error_pos;
	char			**map;
	int				j;

	map = data->map->self;
	i = 0;
	while (i < data->map->map_size)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'W'
					&& map[i][j] != 'E' && map[i][j] != 'S' && map[i][j] != 'N'
					&& map[i][j] != SPACE && map[i][j] != '\0'
					&& map[i][j] != 'D' && map[i][j] != TAB)
			{
				ft_set_grid_pos(&error_pos, j, i);
				ft_free_map_incorrect_bonus(data);
				ft_exit_with_error_func("Unknown character", ft_debug_error_pos,
					&error_pos, 'r');
			}
		}
		i++;
	}
}

/*
 *	Function: ft_check_valid_door
 *	-------------------------
 *	Check if a door is valid like 
 *
 *		1
 *	1D1  or D
 *		1
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

void	ft_check_valid_door(t_data *data, int x, int y)
{
	t_grid_pos	error_pos;
	char		**map;
	char		*message;

	message = "\0";
	map = data->map->self;
	ft_set_grid_pos(&error_pos, x, y);
	if ((map[y][x - 1] == '1' && map[y][x + 1] != '1')
						|| (map[y - 1][x] == '1' && map[y + 1][x] != '1')
						|| (map[y][x - 1] != '1' && map[y][x + 1] == '1')
						|| (map[y - 1][x] != '1' && map[y + 1][x] == '1'))
		message = "Walls misplaced with door\0";
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1'
			&& map[y][x - 1] == '1' && map[y][x + 1] == '1')
		message = "Door surrounded by walls\0";
	else if (map[y - 1][x] == '0' && map[y + 1][x] == '0'
			&& map[y][x - 1] == '0' && map[y][x + 1] == '0')
		message = "Door not surrounded by walls\0";
	if (*message)
	{
		ft_free_map_incorrect_bonus(data);
		ft_exit_with_error_func(message, ft_debug_error_pos,
			(void *)&error_pos, 'r');
	}
}
