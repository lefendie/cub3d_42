/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:02:15 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/18 16:49:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_fill_cell_door
 *	-------------------------
 *	Get the right color for the current pixel cell in the current slice
 *	from the door texture
 *
 *	img: Image data that will be printed
 *	slice_data: Data relative to the slice to be built in the image
 *	img_line: Raw image where to modify the color for the image
 *	sprite: Texture from where the color comes from
 *
 */

void	ft_fill_cell_door(t_img_data *img,
		t_slice_data *slice_data, char **img_line, t_img_data *sprite)
{
	slice_data->sprite_line = (int)slice_data->offset_y
		* sprite->size_line;
	slice_data->offset_y += slice_data->increment;
	*(unsigned int *)*img_line = ft_get_color_from_rgb(sprite->address
			+ (slice_data->offset_x * 4) + slice_data->sprite_line);
	*img_line += img->size_line;
}

/*
 *	Function: ft_fill_cell_floor
 *	-------------------------
 *	Get the right color for the current pixel cell in the current slice
 *	from the floor texture
 *
 *	img: Image data that will be printed
 *	slice_data: Data relative to the slice to be built in the image
 *	img_line: Raw image where to modify the color for the image
 *	sprite: Texture from where the color comes from
 *
 */

void	ft_fill_cell_floor(t_img_data *img,
		t_slice_data *slice_data, char **img_line, t_img_data *sprite)
{
	slice_data->sprite_line = (int)slice_data->offset_y * sprite->size_line;
	*(unsigned int *)*img_line = ft_get_color_from_rgb(sprite->address
			+ (slice_data->offset_x * 4) + slice_data->sprite_line);
	*img_line += img->size_line;
}

/*
 *	Function: ft_fill_cell_ceiling
 *	-------------------------
 *	Get the right color for the current pixel cell in the current slice
 *	from the ceiling texture
 *
 *	img: Image data that will be printed
 *	slice_data: Data relative to the slice to be built in the image
 *	img_line: Raw image where to modify the color for the image
 *	sprite: Texture from where the color comes from
 *
 */

void	ft_fill_cell_ceiling(t_img_data *img,
		t_slice_data *slice_data, char **img_line, t_img_data *sprite)
{
	slice_data->sprite_line = (int)slice_data->offset_y * sprite->size_line;
	*(unsigned int *)*img_line = ft_get_color_from_rgb(sprite->address
			+ (slice_data->offset_x * 4) + slice_data->sprite_line);
	*img_line += img->size_line;
}
