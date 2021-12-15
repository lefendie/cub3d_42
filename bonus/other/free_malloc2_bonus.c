/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:49:09 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:49:25 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_free_asset_bonus
 *	-------------------------
 *	Free the assets data when an error related to the player occurs
 *
 *	data: General data structure
 *
 */

void	ft_free_asset_bonus(t_data *data)
{
	ft_free_asset(data);
	free(data->i_ceiling);
	free(data->i_floor);
	free(data->i_door);
}
