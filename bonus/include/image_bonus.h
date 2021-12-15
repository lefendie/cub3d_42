/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:31:43 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 14:53:20 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BONUS_H
# define IMAGE_BONUS_H

/*
 * BUILD_SLICE_BONUS
 */

void	ft_build_world_slice_bonus(t_data *data, t_pos *wall_pos,
			float distance, int column);
void	ft_build_world_wall_slice(t_data *data, t_pos *wall_pos,
			float distance, int column);
void	ft_build_ceiling_slice_sprite(t_data *data, t_img_data *img,
			t_slice_data *slice_data);
void	ft_build_floor_slice_sprite(t_data *data, t_img_data *img,
			t_slice_data *slice_data);

/*
 * BUILD_SLICE_DOOR_BONUS 
 */

void	ft_build_door_h_slice(t_data *data, t_door *door,
			float distance, int column);
void	ft_build_door_v_slice(t_data *data, t_door *door,
			float distance, int column);
void	ft_build_world_door_slice(t_data *data, float distance, int column);
void	ft_set_data_door(t_data *data,
			t_slice_data *slice_data, int img_y, int projected_height);
void	ft_build_door_slice(t_data *data, t_img_data *img,
			t_slice_data *slice_data);

/*
 * FILL_CELL_BONUS
 */

void	ft_fill_cell_door(t_img_data *img,
			t_slice_data *slice_data, char **img_line, t_img_data *sprite);
void	ft_fill_cell_floor(t_img_data *img,
			t_slice_data *slice_data, char **img_line, t_img_data *sprite);
void	ft_fill_cell_ceiling(t_img_data *img,
			t_slice_data *slice_data, char **img_line, t_img_data *sprite);

/*
 * PRINT_IMAGE_BONUS
 */

int		ft_print_image_bonus(t_data *data);
void	ft_build_image_bonus(t_data *data);

#endif
