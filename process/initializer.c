/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:04:03 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:36:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_initialize_data
 *	-------------------------
 *	Initialize the data structure for the game
 *
 *	data: General data structure
 *	map_path: Path to the map file
 *
 *	Returns: Success state
 */

int	ft_initialize_data(t_data *data, char *map_path)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	ft_init_data_null(data);
	printf("Connection to mlx\n");
	if (!mlx_ptr)
		return (FAILURE);
	data->mlx_ptr = mlx_ptr;
	if (!ft_initialize_map(data, map_path))
		ft_exit_with_error("Issue at map initialization", 'r');
	if (!ft_set_angle_const(data))
		ft_exit_with_error("Issue at angle initialization", 'r');
	if (!ft_initialize_window(data))
		ft_exit_with_error("Issue at bonus initialization", 'r');
	if (!ft_initialize_misc(data))
		ft_exit_with_error("Issue at misc initialization", 'r');
	if (!ft_initialize_player(data, ft_free_player_incorrect))
		ft_exit_with_error("Issue at player initialization", 'r');
	if (!ft_initialize_asset(data))
		ft_exit_with_error("Issue at asset initialization", 'r');
	ft_check_size_asset(data, ft_free_uncomplete_data);
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_player
 *	-------------------------
 *	Initialize the player data structure for the game
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initialize_player(t_data *data, void (*free_func)(void *data))
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (FAILURE);
	data->view_angle = -1;
	ft_initiate_player(data, 60 * (M_PI / 180), 10, free_func);
	data->angle_increment = (data->fov) / (float)data->win_width;
	printf("PLAYER INIT\n");
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_misc
 *	-------------------------
 *	Initialize the various data from the data structure for the game
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initialize_misc(t_data *data)
{
	data->img = malloc(sizeof(t_img_data));
	if (!data->img)
		return (FAILURE);
	data->dist_proj_plane = (data->win_width >> 1) / tan(30 * (M_PI / 180));
	if (!ft_initialize_c_data(data))
		return (FAILURE);
	ft_create_new_image(data);
	printf("MISC INIT\n");
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_map
 *	-------------------------
 *	Initialize the map data structure for the game
 *
 *	data: General data structure
 *	map_path: Path to the map file
 *
 *	Returns: Success state
 */

int	ft_initialize_map(t_data *data, char *map_path)
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
	max_y = ft_fill_data_conf(data, map_path, fd);
	ft_check_map(data, max_y);
	close(fd);
	printf("MAP INIT DONE\n");
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_window
 *	-------------------------
 *	Initialize the window values in the data structure for the game
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initialize_window(t_data *data)
{
	void	*mlx_win;

	printf("Window creation\n");
	mlx_win = mlx_new_window(data->mlx_ptr, SIZE_X, SIZE_Y, "Cub3d");
	if (!mlx_win)
		return (FAILURE);
	data->mlx_win = mlx_win;
	data->win_height = SIZE_Y;
	data->win_half_height = SIZE_Y >> 1;
	data->win_half_width = SIZE_X >> 1;
	data->win_width = SIZE_X;
	printf("WINDOW INIT DONE\n");
	return (SUCCESS);
}
