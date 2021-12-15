/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:10:05 by manjaro           #+#    #+#             */
/*   Updated: 2021/09/27 15:53:57 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_process_main(argv[1]);
	else if (argc < 2)
		ft_exit_with_error("Need a valid map as argument", 'r');
	else if (argc > 2)
		ft_exit_with_error("Too much arguments", 'r');
}
