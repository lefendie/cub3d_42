/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:03:05 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:47:51 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_initialize_data_bonus
 *	-------------------------
 *	Initialize the data structure for the game with bonus data
 *
 *	data: General data structure
 *	map_path: Path to the map file
 *
 *	Returns: Success state
 */

int	ft_initialize_data_bonus(t_data *data, char *map_path)
{
	void	*mlx_ptr;

	printf("Connection to mlx\n");
	ft_init_data_null(data);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (FAILURE);
	data->mlx_ptr = mlx_ptr;
	if (!ft_initialize_map_bonus(data, map_path))
		ft_exit_with_error("Issue at map initialization", 'r');
	if (!ft_initialize_window(data))
		ft_exit_with_error("Issue at bonus initialization", 'r');
	if (!ft_set_angle_const(data))
		ft_exit_with_error("Issue at angle initialization", 'r');
	if (!ft_initialize_misc(data))
		ft_exit_with_error("Issue at misc initialization", 'r');
	if (!ft_initialize_player(data, ft_free_player_incorrect_bonus))
		ft_exit_with_error("Issue at player initialization", 'r');
	if (!ft_initialize_asset(data))
		ft_exit_with_error("Issue at asset initialization", 'r');
	if (!ft_initialize_asset_bonus(data))
		ft_exit_with_error("Issue at bonus asset initialization", 'r');
	ft_check_size_asset(data, ft_free_uncomplete_data_bonus);
	ft_check_size_asset_bonus(data);
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_map_bonus
 *	-------------------------
 *	Initialize the bonus map data structure for the game
 *
 *	data: General data structure
 *	map_path: Path to the map file
 *
 *	Returns: Success state
 */

int	ft_initialize_map_bonus(t_data *data, char *map_path)
{
	char	*message;
	int		max_y;
	int		fd;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (FAILURE);
	fd = open(map_path, O_RDONLY, O_DIRECTORY);
	message = "";
	if (fd == -1)
		message = "Map conf file not found";
	else if (read(fd, 0, 0) == -1)
		message = "Path is a folder";
	else if (!ft_is_extension_valid(map_path, ".cub\0"))
		message = "Map file extension invalid";
	if (*message)
	{
		ft_free_no_map(data);
		ft_exit_with_error_var(message, map_path, 'r', 0);
	}
	max_y = ft_fill_data_conf_bonus(data, map_path, fd);
	close(fd);
	ft_check_map_bonus(data, max_y);
	ft_fill_door_list(data);
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_asset_bonus
 *	-------------------------
 *	Initialize the bonus assets with all the data in it
 *
 *	data: General data structure
 *
 */

int	ft_initialize_asset_bonus(t_data *data)
{
	data->i_ceiling = malloc(sizeof(t_img_data));
	if (!data->i_ceiling)
		return (FAILURE);
	data->i_ceiling->address = mlx_get_data_addr(data->ceiling,
			&(data->i_ceiling->bits_per_pixel), &(data->i_ceiling->size_line),
			&(data->i_ceiling->endian));
	data->i_floor = malloc(sizeof(t_img_data));
	if (!data->i_floor)
		return (FAILURE);
	data->i_floor->address = mlx_get_data_addr(data->floor,
			&(data->i_floor->bits_per_pixel), &(data->i_floor->size_line),
			&(data->i_floor->endian));
	data->i_door = malloc(sizeof(t_img_data));
	if (!data->i_door)
		return (FAILURE);
	data->i_door->address = mlx_get_data_addr(data->door,
			&(data->i_door->bits_per_pixel), &(data->i_door->size_line),
			&(data->i_door->endian));
	return (SUCCESS);
}
