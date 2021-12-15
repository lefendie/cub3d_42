/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:07:43 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/19 14:04:59 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_process_main
 *	-------------------------
 *	Main process of the game
 *
 *	map_path: Path to the map file
 *
 *	Returns: Success state
 */

int	ft_process_main(char *map_path)
{
	t_data	*data;

	printf("Initialising ...\n");
	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	data->mouse_pos = malloc(sizeof(t_pos));
	if (!data->mouse_pos)
		return (FAILURE);
	ft_initialize_data(data, map_path);
	mlx_mouse_get_pos(data->mlx_ptr, data->mlx_win,
		&data->mouse_pos->x, &data->mouse_pos->y);
	printf("Executing ...\n");
	ft_print_image(data);
	mlx_loop_hook(data->mlx_win, ft_print_image, data);
	mlx_hook(data->mlx_win, 33, 0L, ft_listen_mouse_click, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_listen_key_pressed, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_listen_key_just_pressed, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}
