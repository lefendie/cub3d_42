/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:43:19 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 12:24:52 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

/*
 * BUILD_SLICE
 */

void	ft_get_sprite_address(t_data *data, t_img_data **sprite,
			t_slice_data *slice_data, double current_angle);
void	ft_build_floor_slice(t_data *data, t_img_data *img,
			t_slice_data *slice_data);
void	ft_build_wall_slice(t_data *data, t_img_data *img,
			t_slice_data *slice_data);
void	ft_build_ceiling_slice(t_data *data, t_img_data *img,
			t_slice_data *slice_data);
void	ft_build_world_slice(t_data *data, t_pos *wall_pos,
			float distance, int column);

/*
 * FILL_CELL
 */

void	ft_fill_cell_wall(t_img_data *img,
			t_slice_data *slice_data, char **img_line, t_img_data *sprite);

/*
 * PRINT_IMAGE
 */

int		ft_create_new_image(t_data *data);
void	ft_build_image(t_data *data);
int		ft_print_image(t_data *data);
int		ft_get_color_from_rgb(char *char_rgb);

/*
 * SLICE_DATA
 */

void	ft_set_data_ceiling(t_data *data, t_slice_data *slice_data, int img_y,
			int projected_height);
void	ft_set_data_wall(t_data *data, t_slice_data *slice_data, int img_y,
			int projected_height);
void	ft_set_data_floor(t_data *data, t_slice_data *slice_data, int img_y);
void	ft_set_data_collision(t_data *data, t_slice_data *slice_data,
			t_pos *wall_pos);

#endif
