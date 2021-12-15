/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:10:31 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/22 11:11:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
 *	Function: ft_alloc_each_door
 *	-------------------------
 *	Allocate space for each door in the map and giving them positions
 *
 *	data: General data structure 
 *	map: Map of the game
 *
 */

void	ft_alloc_each_door(t_data *data, char **map)
{
	unsigned int	y;
	int				x;
	int				i;

	y = 0;
	i = 0;
	ft_alloc_door_list(data, map);
	while (y < data->map->map_size)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
			{
				ft_alloc_door(data, x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
	data->map->door_list[i] = (void *)0;
}

/*
 *	Function: ft_alloc_door
 *	-------------------------
 *	Allocate a door and gives it pos data according to position in the map
 *
 *	data: General data structure 
 *	x: x position in the map
 *	y: y position in the map
 *	i: index in the list of door_list
 *
 *	Returns: Success state
 */

int	ft_alloc_door(t_data *data, int x, int y, int i)
{
	data->map->door_list[i] = malloc(sizeof(t_door));
	if (!data->map->door_list[i])
		return (FAILURE);
	data->map->door_list[i]->pos = malloc(sizeof(t_pos));
	if (!data->map->door_list[i]->pos)
		return (FAILURE);
	data->map->door_list[i]->surface = malloc(sizeof(t_line));
	if (!data->map->door_list[i]->surface)
		return (FAILURE);
	data->map->door_list[i]->surface->start = malloc(sizeof(t_pos));
	if (!data->map->door_list[i]->surface->start)
		return (FAILURE);
	data->map->door_list[i]->surface->end = malloc(sizeof(t_pos));
	if (!data->map->door_list[i]->surface->end)
		return (FAILURE);
	ft_set_pos(data->map->door_list[i]->pos, x, y);
	return (SUCCESS);
}

/*
 *	Function: ft_alloc_door
 *	-------------------------
 *	Allocate door_list from data->map
 *
 *	data: General data structure 
 *	map: Map of the game
 *
 *	Returns: Success state
 */

int	ft_alloc_door_list(t_data *data, char **map)
{
	unsigned int	y;
	int				door_list_count;
	int				x;

	y = 0;
	door_list_count = 0;
	while (y < data->map->map_size)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
				door_list_count++;
			x++;
		}
		y++;
	}
	data->map->door_list = malloc(sizeof(t_door *) * (door_list_count + 1));
	if (!data->map->door_list)
		return (FAILURE);
	return (SUCCESS);
}
