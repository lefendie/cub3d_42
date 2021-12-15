/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:45:19 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/21 09:21:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <errno.h>
# include <math.h>

# include "cub3d_struct.h"
# include "parser.h"
# include "raycast.h"
# include "input.h"
# include "error.h"
# include "image.h"
# include "process.h"
# include "other.h"

# define PLAYER_HEIGHT 32.0
# define SUCCESS 1
# define FAILURE 0
# define SIZE_X 640
# define SIZE_Y 400
# define TAB 9
# define SPACE 32
# define BONUS 0

int	ft_log_data(int key, t_data *data);

#endif
