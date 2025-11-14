/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:42:08 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 15:29:59 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"

#define screenWidth 640
#define screenHeight 640

void	do_landscape(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_LENGTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			if (j < WIN_HEIGHT / 2)
				my_mlx_pixel_put(d, i, j, 0x4B615C);
			else
				my_mlx_pixel_put(d, i, j, 0x5B4B61);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw(t_data *d, t_map *map)
{
	t_camera	*cam;
	int			i;
	int			drawstart;
	int			drawend;

	cam = init_cam();
	if (!cam)
		return ;
	do_landscape(d);
	cam = get_start_pos(cam, map);
	i = 0;
	while (i < WIN_LENGTH)
	{
		cam->hit = 0;
		cam->camerax = 2 * i / ((double)WIN_LENGTH - 1) - 1;
		cam->raydirx = cam->dirx + cam->planex * cam->camerax;
		cam->raydiry = cam->diry + cam->planey * cam->camerax;
		// case de depars
		cam->mapx = (int)cam->posx;
		cam->mapy = (int)cam->posy;
		// calcule du delta
		cam->deltadistx = fabs(1 / cam->raydirx);
		cam->deltadisty = fabs(1 / cam->raydiry);
		// calcule de la distance jusque la permiere grille -> side dist
		if (cam->raydirx < 0)
		{
			cam->stepx = -1;
			cam->sidedistx = (cam->posx - cam->mapx) * cam->deltadistx;
		}
		else
		{
			cam->stepx = 1;
			cam->sidedistx = (cam->mapx + 1.0 - cam->posx) * cam->deltadistx;
		}
		if (cam->raydiry < 0)
		{
			cam->stepy = -1;
			cam->sidedisty = (cam->posy - cam->mapy) * cam->deltadisty;
		}
		else
		{
			cam->stepy = 1;
			cam->sidedisty = (cam->mapy + 1.0 - cam->posy) * cam->deltadisty;
		}
		// boucle tant qu'on a pas touche de mur
		while (!cam->hit)
		{
			if (cam->sidedistx < cam->sidedisty)
			{
				cam->sidedistx += cam->deltadistx;
				cam->mapx += cam->stepx;
				cam->side = 0;
			}
			else
			{
				cam->sidedisty += cam->deltadisty;
				cam->mapy += cam->stepy;
				cam->side = 1;
			}
			if (map->tab[cam->mapx][cam->mapy] == '1')
				cam->hit = 1;
		}
		
		if (cam->side == 0)
			cam->perpwalldist = (cam->sidedistx - cam->deltadistx);
		else
			cam->perpwalldist = (cam->sidedisty - cam->deltadisty);
			
		cam->lineheight = (int)(WIN_LENGTH / cam->perpwalldist);
		
		drawstart = -cam->lineheight / 2 + WIN_LENGTH / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = cam->lineheight / 2 + WIN_LENGTH / 2;
		if (drawend >= WIN_LENGTH)
			drawend = WIN_LENGTH - 1;
		
		while (drawstart < drawend)
		{
			if (map->tab[cam->mapx][cam->mapy] > 0)
			{
				if (cam->side == 0)
					my_mlx_pixel_put(d, i, drawstart, 0x00FFFF);
				else
					my_mlx_pixel_put(d, i, drawstart, 0xFFFF00);
			}
			drawstart++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
