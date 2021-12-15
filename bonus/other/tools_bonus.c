/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manjaro </var/spool/mail/manjaro>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:55:32 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:48:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_is_data_uncomplete_bonus
 *	-------------------------
 *	Return a success value if there is data missing from data including
 *	the door, the ceiling and floor sprites
 *
 *	data: General data structure 
 *
 *	Returns: Success state
 */

int	ft_is_data_uncomplete_bonus(t_data *data)
{
	if (data->wall_ea == NULL || data->wall_no == NULL
		|| data->wall_so == NULL || data->wall_we == NULL)
		return (SUCCESS);
	if (data->ceiling == NULL || data->floor == NULL)
		return (SUCCESS);
	if (data->door == NULL)
		return (SUCCESS);
	return (FAILURE);
}

/*
 *	Function: ft_check_size_asset_bonus
 *	-------------------------
 *	Checks if the assets are all of the same size
 *
 *	data: General data structure
 *	free_func: Function to free if error
 *
 *	Returns: Success state
 */

void	ft_check_size_asset_bonus(t_data *data)
{
	int	w_size_line;
	int	w_bits_per_pixel;

	w_size_line = data->i_wall_no->size_line;
	w_bits_per_pixel = data->i_wall_no->bits_per_pixel;
	if (!(data->i_door->size_line == data->i_ceiling->size_line
			&& data->i_door->size_line == data->i_floor->size_line
			&& data->i_floor->size_line == data->i_ceiling->size_line
			&& data->i_floor->size_line == w_size_line
			&& data->i_door->size_line == w_size_line
			&& data->i_ceiling->size_line == w_size_line))
	{
		ft_free_uncomplete_data_bonus(data);
		ft_exit_with_error("Textures are of different sizes", 'r');
	}
	if (!(data->i_door->bits_per_pixel == data->i_ceiling->bits_per_pixel
			&& data->i_door->bits_per_pixel == data->i_floor->bits_per_pixel
			&& data->i_floor->bits_per_pixel == data->i_ceiling->bits_per_pixel
			&& data->i_floor->bits_per_pixel == w_bits_per_pixel
			&& data->i_door->bits_per_pixel == w_bits_per_pixel
			&& data->i_ceiling->bits_per_pixel == w_bits_per_pixel))
	{
		ft_free_uncomplete_data_bonus(data);
		ft_exit_with_error("Textures are of different sizes", 'r');
	}
}
