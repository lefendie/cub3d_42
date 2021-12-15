/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:25:23 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:41:52 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_free_map
 *	-------------------------
 *	Free the map data
 *
 *	map: Data that contains the map data
 *
 */

void	ft_free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i <= map->alloc_size)
	{
		free(map->self[i]);
		i++;
	}
	free(map->self);
	free(map);
}

/*
 *	Function: ft_free_player
 *	-------------------------
 *	Free the player data
 *
 *	player: Data that contains the player data
 *
 */

void	ft_free_player(t_player *player)
{
	free(player->pixel_position);
	free(player->grid_position);
	free(player);
}

/*
 *	Function: ft_free_c_data
 *	-------------------------
 *	Free the collision data
 *
 *	c_data: Data that contains the player collision
 *
 */

void	ft_free_c_data(t_data_collision *c_data)
{
	free(c_data->h_pos);
	free(c_data->v_pos);
	free(c_data->c_pos);
	free(c_data->dir_vect);
	free(c_data);
}

/*
 *	Function: ft_free_misc
 *	-------------------------
 *	Free various data without any relation link
 *
 *	data: General data structure
 *
 */

void	ft_free_misc(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->self);
	mlx_destroy_image(data->mlx_ptr, data->wall_no);
	mlx_destroy_image(data->mlx_ptr, data->wall_ea);
	mlx_destroy_image(data->mlx_ptr, data->wall_we);
	mlx_destroy_image(data->mlx_ptr, data->wall_so);
	free(data->img);
	free(data->a_const);
}

/*
 *	Function: ft_clean_exit
 *	-------------------------
 *	Exit the program and removes and allocated data
 *
 *	data: General data structure
 *
 */

void	ft_clean_exit(t_data *data)
{
	printf("Closing program...\n");
	ft_free_map(data->map);
	ft_free_player(data->player);
	ft_free_c_data(data->c_data);
	ft_free_misc(data);
	free(data->mouse_pos);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_asset(data);
	free(data->mlx_ptr);
	free(data);
	exit(SUCCESS);
}
