/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:05:56 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 22:40:38 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_check_only_char
 *	-------------------------
 *	Check if str is only composed with char c
 *
 *	str: String to test
 *	c: char that compose str
 *
 *	Returns: Success state
 */

int	ft_check_only_char(char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (FAILURE);
		str++;
	}
	return (SUCCESS);
}

/*
 *	Function: ft_check_only_char_list
 *	-------------------------
 *	Check if str is only composed with char from the list
 *
 *	str: String to test
 *	list: List with char that compose str
 *
 *	Returns: Success state
 */

int	ft_check_only_char_list(char *str, char *list)
{
	char	*list_sav;
	int		among_list;

	list_sav = list;
	while (*str)
	{
		among_list = 0;
		while (*list)
		{
			if (*str == *list)
				among_list = 1;
			list++;
		}
		if (!among_list)
			return (FAILURE);
		list = list_sav;
		str++;
	}
	return (SUCCESS);
}

/*
 *	Function: ft_get_file_extension
 *	-------------------------
 *	Get the extension of a file
 *
 *	str: File to get the extension of
 *
 *	Returns: Success state
 */

char	*ft_get_file_extension(char *str)
{
	char	*str_ext;

	while (*str)
	{
		if (*str == '.')
			str_ext = str;
		str++;
	}
	return (str_ext);
}

/*
 *	Function: ft_is_extension_valid
 *	-------------------------
 *	Check the file extension of a file path
 *
 *	data: General data structure
 *	list: List with char that compose str
 *
 *	Returns: Success state
 */

int	ft_is_extension_valid(char *str, char *ext)
{
	char	*str_ext;
	int		i;

	str_ext = ft_get_file_extension(str);
	if (!str_ext)
		return (FAILURE);
	i = -1;
	if (ft_strlen(str_ext) != ft_strlen((ext)) && ft_strlen(str_ext) > 0)
		return (FAILURE);
	while (str_ext[++i] && ext[i])
	{
		if (str_ext[i] != ext[i])
			return (FAILURE);
	}
	return (SUCCESS);
}

/*
 *	Function: ft_check_size_asset
 *	-------------------------
 *	Checks if the assets are all of the same size
 *
 *	data: General data structure
 *	free_func: Function to free if error
 *
 *	Returns: Success state
 */

void	ft_check_size_asset(t_data *data, void (*free_func)(void *data))
{
	if (!(data->i_wall_no->size_line == data->i_wall_so->size_line
			&& data->i_wall_no->size_line == data->i_wall_we->size_line
			&& data->i_wall_no->size_line == data->i_wall_ea->size_line
			&& data->i_wall_so->size_line == data->i_wall_we->size_line
			&& data->i_wall_so->size_line == data->i_wall_ea->size_line
			&& data->i_wall_we->size_line == data->i_wall_ea->size_line))
	{
		free_func(data);
		ft_exit_with_error("Walls are of different sizes", 'r');
	}
	if (!(data->i_wall_no->bits_per_pixel == data->i_wall_so->bits_per_pixel
			&& data->i_wall_no->bits_per_pixel
			== data->i_wall_we->bits_per_pixel
			&& data->i_wall_no->bits_per_pixel
			== data->i_wall_ea->bits_per_pixel
			&& data->i_wall_so->bits_per_pixel
			== data->i_wall_we->bits_per_pixel
			&& data->i_wall_so->bits_per_pixel
			== data->i_wall_ea->bits_per_pixel
			&& data->i_wall_we->bits_per_pixel
			== data->i_wall_ea->bits_per_pixel))
	{
		free_func(data);
		ft_exit_with_error("Walls are of different sizes", 'r');
	}
}
