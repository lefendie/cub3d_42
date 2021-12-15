/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:18:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/23 21:52:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_strcontains_char
 *	-------------------------
 *	Check if c is present in str
 *
 *	str: String where to look
 *	c: Char to find
 *
 *	Returns: Success state
 */

int	ft_strcontains_char(char *str, char c)
{
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (1);
	return (0);
}

/*
 *	Function: ft_get_map_line
 *	-------------------------
 *	Get to the line where the map is from a file descriptor
 *
 *	fd: file descriptor
 *	line: String where the beginning of the map will be
 *
 */

void	ft_get_map_line(t_data *data, int fd, char **line,
		void (*free_func)(void *data))
{
	char	*line_temp;
	int		map_not_found;

	map_not_found = 1;
	while (map_not_found && ft_get_next_line(fd, line))
	{
		line_temp = *line;
		while ((*line_temp == ' ' || *line_temp == '	') && *line_temp)
			line_temp++;
		if (*line_temp == '1' || *line_temp == '0')
			map_not_found = 0;
		if (map_not_found)
			free(*line);
	}
	if (map_not_found)
	{
		free(*line);
		free_func(data);
		ft_exit_with_error("Map missing", 'r');
	}
}

/*
 *	Function: ft_is_data_uncomplete
 *	-------------------------
 *	Return a success value if there is data missing from data 
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_is_data_uncomplete(t_data *data)
{
	if (data->wall_ea == NULL || data->wall_no == NULL
		|| data->wall_so == NULL || data->wall_we == NULL)
		return (SUCCESS);
	if (data->ceiling_color == -1 || data->floor_color == -1 )
		return (SUCCESS);
	return (FAILURE);
}

/*
 *	Function: ft_get_path
 *	-------------------------
 *	Get the path from line and gives it to path
 *
 *	line: String where to extract the path
 *	path: String where will be the extracted path
 *
 *	Returns: Success state
 */

int	ft_get_path(char *line, char **path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*line == SPACE || *line == TAB) && *line)
		line++;
	while (line[i] == '/' || line[i] == '.' || (line[i] <= 'z'
			&& line[i] >= 'a') || (line[i] <= 'Z' && line[i] >= 'A')
		|| (line[i] <= '9' && line[i] >= '0') || line[i] == '-'
		|| line[i] == '_')
		i++;
	*path = ft_strdup(line);
	(*path)[i] = '\0';
	while ((line[i] == SPACE || line[i] == TAB) && line[i])
		i++;
	if (line[i] != '\0')
		return (FAILURE);
	return (SUCCESS);
}

/*
 *	Function: ft_get_next_data
 *	-------------------------
 *	Get the path from line and gives it to path
 *
 *	line: String that will contain the data conf
 *	fd: file descriptor
 *
 *	Returns: Success state
 */

char	ft_get_next_data(int fd, char **line)
{
	int	i;

	while (ft_get_next_line(fd, line))
	{
		i = 0;
		ft_skip_str(*line, " \t", &i);
		if ((*line)[0])
			return ((*line)[i]);
		free(*line);
	}
	return ('\0');
}
