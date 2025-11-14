/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:40:16 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 13:56:38 by gcauchy          ###   ########.fr       */
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  DEFINE  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

# define ESCAPE		65307
# define FORWARD	65362
# define BACKWARD	65364
# define LEFT		65361
# define RIGHT		65363
# define WIN_HEIGHT	640
# define WIN_LENGTH	640

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCT  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}			t_data;

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
}			t_camera;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~  PROTO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

t_camera	*init_cam(void);
t_camera	*get_start_pos(t_camera *cam, t_map *map);

void		draw(t_data *d, t_map *map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

int			display_error(char *s, int return_value, int fd);

#endif