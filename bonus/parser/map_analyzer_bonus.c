/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyzer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:45:19 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/25 15:00:10 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_check_before_map_bonus
 *	-------------------------
 *	Check if there is unknown data before the map
 *
 *	data: General data structure where the map variable is located
 *
 *	fd: File descriptor of the map.cub
 *	line: Starting line after the configuration
 *	Returns: Maximum row of the map
 */

void	ft_check_before_map_bonus(t_data *data, int fd, char *line)
{
	char	c;

	c = ft_get_next_data(fd, &line);
	if (c != '1' && c != '0')
	{
		ft_free_uncomplete_data_bonus(data);
		ft_exit_with_error_var("Configuration value unknown", line, 'r', 1);
	}
	free(line);
}

/*
 *	Function: ft_fill_data_conf_bonus
 *	-------------------------
 *	Allocate and fills the data from the map bonus configuration
 *
 *	data: General data structure where the map variable is located
 *	map_path: Path of the map
 *
 *	Returns: Maximum row of the map
 */

int	ft_fill_data_conf_bonus(t_data *data, char *map_path, int fd)
{
	char	*line;
	int		max_y;
	int		map_not_found;

	max_y = 0;
	map_not_found = 1;
	while (ft_get_next_line(fd, &line)
		&& ft_extract_line_data_bonus(data, line))
		free(line);
	free(line);
	if (ft_is_data_uncomplete_bonus(data))
	{
		ft_free_uncomplete_data_bonus(data);
		ft_exit_with_error_func(
			"Data incomplete", ft_debug_data, (void *)data, 'r');
	}
	ft_check_before_map_bonus(data, fd, line);
	max_y = ft_fill_map_bonus(map_path, data);
	return (max_y);
}

/*
 *	Function: ft_fill_map_bonus
 *	-------------------------
 *	Fills the map variable after being allocated from ft_allocate_map with
 *	a different process for checking errors
 *
 *	map_path: Path of the map
 *	data: General data structure where the map variable is located
 *
 *	Returns: Number of lines in the map
 */

int	ft_fill_map_bonus(char *map_path, t_data *data)
{
	char	*line;
	int		max_y;
	int		fd;

	fd = open(map_path, O_RDONLY, O_DIRECTORY);
	ft_get_map_line(data, fd, &line, ft_free_uncomplete_data_bonus);
	if (!(ft_allocate_map(map_path, data)))
		return (FAILURE);
	max_y = ft_file_fill_tab(fd, line, data->map->self);
	data->map->map_size = max_y;
	fd = open(map_path, O_RDONLY, O_DIRECTORY);
	ft_realloc_map(data, fd, line);
	fd = open(map_path, O_RDONLY, O_DIRECTORY);
	ft_check_after_map_bonus(data, fd, line);
	close(fd);
	return (max_y);
}

/*
 *	Function: ft_check_after_map_bonus
 *	-------------------------
 *	Check if there is unknown data after the map with free bonus function
 *
 *	data: General data structure where the map variable is located
 *	fd: File descriptor of the map.cub
 *	line: Starting line after the configuration
 *
 */

void	ft_check_after_map_bonus(t_data *data, int fd, char *line)
{
	int	eof;

	eof = 1;
	ft_get_map_line(data, fd, &line, ft_free_uncomplete_data_bonus);
	free(line);
	while (!ft_check_only_char_list(line, "\t \0") && eof)
	{
		eof = ft_get_next_line(fd, &line);
		free(line);
	}
	if (eof)
		ft_file_verify_void_until_end_bonus(data, fd, line,
			"Unknown element after the map");
}
