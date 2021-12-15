/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:21:16 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 15:16:42 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_free_map_incorrect
 *	-------------------------
 *	Free the map data when an error related to the map occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_map_incorrect(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	free(data_temp->mouse_pos);
	ft_free_map(data_temp->map);
	if (data_temp->wall_ea != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_ea);
	if (data_temp->wall_no != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_no);
	if (data_temp->wall_so != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_so);
	if (data_temp->wall_we != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_we);
	ft_free_asset(data);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp);
}

/*
 *	Function: ft_free_player_incorrect
 *	-------------------------
 *	Free the player data when an error related to the player occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_player_incorrect(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	free(data_temp->mouse_pos);
	free(data_temp->player);
	ft_free_map(data_temp->map);
	if (data_temp->wall_ea != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_ea);
	if (data_temp->wall_no != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_no);
	if (data_temp->wall_so != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_so);
	if (data_temp->wall_we != NULL)
		mlx_destroy_image(data_temp->mlx_ptr, data_temp->wall_we);
	mlx_destroy_window(data_temp->mlx_ptr, data_temp->mlx_win);
	free(data_temp->a_const);
	ft_free_c_data(data_temp->c_data);
	mlx_destroy_image(data_temp->mlx_ptr, data_temp->img->self);
	free(data_temp->img);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp);
}

/*
 *	Function: ft_free_uncomplete_data
 *	-------------------------
 *	Free data if any error happens in the conf file, it frees only the
 *	allocated data before the whole map is allocated
 *
 *	data: General data structure
 *
 */

void	ft_free_uncomplete_data(void *data)
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
	free(data_temp->map);
	free(data_temp->img);
	free(data_temp->mouse_pos);
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mlx_ptr);
	free(data_temp);
}

/*
 *	Function: ft_free_no_map
 *	-------------------------
 *	Free data at the beginning state of the program
 *
 *	data: General data structure
 *
 */

void	ft_free_no_map(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	mlx_destroy_display(data_temp->mlx_ptr);
	free(data_temp->mouse_pos);
	free(data_temp->mlx_ptr);
	free(data_temp->map);
	free(data_temp);
}

/*
 *	Function: ft_free_asset
 *	-------------------------
 *	Free the assets data when an error related to the player occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_asset(t_data *data)
{
	free(data->i_wall_ea);
	free(data->i_wall_we);
	free(data->i_wall_so);
	free(data->i_wall_no);
}
