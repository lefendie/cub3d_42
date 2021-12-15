/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:39:23 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:05:04 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_BONUS_H
# define OTHER_BONUS_H

/*
 * DOOR_CHECKER_BONUS
 */

int		ft_player_in_door_range(t_pos *player_pos, t_door *door);
int		ft_check_player_facing_door(t_map *map, t_door *door,
			t_pos *player_pos, t_vect *dir_vect);
int		ft_check_player_door_area(t_map *map, t_pos *player_pos);
int		ft_check_door_open(t_data *data, int x, int y);

/*
 * DOOR_HANDLER_BONUS
 */

void	ft_get_door(t_data *data, int x, int y);
void	ft_change_door_status(t_door *door);
void	ft_interact_with_door(t_data *data);

/*
 * FREE_MALLOC_BONUS
 */

void	ft_free_door(t_door **door_list);
void	ft_clean_exit_bonus(t_data *data);
void	ft_free_uncomplete_data_bonus(void *data);
void	ft_free_map_incorrect_bonus(void *data);
void	ft_free_player_incorrect_bonus(void *data);
void	ft_free_asset_bonus(t_data *data);

/*
 * TOOLS_BONUS
 */

int		ft_is_data_uncomplete_bonus(t_data *data);
void	ft_check_size_asset_bonus(t_data *data);

#endif
