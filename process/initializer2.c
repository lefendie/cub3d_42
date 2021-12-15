/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:05:37 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/23 14:03:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_initialize_c_data
 *	-------------------------
 *	Initialize the collision data structure for the game
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initialize_c_data(t_data *data)
{
	data->c_data = malloc(sizeof(t_data_collision));
	if (!data->c_data)
		return (FAILURE);
	data->c_data->h_pos = malloc(sizeof(t_pos));
	if (!(data->c_data->h_pos))
		return (FAILURE);
	data->c_data->v_pos = malloc(sizeof(t_pos));
	if (!(data->c_data->v_pos))
		return (FAILURE);
	data->c_data->c_pos = malloc(sizeof(t_pos));
	if (!(data->c_data->c_pos))
		return (FAILURE);
	data->c_data->dir_vect = malloc(sizeof(t_vect));
	if (!(data->c_data->dir_vect))
		return (FAILURE);
	return (SUCCESS);
}

/*
 *	Function: ft_init_data_null
 *	-------------------------
 *	Initialize the data to NULL to avoid read on unnitialized value
 *
 *	data: General data structure
 *
 */

void	ft_init_data_null(t_data *data)
{
	data->c_data = NULL;
	data->img = NULL;
	data->a_const = NULL;
	data->player = NULL;
	data->view_angle = 0;
	data->fov = 0;
	data->angle_increment = 0;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->wall_no = NULL;
	data->wall_we = NULL;
	data->wall_ea = NULL;
	data->wall_so = NULL;
	data->floor = NULL;
	data->ceiling = NULL;
	data->door = NULL;
	data->mouse_control = 0;
	data->ceiling_color = -1;
	data->floor_color = -1;
	data->speed = 0;
}

/*
 *	Function: ft_initialize_asset
 *	-------------------------
 *	Initialize the assets with all the data in it
 *
 *	data: General data structure
 *
 */

int	ft_initialize_asset(t_data *data)
{
	data->i_wall_no = malloc(sizeof(t_img_data));
	if (!data->i_wall_no)
		return (FAILURE);
	data->i_wall_no->address = mlx_get_data_addr(data->wall_no,
			&(data->i_wall_no->bits_per_pixel), &(data->i_wall_no->size_line),
			&(data->i_wall_no->endian));
	data->i_wall_so = malloc(sizeof(t_img_data));
	if (!data->i_wall_so)
		return (FAILURE);
	data->i_wall_so->address = mlx_get_data_addr(data->wall_so,
			&(data->i_wall_so->bits_per_pixel), &(data->i_wall_so->size_line),
			&(data->i_wall_so->endian));
	data->i_wall_we = malloc(sizeof(t_img_data));
	if (!data->i_wall_we)
		return (FAILURE);
	data->i_wall_we->address = mlx_get_data_addr(data->wall_we,
			&(data->i_wall_we->bits_per_pixel), &(data->i_wall_we->size_line),
			&(data->i_wall_we->endian));
	data->i_wall_ea = malloc(sizeof(t_img_data));
	if (!data->i_wall_ea)
		return (FAILURE);
	data->i_wall_ea->address = mlx_get_data_addr(data->wall_ea,
			&(data->i_wall_ea->bits_per_pixel), &(data->i_wall_ea->size_line),
			&(data->i_wall_ea->endian));
	return (SUCCESS);
}
