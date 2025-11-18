/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:57:43 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/18 13:09:43 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"
#include "include/cub3d.h"

// calcule de la distance jusque la permiere grille -> side dist
void	side_dist(t_data *d)
{
	if (d->cam->raydirx < 0)
	{
		d->cam->stepx = -1;
		d->cam->sidedistx = (d->cam->posx - d->cam->mapx) * d->cam->deltadistx;
	}
	else
	{
		d->cam->stepx = 1;
		d->cam->sidedistx = (d->cam->mapx + 1.0 - d->cam->posx)
			* d->cam->deltadistx;
	}
	if (d->cam->raydiry < 0)
	{
		d->cam->stepy = -1;
		d->cam->sidedisty = (d->cam->posy - d->cam->mapy) * d->cam->deltadisty;
	}
	else
	{
		d->cam->stepy = 1;
		d->cam->sidedisty = (d->cam->mapy + 1.0 - d->cam->posy)
			* d->cam->deltadisty;
	}
}

// boucle tant qu'on a pas touche de mur
void	detect_wall(t_data *d, t_map *map)
{
	while (!d->cam->hit)
	{
		if (d->cam->sidedistx < d->cam->sidedisty)
		{
			d->cam->sidedistx += d->cam->deltadistx;
			d->cam->mapx += d->cam->stepx;
			d->cam->side = 0;
		}
		else
		{
			d->cam->sidedisty += d->cam->deltadisty;
			d->cam->mapy += d->cam->stepy;
			d->cam->side = 1;
		}
		if (map->tab[d->cam->mapx][d->cam->mapy] == '1')
			d->cam->hit = 1;
	}
}

void	size_wall(t_data *d)
{
	if (d->cam->side == 0)
		d->cam->perpwalldist = (d->cam->sidedistx - d->cam->deltadistx);
	else
		d->cam->perpwalldist = (d->cam->sidedisty - d->cam->deltadisty);
	d->cam->lineheight = (int)(WIN_LENGTH / d->cam->perpwalldist);
	d->cam->draw_start = -d->cam->lineheight / 2 + WIN_LENGTH / 2;
	if (d->cam->draw_start < 0)
		d->cam->draw_start = 0;
	d->cam->draw_end = d->cam->lineheight / 2 + WIN_LENGTH / 2;
	if (d->cam->draw_end >= WIN_LENGTH)
		d->cam->draw_end = WIN_LENGTH - 1;
}
