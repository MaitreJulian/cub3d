/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:40:16 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/17 14:58:56 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "cub3d.h"
# include <math.h>
# include <sys/time.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  DEFINE  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

# define ESCAPE		65307
# define FORWARD	119
# define BACKWARD	115
# define LEFT		97
# define RIGHT		100
# define LOOK_R		65361
# define LOOK_L		65363
# define WIN_HEIGHT	1200
# define WIN_LENGTH	1200

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCT  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct s_camera
{
	double	camerax;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	raydirx;
	double	raydiry;
	double	planex;
	double	planey;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	stepx;
	double	stepy;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		hit;
	int		side;
	int		lineheight;
	double	rot_speed;
}			t_camera;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*addr;
	void		*img;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	t_camera	*cam;
	t_map		*map;
}				t_data;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  PROTO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

// INIT
t_camera	*init_cam(void);
t_camera	*get_start_pos(t_camera *cam, t_map *map);

// PRINT SCREEN
void		draw(t_data *d, t_map *map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

// MOVE
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

// LOOK
void		look_right(t_data *d);
void		look_left(t_data *d);

// UTILS
int			display_error(char *s, int return_value, int fd);

#endif