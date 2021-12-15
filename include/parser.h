/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:49:38 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:42:55 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
 * COLOR
 */

void	ft_check_color_value(t_data *data, char *line, int i);
void	ft_check_color_count(t_data *data, int color_count, char *line);
char	*ft_color(t_data *data, char *line, int *i);
void	ft_get_full_color(t_data *data, int *data_color, char *line);
void	ft_set_color(t_data *data, int *color, char *value, int color_pos);

/*
 * EXTRACT_DATA
 */

void	ft_get_asset(t_data *data, void **data_ass, char *line, char **path);
int		ft_extract_wall(t_data *data, char *line, char **path);
int		ft_extract_line_data(t_data *data, char *line);
void	ft_is_data_duplicate(t_data *data, char *line);

/*
 * MAP_ALLOC
 */

void	ft_realloc_map(t_data *data, int fd, char *line);
int		ft_alloc_map_row(int fd, t_data *data);
int		ft_allocate_map(char *map_path, t_data *data);

/*
 * MAP_ANALYZER
 */

int		ft_fill_map(char *map_path, t_data *data);
void	ft_check_before_map(t_data *data, int fd, char *line);
int		ft_fill_data_conf(t_data *data, char *map_path, int fd);
void	ft_check_after_map(t_data *data, int fd, char *line);

/*
 * MAP_CHECK_CORNER
 */

void	ft_check_up_left_corner(t_data *data, int x, int y,
			void (*free_func)(void *data));
void	ft_check_down_left_corner(t_data *data, int x, int y,
			void (*free_func)(void *data));
void	ft_check_up_right_corner(t_data *data, int x, int y,
			void (*free_func)(void *data));
void	ft_check_down_right_corner(t_data *data, int x, int y,
			void (*free_func)(void *data));
void	ft_check_corner_hole(t_data *data, int y, int x,
			void (*free_func)(void *data));

/*
 * MAP_CHECKER
 */

void	ft_check_wall_hole(t_data *data, int y, int x,
			void (*free_func)(void *data));
void	ft_check_only_wall(t_data *data, char *current_line,
			void (*free_func)(void *data));
int		ft_check_map_line(t_data *data, int y);
void	ft_check_map_char(t_data *data);
void	ft_check_map(t_data *data, int max_y);

/*
 * PARSER
 */

void	ft_file_verify_void_until_end(t_data *data, int fd, char *line,
			char *error_message);
int		ft_file_fill_tab(int fd, char *line, char **tab);
int		ft_file_count_lines(int fd, char *line);
int		ft_file_max_line(int fd, char **line);

/*
 * PLAYER_SET
 */

int		ft_initiate_player(t_data *data, int fov, int speed,
			void (*free_func)(void *data));
void	ft_set_data_from_map(t_data *data, void (*free_func)(void *data));
int		ft_set_player_position(t_data *data, t_grid_pos *p_position,
			char position, void (*free_func)(void *data));
void	ft_set_viewing_angle(char orientation, t_data *data);
int		ft_set_pixel_position(t_player *player, int wall_height,
			int wall_width);

#endif
