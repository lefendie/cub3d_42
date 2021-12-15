/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:36:20 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 21:31:54 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BONUS_H
# define INPUT_BONUS_H

/*
 * INPUT_LISTENER_BONUS
 */

int		ft_listen_viewing_bonus(int key, t_data *data);
int		ft_listen_action(int key, t_data *data);
int		ft_listen_motion_bonus(int key, t_data *data);
int		ft_listen_key_just_pressed_bonus(int key, t_data *data);
int		ft_listen_key_pressed_bonus(int key, t_data *data);

/*
 * MOUSE_CONTROLLER_BONUS
 */

int		ft_listen_mouse_viewing(t_data *data);
void	ft_reset_mouse(t_data *data);
void	ft_release_mouse_control(t_data *data);
int		ft_listen_mouse_click_bonus(t_data *data);

/*
 * PLAYER_MOTION_BONUS
 */

void	ft_adjust_to_door(t_data *data, t_pos *player_pos, t_pos *next_pos);
void	ft_move_forward_bonus(t_data *data, double view_angle, int speed);
void	ft_strafe_left_bonus(t_data *data, double view_angle, int speed);
void	ft_move_backward_bonus(t_data *data, double view_angle, int speed);
void	ft_strafe_right_bonus(t_data *data, double view_angle, int speed);

#endif
