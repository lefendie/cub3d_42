/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:49:56 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 14:53:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

/*
 * COLLISION_BONUS
 */

int		ft_collision_bonus(t_data *data,
			t_pos *ray_pos, char **map, t_vect *dir_vect);
int		ft_get_door_collision_vertical(t_data *data, t_data_collision *c_data);
int		ft_get_door_collision_horizontal(t_data *data,
			t_data_collision *c_data);

/*
 * EXTRACT_LINE
 */

void	ft_set_door_surface(char **map, t_door *door);
void	ft_reset_door_surface(t_door *door);
void	ft_shift_door_surface(t_door *door);

/*
 * EXTRACT_POS_BONUS
 */

void	ft_get_floor_pos(t_data *data, t_pos *floor_pos, int img_row);
void	ft_get_ceiling_pos(t_data *data, t_pos *ceiling_pos, int img_row);

/*
 * RAY_CAST_BONUS
 */

void	ft_continue_vertical_bonus(t_data *data, t_data_collision *c_data);
void	ft_continue_horizontal_bonus(t_data *data, t_data_collision *c_data);
void	ft_jump_dda_collision(t_data_collision *c_data);
int		ft_get_dda_collision_bonus(t_data *data, t_data_collision *c_data);
int		ft_continue_dda_collision_bonus(t_data *data,
			t_data_collision *c_data);

#endif
