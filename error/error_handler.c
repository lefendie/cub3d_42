/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:11:32 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/12 14:29:45 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 *	Function: ft_choose_print_color
 *	-------------------------
 *	Changes the color property of printf
 *
 *	color: first letter of each color available for printf
 *	(b, r, g, y, p, c, w)
 *
 */

void	ft_choose_print_color(char color)
{
	if (color == 'b')
		printf("\033[0;34m");
	else if (color == 'r')
		printf("\033[0;31m");
	else if (color == 'g')
		printf("\033[0;32m");
	else if (color == 'y')
		printf("\033[0;33m");
	else if (color == 'p')
		printf("\033[0;35m");
	else if (color == 'c')
		printf("\033[0;36m");
	else if (color == 'w')
		printf("\033[0;37m");
}

/*
 *	Function: ft_exit_with_error
 *	-------------------------
 *	Exit the program with a color for the first message Error 
 *	and prints the error_message
 *
 *	error_message: Custom message that will be printed
 *	color: Color for Error
 *
 */

void	ft_exit_with_error(char *error_message, char color)
{
	ft_choose_print_color(color);
	printf("Error\n");
	printf("\033[0m");
	printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

/*
 *	Function: ft_exit_with_error_func
 *	-------------------------
 *	Exit the program with a color for the first message Error 
 *	and prints the error_message with data printed by a debug function
 *
 *	error_message: Custom message that will be printed
 *	func: debug function to print additional data
 *	data: data for the debug function
 *	color: Color for Error
 *
 */

void	ft_exit_with_error_func(char *error_message, void (*func)(void *data),
		void *data, char color)
{
	ft_choose_print_color(color);
	printf("Error\n");
	printf("\033[0m");
	printf("%s\n", error_message);
	func(data);
	exit(EXIT_FAILURE);
}

/*
 *	Function: ft_exit_with_error_var
 *	-------------------------
 *	Exit the program with a color for the first message Error 
 *	and prints the error_message with simple additionnal data
 *
 *	error_message: Custom message that will be printed
 *	additional_info: Additional data to print
 *	color: Color for Error
 *
 */

void	ft_exit_with_error_var(char *error_message, char *additional_info,
		char color, unsigned int allocated)
{
	ft_choose_print_color(color);
	printf("Error\n");
	printf("\033[0m");
	if (*additional_info)
		printf("%s : ", additional_info);
	printf("%s\n", error_message);
	if (allocated)
		free(additional_info);
	exit(EXIT_FAILURE);
}
