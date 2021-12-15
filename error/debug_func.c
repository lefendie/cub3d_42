/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:40:39 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/19 18:03:26 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_debug_error_pos
 *	-------------------------
 *	Prints the position given in parameter
 *
 *	pos: pos to print
 *
 */

void	ft_debug_error_pos(void *pos)
{
	t_grid_pos	*error_pos;

	error_pos = (t_grid_pos *)pos;
	printf("Issue at {%d;%d}\n", error_pos->x, error_pos->y);
}

/*
 *	Function: ft_debug_data
 *	-------------------------
 *	Print all the missing element that needs to be defined in data
 *
 *	data: data variable that contains data of the program
 *
 */

void	ft_debug_data(void *data)
{
	t_data	*data_temp;

	data_temp = (t_data *)data;
	if (data_temp->wall_ea == NULL)
		printf(" EA ");
	if (data_temp->wall_so == NULL)
		printf(" SO ");
	if (data_temp->wall_no == NULL)
		printf(" NO ");
	if (data_temp->wall_we == NULL)
		printf(" WE ");
	if (data_temp->floor_color == -1)
		printf(" F ");
	if (data_temp->ceiling_color == -1)
		printf(" C ");
	printf("\n");
}

int	ft_log_data(int key, t_data *data)
{
	if (key == 'p')
	{
		printf("PLAYER POSITION PIXEL : {%f;%f}\n\r",
			data->player->pixel_position->x,
			data->player->pixel_position->y);
		printf("PLAYER POSITION GRID  : {%f;%f}\n\r",
			data->player->grid_position->x,
			data->player->grid_position->y);
		printf("PLAYER POSITION GRID INT : {%d;%d}\n\r",
			(int)data->player->grid_position->x,
			(int)data->player->grid_position->y);
		printf("PLAYER VIEW ANGLE  : {%d}\n\r",
			(int)(data->view_angle * (180 / M_PI)));
	}
	return (SUCCESS);
}

void	ft_printmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->self[i++])
		printf("|%s|\n", map->self[i]);
	i = 0;
}
