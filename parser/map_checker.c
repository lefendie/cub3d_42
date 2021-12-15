/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:06:56 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:39:41 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_check_wall_hole
 *	-------------------------
 *	Checks if there is a hole in the outer walls of the map
 *
 *	data: General data structure
 *	x: x position of the checked value
 *	y: y position of the checked value
 *
 */

void	ft_check_wall_hole(t_data *data, int y, int x,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	char		**map;
	char		*message;

	message = "\0";
	map = data->map->self;
	if (x == 0)
		message = "Left wall open at";
	else if (map[y][x - 1] == SPACE || map[y][x - 1] == TAB)
		message = "Left wall open at";
	else if (map[y][x + 1] == SPACE || map[y][x + 1] == TAB
			|| map[y][x + 1] == '\0')
		message = "Right wall open at";
	else if (map[y - 1][x] == SPACE || map[y - 1][x] == TAB)
		message = "Up wall open at";
	else if (map[y + 1][x] == SPACE || map[y + 1][x] == TAB)
		message = "Down wall open at";
	if (*message)
	{
		ft_set_grid_pos(&error_pos, x, y);
		free_func(data);
		ft_exit_with_error_func(message, ft_debug_error_pos,
			(void *)&error_pos, 'r');
	}
}

/*
 *	Function: ft_check_only_wall
 *	-------------------------
 *	Checks if the line contains only walls,
 *	this is used for the first and last row
 *
 *	current_line: String to test
 *
 */

void	ft_check_only_wall(t_data *data, char *current_line,
		void (*free_func)(void *data))
{
	t_grid_pos	error_pos;
	int			x;

	x = 0;
	while (current_line[x])
	{
		if (current_line[x] != '1' && current_line[x] != SPACE
			&& current_line[x] != TAB)
		{
			error_pos.x = x + 1;
			error_pos.y = 0;
			free_func(data);
			ft_exit_with_error_func("There is a hole in your wall",
				ft_debug_error_pos, (void *)&error_pos, 'r');
		}
		x++;
	}	
}

/*
 *	Function: ft_check_map_line
 *	-------------------------
 *	Checks every row of the map for corner or wall holes
 *
 *	data: General data structure
 *	y: y position of the checked value
 *
 *	Returns: Boolean meaning if the map is ended or not
 */

int	ft_check_map_line(t_data *data, int y)
{
	char	**map;
	int		x;
	int		end_of_map;
	int		nb_spaces;

	end_of_map = 1;
	map = data->map->self;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'N'
				|| map[y][x] == 'W' || map[y][x] == 'E')
		{
			ft_check_wall_hole(data, y, x, ft_free_map_incorrect);
			ft_check_corner_hole(data, y, x, ft_free_map_incorrect);
		}
		x++;
	}
	nb_spaces = 1;
	while (map[y][nb_spaces] && map[y][nb_spaces] == SPACE
			&& map[y][nb_spaces] == TAB)
		nb_spaces++;
	if (x == nb_spaces || map[y][0] == '\0')
		end_of_map = 1;
	return (end_of_map);
}

/*
 *	Function: ft_check_map_char
 *	-------------------------
 *	Checks if the map contains only the following
 *	0, 1, W, E, S, N, SPACE, \0
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

void	ft_check_map_char(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	t_grid_pos		error_pos;
	char			**map;

	i = -1;
	map = data->map->self;
	while (++i < data->map->map_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S'
				&& map[i][j] != 'N' && map[i][j] != SPACE && map[i][j] != '\0'
				&& map[i][j] != TAB)
			{
				ft_set_grid_pos(&error_pos, j, i);
				ft_free_map_incorrect(data);
				ft_exit_with_error_func("Unknown character", ft_debug_error_pos,
					&error_pos, 'r');
			}
			j++;
		}
	}
}

/*
 *	Function: ft_check_map
 *	-------------------------
 *	Checks the hole map for eventual errors
 *
 *	map: Map of the game
 *	max_y: Number max of rows in the map
 *
 */

void	ft_check_map(t_data *data, int max_y)
{
	unsigned int	y;
	char			**map;

	map = data->map->self;
	ft_check_map_char(data);
	y = 1;
	ft_check_only_wall(data, map[0], ft_free_map_incorrect);
	while (y < data->map->map_size - 1)
	{
		ft_check_map_line(data, y);
		y++;
	}
	ft_check_only_wall(data, map[max_y - 1], ft_free_map_incorrect);
}
