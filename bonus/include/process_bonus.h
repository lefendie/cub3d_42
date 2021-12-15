/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:15:44 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 13:52:13 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_BONUS_H
# define PROCESS_BONUS_H

/*
 * INITIALIZER_BONUs
 */

int	ft_initialize_data_bonus(t_data *data, char *map_path);
int	ft_initialize_map_bonus(t_data *data, char *map_path);
int	ft_initialize_asset_bonus(t_data *data);

/*
 * PROCESS_BONUS
 */

int	ft_process_main_with_bonus(char *map_path);

#endif
