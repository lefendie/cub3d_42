/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:37:41 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 22:36:18 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_file_verify_void_until_end
 *	-------------------------
 *	Verify that there is only empty line until the end of the file
 *	This allows to check if there is no useless configuration that
 *	is not going to be extracted
 *
 *	fd: File descriptor
 *	line: Line from the fd
 *	error_message: Error message to display
 *
 */

void	ft_file_verify_void_until_end(t_data *data, int fd, char *line,
		char *error_message)
{
	while (ft_get_next_line(fd, &line))
	{
		if (*line && !ft_check_only_char_list(line, "\t \0"))
		{
			ft_free_map_incorrect(data);
			ft_exit_with_error_var(error_message, line, 'r', 1);
		}
		free(line);
	}
	free(line);
}

/*
 *	Function: ft_file_fill_tab
 *	-------------------------
 *	Extract a list of string from a file and returns the number of lines
 *
 *	fd: File descriptor
 *	line: Line from the fd
 *	tab: List of string
 *
 *	Returns: Number of lines extracted
 */

int	ft_file_fill_tab(int fd, char *line, char **tab)
{
	int	max;
	int	i;

	max = 1;
	i = 1;
	tab[0] = line;
	while (ft_get_next_line(fd, &line))
	{
		tab[i++] = line;
		max++;
	}
	tab[i] = line;
	return (max);
}

/*
 *	Function: ft_file_count_lines
 *	-------------------------
 *	Count the number of lines from a file and returns the number
 *
 *	fd: File descriptor
 *	line: Line from the fd
 *
 *	Returns: Number of lines from the file
 */

int	ft_file_count_lines(int fd, char *line)
{
	int	nb_lines;

	nb_lines = 0;
	while (ft_get_next_line(fd, &line))
	{
		nb_lines++;
		free(line);
	}
	nb_lines++;
	free(line);
	return (nb_lines);
}

/*
 *	Function: ft_file_max_line
 *	-------------------------
 *	Get the line with the more characters and returns its size
 *
 *	fd: File descriptor
 *	line: Line from the fd
 *
 *	Returns: Size of the line
 */

int	ft_file_max_line(int fd, char **line)
{
	char	*max_line;
	int		max;
	int		size_line;

	max_line = *line;
	max = (int)ft_strlen(*line);
	size_line = (int)ft_strlen(*line);
	while (ft_get_next_line(fd, line))
	{
		size_line = ft_strlen(*line);
		if (size_line > max)
		{
			max = size_line;
			free(max_line);
			max_line = *line;
		}
		else
			free(*line);
	}
	free(*line);
	*line = max_line;
	return (max);
}
