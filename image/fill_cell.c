/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:56:58 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/18 16:48:39 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_fill_cell_wall
 *	-------------------------
 *	Get the right color for the current pixel cell in the current slice
 *	from the wall texture
 *
 *	img: Image data that will be printed
 *	slice_data: Data relative to the slice to be built in the image
 *	img_line: Raw image where to modify the color for the image
 *	sprite: Texture from where the color comes from
 *
 */

void	ft_fill_cell_wall(t_img_data *img,
		t_slice_data *slice_data, char **img_line, t_img_data *sprite)
{
	slice_data->sprite_line = (int)slice_data->offset_y
		* sprite->size_line;
	slice_data->offset_y += slice_data->increment;
	*(unsigned int *)*img_line = ft_get_color_from_rgb(sprite->address
			+ (slice_data->offset_x * 4) + slice_data->sprite_line);
	*img_line += img->size_line;
}
