/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:16:17 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/24 22:42:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

/*
 * INITIALIZER
 */
int		ft_initialize_data(t_data *data, char *map_path);
int		ft_initialize_player(t_data *data, void (*free_func)(void *data));
int		ft_initialize_misc(t_data *data);
int		ft_initialize_map(t_data *data, char *map_path);
int		ft_initialize_window(t_data *data);

/*
 * INITIALIZER2 
 */

int		ft_initialize_asset(t_data *data);
int		ft_initialize_c_data(t_data *data);
void	ft_init_data_null(t_data *data);

/*
 * PROCESS
 */

int		ft_process_main(char *map_path);

#endif
