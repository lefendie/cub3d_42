/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:00:35 by manjaro           #+#    #+#             */
/*   Updated: 2021/10/23 14:09:45 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_dim {
	int	width;
	int	height;
}								t_dim;

typedef struct s_pos {
	double	x;
	double	y;
	char	collision_side;	
	char	obstacle_type;
}								t_pos;

typedef struct s_grid_pos {
	int	x;
	int	y;
}								t_grid_pos;

typedef struct s_line {
	t_pos	*start;
	t_pos	*end;
}							t_line;

typedef struct s_vect
{
	int	x;
	int	y;
}								t_vect;

typedef struct s_object_inst {
	t_grid_pos	*position;
	t_line		*surface;
	double		angle;
	int			list_index;
	int			distance;
	int			path_index;
	int			start_column;
	int			end_column;
}								t_object_inst;

typedef struct s_object {
	t_object_inst	**instance_list;
	char			*path_file;
}								t_object;

typedef struct s_door {
	t_line	*surface;
	t_pos	*pos;
	char	side;
	int		status;
}							t_door;

typedef struct s_map {
	unsigned int	map_size;
	unsigned int	alloc_size;
	t_door			**door_list;
	char			**self;

}								t_map;

typedef struct s_player
{
	t_pos		*grid_position;
	t_pos		*pixel_position;
	int			health;
	int			speed;
}								t_player;

typedef struct s_img_data
{
	void	*self;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}								t_img_data;

typedef struct s_data_collision
{
	double	tan_angle;
	double	cos_angle;
	double	sin_angle;
	double	cos_correct_angle;
	double	current_angle;
	t_vect	*dir_vect;
	t_door	*curr_door;
	t_pos	*c_pos;
	t_pos	*h_pos;
	t_pos	*v_pos;
}							t_data_collision;

typedef struct s_angle_const
{
	double	left_angle;
	double	right_angle;
	double	up_angle;
	double	down_angle;
	double	cos_up_right_angle;
	double	sin_up_right_angle;
	double	degree_to_radian;
}							t_angle_const;

typedef struct s_data
{
	t_data_collision	*c_data;
	t_img_data			*img;
	t_img_data			*i_wall_no;
	t_img_data			*i_wall_so;
	t_img_data			*i_wall_ea;
	t_img_data			*i_wall_we;
	t_img_data			*i_floor;
	t_img_data			*i_ceiling;
	t_img_data			*i_door;
	t_grid_pos			*mouse_pos;
	t_angle_const		*a_const;
	t_player			*player;
	double				view_angle;
	double				fov;
	double				angle_increment;
	t_map				*map;
	void				*mlx_ptr;
	void				*mlx_win;
	void				*wall_no;
	void				*wall_we;
	void				*wall_ea;
	void				*wall_so;
	void				*floor;
	void				*ceiling;
	void				*door;
	int					mouse_control;
	int					dist_proj_plane;
	int					win_height;
	int					win_half_height;
	int					win_half_width;
	int					win_width;
	int					wall_height;
	int					wall_width;
	int					ceiling_color;
	int					floor_color;
	int					speed;
}								t_data;

typedef struct s_data_count
{
	unsigned int	map;
	unsigned int	pos;
	unsigned int	ceiling;
	unsigned int	floor;
	unsigned int	west;
	unsigned int	east;
	unsigned int	south;
	unsigned int	north;
}							t_data_count;

typedef struct s_slice_data
{
	double	current_angle;
	float	offset_y;
	float	increment;
	char	*img_line;
	char	collision_side;
	int		img_y;
	int		sprite_line;
	int		column;
	int		limit;
	int		offset_x;
}							t_slice_data;

#endif
