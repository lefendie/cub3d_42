/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:58:41 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:43:13 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

/*
 * EXTRACT_DATA_BONUS
 */

int		ft_extract_line_data_bonus(t_data *data, char *line);
void	ft_fill_door_list(t_data *data);
void	ft_get_asset_bonus(t_data *data, void **data_ass, char *line,
			char **path);
int		ft_extract_wall_bonus(t_data *data, char *line, char **path);

/*
 * MAP_ALLOC_BONUS
 */

void	ft_alloc_each_door(t_data *data, char **map);
int		ft_alloc_door(t_data *data, int x, int y, int i);
int		ft_alloc_door_list(t_data *data, char **map);

/*
 * MAP_ANALYZER_BONUS
 */

void	ft_check_before_map_bonus(t_data *data, int fd, char *line);
int		ft_fill_data_conf_bonus(t_data *data, char *map_path, int fd);
int		ft_fill_map_bonus(char *map_path, t_data *data);
void	ft_check_after_map_bonus(t_data *data, int fd, char *line);

/*
 * MAP_CHECKER_BONUS
 */

void	ft_check_map_bonus(t_data *data, int max_y);
void	ft_check_map_line_bonus(t_data *data, int y);
void	ft_check_map_char_bonus(t_data *data);
void	ft_check_valid_door(t_data *data, int x, int y);

/*
 * PARSER_BONUS
 */

void	ft_file_verify_void_until_end_bonus(t_data *data, int fd, char *line,
			char *error_message);

#endif
