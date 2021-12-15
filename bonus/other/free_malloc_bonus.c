/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:55:07 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 15:52:58 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_free_door
 *	-------------------------
 *	Free various data without any relation link
 *
 *	data: General data structure where the map variable is located
 *
 */

void	ft_free_door(t_door **door_list)
{
	int	i;

	i = 0;
	while (door_list[i])
	{
		free(door_list[i]->surface->start);
		free(door_list[i]->surface->end);
		free(door_list[i]->surface);
		free(door_list[i]->pos);
		free(door_list[i]);
		i++;
	}
	free(door_list);
}

/*
 *	Function: ft_clean_exit
 *	-------------------------
 *	Exit the program and removes and allocated data
 *
 *	data: General data structure where the map variable is located
 *
 */

void	ft_clean_exit_bonus(t_data *data)
{
	printf("Closing program...\n");
	ft_free_door(data->map->door_list);
	ft_free_map(data->map);
	ft_free_player(data->player);
	ft_free_c_data(data->c_data);
	ft_free_misc(data);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->ceiling);
	mlx_destroy_image(data->mlx_ptr, data->door);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_asset_bonus(data);
	free(data->mouse_pos);
	free(data->mlx_ptr);
	free(data);
	exit(SUCCESS);
}

/*
 *	Function: ft_free_uncomplete_data_bonus
 *	-------------------------
 *	Free data if any error happens in the conf file, it frees only the
 *	allocated data
 *
 *	data: General data structure
 *
 */

void	ft_free_uncomplete_data_bonus(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	if (data_temp->wall_ea != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_ea);
	if (data_temp->wall_no != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_no);
	if (data_temp->wall_so != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_so);
	if (data_temp->wall_we != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_we);
	if (data_temp->ceiling != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->ceiling);
	if (data_temp->floor != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->floor);
	if (data_temp->door != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->door);
	free(data_temp->mouse_pos);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp->map);
	free(data_temp);
}

/*
 *	Function: ft_free_map_incorrect_bonus
 *	-------------------------
 *	Free the map data when an error related to the map occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_map_incorrect_bonus(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	free(data_temp->mouse_pos);
	if (data_temp->map->door_list)
		ft_free_door(data_temp->map->door_list);
	ft_free_map(data_temp->map);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->door);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_ea);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_no);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_so);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_we);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->ceiling);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->floor);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp);
}

/*
 *	Function: ft_free_player_incorrect_bonus
 *	-------------------------
 *	Free the player data when an error related to the player occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_player_incorrect_bonus(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	free(data_temp->mouse_pos);
	free(data_temp->player);
	ft_free_door(data_temp->map->door_list);
	ft_free_map(data_temp->map);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->door);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_ea);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_no);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_so);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_we);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->ceiling);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->floor);
	mlx_destroy_window(data_temp->mlx_ptr, data_temp->mlx_win);
	free(data_temp->a_const);
	ft_free_c_data(data_temp->c_data);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->img->self);
	free(data_temp->img);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp);
}
