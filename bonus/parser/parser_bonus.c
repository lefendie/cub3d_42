/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:56:36 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/19 17:35:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_file_verify_void_until_end_bonus
 *	-------------------------
 *	Verify that there is only empty line until the end of the file
 *	This allows to check if there is no useless configuration that
 *	is not going to be extracted
 *
 *	fd: File descriptor
 *	line: Line from the fd
 *	error_message: Error message to display
 *
 */

void	ft_file_verify_void_until_end_bonus(t_data *data, int fd, char *line,
		char *error_message)
{
	while (ft_get_next_line(fd, &line))
	{
		if (*line && !ft_check_only_char_list(line, "\t \0"))
		{
			ft_free_map_incorrect_bonus(data);
			ft_exit_with_error_var(error_message, line, 'r', 1);
		}
		free(line);
	}
	free(line);
}
