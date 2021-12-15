/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:46 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/23 10:53:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_continue_vertical_bonus(t_data *data, t_data_collision *c_data)
{
	double	increment;
	t_pos	*vertical_pos;
	t_pos	*collision_pos;
	int		wall_hit;

	vertical_pos = c_data->v_pos;
	collision_pos = c_data->c_pos;
	increment = fabs(c_data->tan_angle);
	increment *= c_data->dir_vect->y;
	if (collision_pos->collision_side == 'v')
	{
		wall_hit = ft_collision_bonus(data, vertical_pos, data->map->self,
				c_data->dir_vect);
		while (collision_pos->collision_side == 'v' && !wall_hit)
		{
			vertical_pos->x += c_data->dir_vect->x;
			vertical_pos->y += increment;
			collision_pos->collision_side = ft_collision_side(c_data);
			if (collision_pos->collision_side == 'v')
				wall_hit = ft_collision_bonus(data, vertical_pos,
						data->map->self, c_data->dir_vect);
		}
	}
}

void	ft_continue_horizontal_bonus(t_data *data, t_data_collision *c_data)
{
	double	increment;
	t_pos	*horizontal_pos;
	t_pos	*collision_pos;
	int		wall_hit;

	increment = fabs(1 / c_data->tan_angle);
	increment *= c_data->dir_vect->x;
	collision_pos = c_data->c_pos;
	horizontal_pos = c_data->h_pos;
	if (collision_pos->collision_side == 'h')
	{
		wall_hit = ft_collision_bonus(data, horizontal_pos,
				data->map->self, c_data->dir_vect);
		while (collision_pos->collision_side == 'h' && !wall_hit)
		{
			horizontal_pos->y += c_data->dir_vect->y;
			horizontal_pos->x += increment;
			collision_pos->collision_side = ft_collision_side(c_data);
			wall_hit = ft_collision_bonus(data, horizontal_pos,
					data->map->self, c_data->dir_vect);
		}
	}
}

int	ft_get_dda_collision_bonus(t_data *data, t_data_collision *c_data)
{
	char	**map;
	int		ht;

	map = data->map->self;
	c_data->c_pos->obstacle_type = '0';
	ft_first_vertical_pos(data->player->grid_position, c_data);
	ft_first_horizontal_pos(data->player->grid_position, c_data);
	ft_collision_pos(c_data);
	ht = ft_collision_bonus(data, c_data->c_pos, map, c_data->dir_vect);
	if (ht)
		return (ft_get_distance_from_player(data, c_data->c_pos, c_data));
	while (!ht)
	{
		ft_continue_horizontal_bonus(data, c_data);
		ft_continue_vertical_bonus(data, c_data);
		if (c_data->c_pos->collision_side == 'h')
			ht = ft_collision_bonus(data, c_data->h_pos, map, c_data->dir_vect);
		else
			ht = ft_collision_bonus(data, c_data->v_pos, map, c_data->dir_vect);
	}
	if (c_data->c_pos->collision_side == 'h')
		ft_copy_pos(c_data->h_pos, c_data->c_pos);
	else
		ft_copy_pos(c_data->v_pos, c_data->c_pos);
	return (ft_get_distance_from_player(data, c_data->c_pos, c_data));
}

int	ft_continue_dda_collision_bonus(t_data *data, t_data_collision *c_data)
{
	char	**map;
	int		wall_hit;

	map = data->map->self;
	ft_jump_dda_collision(data->c_data);
	wall_hit = ft_collision_bonus(data, c_data->c_pos,
			map, c_data->dir_vect);
	if (wall_hit)
		return (ft_get_distance_from_player(data, c_data->c_pos, c_data));
	while (!wall_hit)
	{
		ft_continue_vertical_bonus(data, c_data);
		ft_continue_horizontal_bonus(data, c_data);
		if (c_data->c_pos->collision_side == 'h')
			wall_hit = ft_collision_bonus(data, c_data->h_pos,
					map, c_data->dir_vect);
		else
			wall_hit = ft_collision_bonus(data, c_data->v_pos,
					map, c_data->dir_vect);
	}
	if (c_data->c_pos->collision_side == 'h')
		ft_copy_pos(c_data->h_pos, c_data->c_pos);
	else
		ft_copy_pos(c_data->v_pos, c_data->c_pos);
	return (ft_get_distance_from_player(data, c_data->c_pos, c_data));
}

void	ft_jump_dda_collision(t_data_collision *c_data)
{
	double	increment;

	if (c_data->c_pos->collision_side == 'h')
	{
		increment = fabs(1 / c_data->tan_angle);
		increment *= c_data->dir_vect->x;
		c_data->h_pos->y += c_data->dir_vect->y;
		c_data->h_pos->x += increment;
		ft_collision_pos(c_data);
	}
	else if (c_data->c_pos->collision_side == 'v')
	{
		increment = fabs(c_data->tan_angle);
		increment *= c_data->dir_vect->y;
		c_data->v_pos->x += c_data->dir_vect->x;
		c_data->v_pos->y += increment;
		ft_collision_pos(c_data);
	}
}
