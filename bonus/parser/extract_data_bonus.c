/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:41:30 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/25 15:50:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_extract_line_data_bonus
 *	-------------------------
 *	Extract the data from a line in the map configuration with bonus values
 *
 *	data: General data structure 
 *	line: Current line in map configuration
 *
 *	Returns: Boolean for if data configuration is complete or not
 */

int	ft_extract_line_data_bonus(t_data *data, char *line)
{
	char	*path;
	int		i;
	int		line_is_wall;

	i = 0;
	ft_is_data_duplicate(data, line);
	line_is_wall = ft_extract_wall_bonus(data, line, &path);
	if (line_is_wall)
		return (ft_is_data_uncomplete_bonus(data));
	ft_skip_str(line, " \t\0", &i);
	if (line[i] == 'C')
		ft_get_asset_bonus(data, &(data->ceiling), line, &path);
	else if (line[i] == 'F')
		ft_get_asset_bonus(data, &(data->floor), line, &path);
	else if (line[i] == 'D')
		ft_get_asset_bonus(data, &(data->door), line, &path);
	else if (line[i] == '1' || line[i] != '\0')
	{
		ft_free_uncomplete_data_bonus(data);
		if (line[i] == '1' && ft_is_data_uncomplete_bonus(data))
			ft_exit_with_error_var("Map not at the end", line, 'r', 1);
		else if (line[i] != '\0')
			ft_exit_with_error_var("Configuration value unknown", line, 'r', 1);
	}
	return (ft_is_data_uncomplete_bonus(data));
}

/*
 *	Function: ft_fill_door_list
 *	-------------------------
 *	Fill data for each door in the map
 *
 *	data: General data structure 
 *
 */

void	ft_fill_door_list(t_data *data)
{
	int	i;

	i = 0;
	ft_alloc_each_door(data, data->map->self);
	while (data->map->door_list[i])
	{
		ft_set_door_surface(data->map->self, data->map->door_list[i]);
		data->map->door_list[i]->status = 0;
		i++;
	}	
}

/*
 *	Function: ft_get_size_asset_name
 *	-------------------------
 *	Get the size of the name configuration
 *
 *	line: Current line in map configuration
 *	i: index where to test the char
 *
 */

int	ft_get_size_asset_name(char *line, int i)
{
	if (line[i] == 'F' || line[i] == 'D' || line[i] == 'C')
		return (1);
	return (2);
}

/*
 *	Function: ft_get_asset_bonus
 *	-------------------------
 *	Get an asset (texture) from the map configuration, we increase the pointer
 *	to i+2 to get only the path therefore skipping spaces and the conf
 *	name line "->       NO<- ./texture.xpm"
 *									i		+2
 *	Here is the difference is with the freeing function for bonus
 *
 *	data: General data structure 
 *	data_ass: Asset from the data to fill
 *	line: Current line in map configuration
 *	path: Path to the asset
 *
 */

void	ft_get_asset_bonus(t_data *data, void **data_ass, char *line,
		char **path)
{
	char	*message;
	int		i;
	int		asset_name_size;

	i = 0;
	ft_skip_str(line, " \t\0", &i);
	asset_name_size = ft_get_size_asset_name(line, i);
	line += i + asset_name_size;
	message = "";
	if (!ft_get_path(line, path))
		message = "Wrong path";
	else if (!ft_is_extension_valid(*path, ".xpm"))
		message = "File extension invalid";
	*data_ass = mlx_xpm_file_to_image(data->mlx_ptr, *path,
			&data->wall_width, &data->wall_height);
	if (*data_ass == NULL && !*message)
		message = "File not found or incorrect";
	if (*message)
	{
		line -= i + asset_name_size;
		free(line);
		ft_free_uncomplete_data_bonus(data);
		ft_exit_with_error_var(message, *path, 'r', 1);
	}
	free(*path);
}

/*
 *	Function: ft_extract_wall_bonus
 *	-------------------------
 *	Fills the right data asset in data according to the wall in the map
 *	configuration
 *	Here is the difference is with the freeing function for bonus
 *
 *	data: General data structure 
 *	line: Current line in map configuration
 *	path: Path to the asset
 *
 *	Returns: Boolean if the line contained a wall asset or not
 */

int	ft_extract_wall_bonus(t_data *data, char *line, char **path)
{
	int	line_is_wall;
	int	i;

	i = 0;
	ft_skip_str(line, " \t\0", &i);
	line_is_wall = 0;
	if (line[i] == 'E' && line[i + 1] == 'A')
		ft_get_asset_bonus(data, &(data->wall_ea), line, path);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		ft_get_asset_bonus(data, &(data->wall_no), line, path);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ft_get_asset_bonus(data, &(data->wall_we), line, path);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_get_asset_bonus(data, &(data->wall_so), line, path);
	if ((line[i] == 'E' && line[i + 1] == 'A')
		|| (line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'S' && line[i + 1] == 'O'))
		line_is_wall = 1;
	return (line_is_wall);
}
