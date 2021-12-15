/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:03:00 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/25 15:16:51 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_get_asset
 *	-------------------------
 *	Get an asset (texture) from the map configuration, we increase the pointer
 *	to i+2 to get only the path therefore skipping spaces and the conf
 *	name line "->       NO<- ./texture.xpm"
 *									i		+2
 *
 *	data: General data structure 
 *	data_ass: Asset from the data to fill
 *	line: Current line in map configuration
 *	path: Path to the asset
 *
 */

void	ft_get_asset(t_data *data, void **data_ass, char *line, char **path)
{
	char	*message;
	int		i;

	i = 0;
	ft_skip_str(line, " \t\0", &i);
	line += i + 2;
	message = "";
	if (!ft_get_path(line, path))
		message = "Wrong path";
	else if (!ft_is_extension_valid(*path, ".xpm\0"))
		message = "File extension invalid";
	*data_ass = mlx_xpm_file_to_image(data->mlx_ptr, *path,
			&data->wall_width, &data->wall_height);
	if (*data_ass == NULL && !*message)
		message = "File not found or incorrect";
	if (*message)
	{
		line -= i + 2;
		free(line);
		ft_free_uncomplete_data(data);
		ft_exit_with_error_var(message, *path, 'r', 1);
	}
	free(*path);
}

/*
 *	Function: ft_extract_wall
 *	-------------------------
 *	Fills the right data asset in data according to the wall in the map
 *	configuration
 *
 *	data: General data structure 
 *	line: Current line in map configuration
 *	path: Path to the asset
 *
 *	Returns: Boolean if the line contained a wall asset or not
 */

int	ft_extract_wall(t_data *data, char *line, char **path)
{
	int	line_is_wall;
	int	i;

	i = 0;
	ft_skip_str(line, " \t\0", &i);
	line_is_wall = 0;
	if (line[i] == 'E' && line[i + 1] == 'A')
		ft_get_asset(data, &(data->wall_ea), line, path);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		ft_get_asset(data, &(data->wall_no), line, path);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ft_get_asset(data, &(data->wall_we), line, path);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_get_asset(data, &(data->wall_so), line, path);
	if ((line[i] == 'E' && line[i + 1] == 'A')
		|| (line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'S' && line[i + 1] == 'O'))
		line_is_wall = 1;
	return (line_is_wall);
}

/*
 *	Function: ft_extract_line_data
 *	-------------------------
 *	Extract the data from a line in the map configuration
 *
 *	data: General data structure 
 *	line: Current line in map configuration
 *
 *	Returns: Boolean for if data configuration is complete or not
 */

int	ft_extract_line_data(t_data *data, char *line)
{
	char	*path;
	int		line_is_wall;
	int		i;

	i = 0;
	ft_is_data_duplicate(data, line);
	line_is_wall = ft_extract_wall(data, line, &path);
	if (line_is_wall)
		return (ft_is_data_uncomplete(data));
	ft_skip_str(line, " \t\0", &i);
	if (line[i] == 'C')
		ft_get_full_color(data, &(data->ceiling_color), line);
	else if (line[i] == 'F')
		ft_get_full_color(data, &(data->floor_color), line);
	else if (line[i] == '1' || line[i] != '\0')
	{
		ft_free_uncomplete_data(data);
		if (line[i] == '1' && ft_is_data_uncomplete(data))
			ft_exit_with_error_var("Map not at the end of the file",
				line, 'r', 1);
		else if (line[i] != '\0')
			ft_exit_with_error_var("Configuration value unknown", line, 'r', 1);
	}
	return (ft_is_data_uncomplete(data));
}

/*
 *	Function: ft_is_data_duplicate
 *	-------------------------
 *	Check if the data already has been filled
 *
 *	data: General data structure 
 *	line ""
 *
 *	Returns: Success state
 */

void	ft_is_data_duplicate(t_data *data, char *line)
{
	char	*message;
	int		i;

	i = 0;
	message = "";
	ft_skip_str(line, " \t\0", &i);
	if (line[i] == 'E' && line[i + 1] == 'A' && data->wall_ea != NULL)
		message = "Duplicate of EA";
	else if (line[i] == 'N' && line[i + 1] == 'O' && data->wall_no != NULL)
		message = "Duplicate of NO";
	else if (line[i] == 'W' && line[i + 1] == 'E' && data->wall_we != NULL)
		message = "Duplicate of WE";
	else if (line[i] == 'S' && line[i + 1] == 'O' && data->wall_so != NULL)
		message = "Duplicate of SO";
	else if (line[i] == 'C' && data->ceiling_color != -1)
		message = "Duplicate of C";
	else if (line[i] == 'F' && data->floor_color != -1)
		message = "Duplicate of F";
	if (*message)
	{
		ft_free_uncomplete_data(data);
		ft_exit_with_error_var(message, line, 'r', 1);
	}
}
