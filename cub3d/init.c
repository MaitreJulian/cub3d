/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:12:48 by gcauchy           #+#    #+#             */
/*   Updated: 2025/12/09 11:36:33 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"
#include "stdio.h"

static int	load_img(t_data	*d, int i)
{
	char	*file;

	if (i == 0)
		file = d->map->texture->north;
	else if (i == 1)
		file = d->map->texture->south;
	else if (i == 2)
		file = d->map->texture->west;
	else
		file = d->map->texture->east;
	d->imgs[i].img = mlx_xpm_file_to_image(d->mlx, file,
			&d->imgs[i].width, &d->imgs[i].height);
	if (!d->imgs[i].img)
		return (0);
	d->imgs[i].addr = mlx_get_data_addr(d->imgs[i].img, &d->imgs[i].bpp,
			&d->imgs[i].line_len, &d->imgs[i].endian);
	return (1);
}

static void	get_map_pos(t_camera *cam, char pos)
{
	if (pos == 'N')
	{
		cam->dirx = -1;
		cam->diry = 0;
		cam->planey = 0.66;
	}
	else if (pos == 'S')
	{
		cam->dirx = 1;
		cam->diry = 0;
		cam->planey = -0.66;
	}
	else if (pos == 'E')
	{
		cam->dirx = 0;
		cam->diry = 1;
		cam->planex = 0.66;
	}
	else
	{
		cam->dirx = 0;
		cam->diry = -1;
		cam->planex = -0.66;
	}
}

t_camera	*get_start_pos(t_camera *cam, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'N' || map->tab[i][j] == 'S'
				|| map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
			{
				get_map_pos(cam, map->tab[i][j]);
				map->tab[i][j] = '0';
				cam->posx = i + 0.5;
				cam->posy = j + 0.5;
				return (cam);
			}
			j++;
		}
		i++;
	}
	return (cam);
}

t_camera	*init_cam(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (ft_putendl_fd("Malloc cam failed", 2), NULL);
	cam->posx = -1;
	cam->posy = -1;
	cam->planex = 0;
	cam->planey = 0;
	cam->hit = 0;
	cam->rot_speed = ((double)WIN_LENGTH / 20000.0)
		* ((double)WIN_HEIGHT) / 1500;
	cam->move_speed = 0.25;
	cam->size = ((double)WIN_HEIGHT + (double)WIN_LENGTH) / 2;
	return (cam);
}

t_data	*init_img(t_data *d)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		d->imgs[i].bpp = 32;
		if (!load_img(d, i))
		{
			while (i-- > 0)
				mlx_destroy_image(d->mlx, d->imgs[i].img);
			mlx_destroy_display(d->mlx);
			return (free_map(&d->map), free(d->mlx), free(d), NULL);
		}
		i++;
	}
	d->key.up = 0;
	d->key.down = 0;
	d->key.right = 0;
	d->key.left = 0;
	d->key.look_r = 0;
	d->key.look_l = 0;
	return (d);
}
