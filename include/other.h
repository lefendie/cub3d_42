/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:55:38 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:21:15 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# define BUFFER_SIZE 32

/*
 * FREE_MALLOC
 */

void	ft_free_map(t_map *map);
void	ft_free_player(t_player *player);
void	ft_free_c_data(t_data_collision *c_data);
void	ft_free_misc(t_data *data);
void	ft_clean_exit(t_data *data);

/*
 * FREE_MALLOC2
 */

void	ft_free_map_incorrect(void *data);
void	ft_free_player_incorrect(void *data);
void	ft_free_uncomplete_data(void *data);
void	ft_free_no_map(void *data);
void	ft_free_asset(t_data *data);

/*
 * GET_NEXT_LINE
 */

char	*ft_strnjoin(char *s1, char const *s2, size_t n_s2);
char	**ft_halfsplit(char s[BUFFER_SIZE], char c);
int		ft_getlinefrom_temp(char *temp, char buffer[BUFFER_SIZE], char **line);
int		ft_get_next_line(int fd, char **line);

/*
 * LITTLE_CHECK
 */

int		ft_check_only_char(char *str, char c);
int		ft_check_only_char_list(char *str, char *list);
char	*ft_get_file_extension(char *str);
int		ft_is_extension_valid(char *str, char *ext);
void	ft_check_size_asset(t_data *data, void (*free_func)(void *data));

/*
 * SETTER
 */

void	ft_set_grid_pos(t_grid_pos *grid_pos, int x, int y);
void	ft_set_pos(t_pos *pos, double x, double y);

/*
 * TOOLS
 */

int		ft_strcontains_char(char *str, char c);
void	ft_get_map_line(t_data *data, int fd, char **line,
			void (*free_func)(void *data));
int		ft_is_data_uncomplete(t_data *data);
int		ft_get_path(char *line, char **path);
char	ft_get_next_data(int fd, char **line);

#endif
