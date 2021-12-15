/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:50:44 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 14:55:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*
 * INPUT_LISTENER
 */

int		ft_listen_exit(int key, t_data *data);
int		ft_listen_motion(int key, t_data *data);
int		ft_listen_viewing(int key, t_data *data);
int		ft_listen_key_just_pressed(int key, t_data *data);
int		ft_listen_key_pressed(int key, t_data *data);

/*
 * MOUSE_LISTENER
 */

int		ft_listen_mouse_click(t_data *data);

/*
 * PLAYER_MOTION
 */

int		ft_adjust_to_wall(t_pos *player_pos, t_pos *next_pos, char **map);
void	ft_move_forward(t_data *data, double view_angle, int speed);
void	ft_strafe_left(t_data *data, double view_angle, int speed);
void	ft_move_backward(t_data *data, double view_angle, int speed);
void	ft_strafe_right(t_data *data, double view_angle, int speed);

/*
 * PLAYER_VIEWING
 */

void	ft_look_right(t_data *data, int speed);
void	ft_look_left(t_data *data, int speed);

#endif
