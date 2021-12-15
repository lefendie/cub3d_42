/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:10:05 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/20 21:11:15 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_process_main_with_bonus(argv[1]);
	else if (argc < 2)
		ft_exit_with_error("Need a valid map as argument", 'r');
	else if (argc > 2)
		ft_exit_with_error("Too much arguments", 'r');
	return (SUCCESS);
}
