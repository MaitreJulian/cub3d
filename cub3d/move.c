/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:37 by gcauchy           #+#    #+#             */
/*   Updated: 2025/12/05 10:28:01 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	move_forward(t_data	*d)
{
	if (d->map->tab[(int)d->cam->posx][(int)(d->cam->posy + d->cam->diry
		* (d->cam->move_speed + 0.1))] != '1')
		d->cam->posy += (d->cam->diry * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
	if (d->map->tab[(int)(d->cam->posx + d->cam->dirx
			* (d->cam->move_speed + 0.1))][(int)d->cam->posy] != '1')
		d->cam->posx += (d->cam->dirx * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
}

void	move_backward(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx][(int)(d->cam->posy - d->cam->diry
		* (d->cam->move_speed + 0.1))] != '1')
		d->cam->posy += -(d->cam->diry * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
	if (d->map->tab[(int)(d->cam->posx - d->cam->dirx
			* (d->cam->move_speed + 0.1))][(int)d->cam->posy] != '1')
		d->cam->posx += (-d->cam->dirx * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
}

void	move_left(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx][(int)(d->cam->posy + d->cam->dirx
		* (d->cam->move_speed + 0.1))] != '1')
		d->cam->posy += (d->cam->dirx * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
	if (d->map->tab[(int)(d->cam->posx - d->cam->diry
			* (d->cam->move_speed + 0.1))][(int)d->cam->posy] != '1')
		d->cam->posx += (-d->cam->diry * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
}

void	move_right(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx][(int)(d->cam->posy - d->cam->dirx
		* (d->cam->move_speed + 0.1))] != '1')
		d->cam->posy += (-d->cam->dirx * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
	if (d->map->tab[(int)(d->cam->posx + d->cam->diry
			* (d->cam->move_speed + 0.1))][(int)d->cam->posy] != '1')
		d->cam->posx += (d->cam->diry * (d->cam->size / 5000.0)
				* (d->cam->size / 2500.0));
}
