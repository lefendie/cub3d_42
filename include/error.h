/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:20:38 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/21 14:55:26 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
 * ERROR_HANDLER
 */

void	ft_exit_with_error_var(char *error_message, char *additional_info,
			char color, unsigned int allocated);
void	ft_exit_with_error(char *error_message, char color);
void	ft_exit_with_error_func(char *error_message, void (*func)(void *data),
			void *data, char color);

/*
 * DEBUG_FUNC
 */

void	ft_debug_error_pos(void *pos);
void	ft_debug_data(void *data);
void	ft_printmap(t_map *map);
int		ft_log_data(int key, t_data *data);

#endif
