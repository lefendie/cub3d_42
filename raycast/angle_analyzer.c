/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_analyzer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:55:19 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/19 14:55:29 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_increment_angle
 *	-------------------------
 *	Increments the radian angle with the increment from 0 to 2M_PI
 *
 *	radian_angle: Radian angle to increment
 *	increment: Increment for the radian angle
 *	right_angle: constant that correspond to 2M_PI
 *
 *	Returns: The incremented angle
 */

double	ft_increment_angle(double radian_angle, double increment,
	double right_angle)
{
	radian_angle += increment;
	if (radian_angle > right_angle)
		radian_angle -= right_angle;
	else if (radian_angle < 0)
		radian_angle += right_angle;
	return (radian_angle);
}

/*
 *	Function: ft_set_angle_values
 *	-------------------------
 *	Preset math values from the current_angle
 *
 *	data: General data structure
 *	c_data: Contains raycast data
 *	current_angle: Radian angle that will be computed 
 *
 */

void	ft_set_angle_values(t_data_collision *c_data, t_data *data,
		double current_angle)
{
	c_data->tan_angle = tan(current_angle);
	c_data->cos_angle = cos(current_angle);
	c_data->sin_angle = sin(current_angle);
	c_data->cos_correct_angle = cos(data->view_angle - current_angle);
	c_data->current_angle = current_angle;
}

/*
 *	Function: ft_set_angle_const
 *	-------------------------
 *	Set the constants used in raycast that
 *	cannot be defined as real constants because of the 42 norm
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_set_angle_const(t_data *data)
{
	data->a_const = malloc(sizeof(t_angle_const));
	if (!(data->a_const))
		return (FAILURE);
	data->a_const->left_angle = M_PI;
	data->a_const->right_angle = M_PI * 2;
	data->a_const->up_angle = M_PI / 2;
	data->a_const->down_angle = (3 * M_PI) / 2;
	data->a_const->degree_to_radian = M_PI / 180;
	data->a_const->cos_up_right_angle = (cos(M_PI / 4)) / 2;
	data->a_const->sin_up_right_angle = (sin(M_PI / 4)) / 2;
	return (SUCCESS);
}

/*
 *	Function: ft_set_dir_vector
 *	-------------------------
 *	Set the direction vector to avoid use of angle and math computation
 *
 *	c_data: Contains raycast data
 *	a_const: Data for angles constans 
 *
 */

void	ft_set_dir_vector(t_data_collision *c_data, t_angle_const *a_const)
{
	if (c_data->current_angle < a_const->left_angle
		&& c_data->current_angle > 0)
		c_data->dir_vect->y = -1;
	else
		c_data->dir_vect->y = 1;
	if (c_data->current_angle < a_const->down_angle
		&& c_data->current_angle > a_const->up_angle)
		c_data->dir_vect->x = -1;
	else
		c_data->dir_vect->x = 1;
}
