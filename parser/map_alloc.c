/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:34:04 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:37:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_realloc_map
 *	-------------------------
 *	Reallocate the map so that every line has the same length, it's for bug
 *	preventing
 *
 *	data: General data structure 
 *	map_path: Path of the map
 *
 */

void	ft_realloc_map(t_data *data, int fd, char *line)
{
	unsigned int	i;
	char			*line_temp;
	int				line_size;
	int				prev_line_size;

	ft_get_map_line(data, fd, &line, ft_free_map_incorrect);
	line_size = ft_file_max_line(fd, &line);
	free(line);
	i = 0;
	while (i <= data->map->alloc_size)
	{
		prev_line_size = ft_strlen(data->map->self[i]);
		data->map->self[i] = ft_realloc_str(data->map->self[i],
				sizeof(char) * line_size + 1);
		line_temp = data->map->self[i] + prev_line_size;
		line_temp = ft_strset(line_temp, SPACE, line_size - prev_line_size + 1);
		i++;
	}
}

/*
 *	Function: ft_alloc_map_row
 *	-------------------------
 *	Get and allocate the number of lines for the map and allocate the number
 *	of object found in the map
 *
 *	fd: File descriptor of the map.cub
 *	data: General data structure where the map variable is located
 *
 *	Returns: SUCCESS/FAILURE value
 */

int	ft_alloc_map_row(int fd, t_data *data)
{
	unsigned int	alloc_size;
	char			*line;

	line = "";
	alloc_size = ft_file_count_lines(fd, line);
	close(fd);
	data->map->self = malloc(sizeof(char *) * (alloc_size + 1));
	if (!(data->map->self))
		return (FAILURE);
	data->map->self[alloc_size] = "\0";
	data->map->alloc_size = alloc_size;
	return (SUCCESS);
}

/*
 *	Function: ft_allocate_map
 *	-------------------------
 *	Allocate the right amount of memory for every line from the map.cub
 *
 *	map_path: Path of the map
 *	data: General data structure where the map variable is located
 *
 *	Returns: SUCCESS/FAILURE value
 */

int	ft_allocate_map(char *map_path, t_data *data)
{
	char			*line;
	int				fd;

	fd = open(map_path, O_RDONLY, O_DIRECTORY);
	ft_get_map_line(data, fd, &line, ft_free_uncomplete_data);
	free(line);
	ft_alloc_map_row(fd, data);
	close(fd);
	return (SUCCESS);
}
