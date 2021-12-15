/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:56:25 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/23 22:05:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_check_color_value
 *	-------------------------
 *	Checks if the color value is in the range [0,255]
 *
 *	data: General data structure
 *	line: Current line
 *	i: Current index
 *
 */

void	ft_check_color_value(t_data *data, char *line, int i)
{
	char	*color_value;

	color_value = ft_color(data, line, &i);
	if (ft_atoi(color_value) < 0 || ft_atoi(color_value) > 255)
	{
		ft_free_uncomplete_data(data);
		free(line);
		ft_exit_with_error_var("Color not in the range [0,255]",
			color_value, 'r', 1);
	}
	free(color_value);
}

/*
 *	Function: ft_check_color_count
 *	-------------------------
 *	Checks if there r, g and b colors
 *
 *	color_count: Number of colors
 *	line: Current line
 *	data: General data structure
 *
 */

void	ft_check_color_count(t_data *data, int color_count, char *line)
{
	if (color_count < 3)
	{
		free(line);
		ft_exit_with_error_func("Color missing",
			ft_free_uncomplete_data, data, 'r');
	}
	if (color_count > 3)
	{
		free(line);
		ft_exit_with_error_func("Too many colors",
			ft_free_uncomplete_data, data, 'r');
	}
}

/*
 *	Function: ft_color
 *	-------------------------
 *	Get a color (texture) from the map configuration
 *
 *	data:	General data structure
 *	data_color: Color that will be extracted from the map configuration
 *	line: Current line in map configuration
 *
 */

char	*ft_color(t_data *data, char *line, int *i)
{
	char	*str_color;
	int		j;

	str_color = malloc(sizeof(char *) * 4);
	if (!str_color)
		return (FAILURE);
	ft_bzero(str_color, 4);
	j = 0;
	ft_skip_str(line, " \t", i);
	if (line[*i] == '+' || line[*i] == '-')
		str_color[j++] = line[(*i)++];
	if (line[*i] >= '0' && line[*i] <= '9' && line[*i])
	{
		while (line[*i] >= '0' && line[*i] <= '9' && line[*i])
			str_color[j++] = line[(*i)++];
	}
	else
	{
		free(str_color);
		ft_free_uncomplete_data(data);
		ft_exit_with_error_var("Unknown element in color", line, 'r', 1);
	}
	return (str_color);
}

/*
 *	Function: ft_get_full_color
 *	-------------------------
 *	Get a color (texture) from the map configuration
 *
 *	data:	General data structure
 *	data_color: Color that will be extracted from the map configuration
 *	line: Current line in map configuration
 *
 */

void	ft_get_full_color(t_data *data, int *data_color, char *line)
{
	int		i;
	int		nb_count;
	int		color_count;

	i = 1;
	*data_color = 0;
	color_count = 0;
	while (line[i])
	{
		nb_count = -1;
		ft_check_color_value(data, line, i);
		ft_set_color(data, data_color, ft_color(data, line, &i), ++color_count);
		ft_skip_str(line, " \t", &i);
		if (line[i] != ',' && line[i] != '\0')
		{
			free(line);
			ft_exit_with_error_func("Colors not separated by coma",
				ft_free_uncomplete_data, data, 'r');
		}
		else if (line[i] != '\0')
			i++;
	}
	ft_check_color_count(data, color_count, line);
}

/*
 *	Function: ft_set_color
 *	-------------------------
 *	Allow the formating of a rgb string value to a single int
 *
 *	color: Contains the current color
 *	value: String that contains a r, g or b color
 *	color_pos: Position that correspond to 1, 2 or 3 to properly place a
 *	r, g or b value
 *
 */

void	ft_set_color(t_data *data, int *color, char *value, int color_pos)
{
	int	converted_color;
	int	i;

	i = 0;
	converted_color = ft_atoi(value);
	if (converted_color < 0 || converted_color > 255)
	{
		ft_free_uncomplete_data(data);
		ft_exit_with_error_var("Color not in the range [0,255]", value, 'r', 1);
	}
	if (color_pos == 1)
		*color = converted_color << 16 | *color;
	else if (color_pos == 2)
		*color = converted_color << 8 | *color;
	else if (color_pos == 3)
		*color = converted_color | *color;
	while (i < 3)
	{
		value[i] = '\0';
		i++;
	}
	free(value);
}
