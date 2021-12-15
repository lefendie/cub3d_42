/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:09:54 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 14:57:10 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

/*
 * ANGLE_ANALYZER
 */

double	ft_increment_angle(double radian_angle, double increment,
			double right_angle);
void	ft_set_angle_values(t_data_collision *c_data, t_data *data,
			double current_angle);
int		ft_set_angle_const(t_data *data);
void	ft_set_dir_vector(t_data_collision *c_data, t_angle_const *a_const);

/*
 * COLLISION
 */

void	ft_collision_pos(t_data_collision *c_data);
int		ft_check_collision(t_pos *ray_pos, char **map, t_vect *dir_vect);
char	ft_collision_side(t_data_collision *c_data);

/*
 * EXTRACT_POS
 */

void	ft_adjust_pos_to_wall(t_pos *pos, t_vect *dir_vect);
void	ft_copy_pos(t_pos *pos_copy, t_pos *pos_copied);

/*
 * INIT_POS
 */

void	ft_first_horizontal_pos(t_pos *grid_pos, t_data_collision *c_data);
void	ft_first_vertical_pos(t_pos *grid_pos, t_data_collision *c_data);

/*
 * POS_ANALYZER
 */
int		ft_same_grid_pos(t_grid_pos *first_pos, t_grid_pos *second_pos);
float	ft_get_distance_from_player(t_data *data,
			t_pos *evaluated_position, t_data_collision *c_data);

/*
 * RAY_CAST
 */
void	ft_continue_vertical(t_data *data, t_data_collision *c_data);
void	ft_continue_horizontal(t_data *data, t_data_collision *c_data);
int		ft_get_dda_collision(t_data *data, t_data_collision *c_data);

#endif
