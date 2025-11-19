/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:37 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/19 10:24:09 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	move_forward(t_data	*d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy + d->cam->diry * 0.5)] != '1')
		d->cam->posy += d->cam->diry * d->cam->move_speed;
	if (d->map->tab[(int)(d->cam->posx + d->cam->dirx * 0.5)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += d->cam->dirx * d->cam->move_speed;
	// draw(d, d->map);
}

void	move_backward(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy - d->cam->diry * 0.5)] != '1')
		d->cam->posy += -d->cam->diry * d->cam->move_speed;
	if (d->map->tab[(int)(d->cam->posx - d->cam->dirx * 0.5)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += -d->cam->dirx * d->cam->move_speed;
	// draw(d, d->map);
}

void	move_left(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy + d->cam->dirx * 0.5)] != '1')
		d->cam->posy += d->cam->dirx * d->cam->move_speed;
	if (d->map->tab[(int)(d->cam->posx - d->cam->diry * 0.5)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += -d->cam->diry * d->cam->move_speed;
	// draw(d, d->map);
}

void	move_right(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy - d->cam->dirx * 0.5)] != '1')
		d->cam->posy += -d->cam->dirx * d->cam->move_speed;
	if (d->map->tab[(int)(d->cam->posx + d->cam->diry * 0.5)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += d->cam->diry * d->cam->move_speed;
	// draw(d, d->map);
}
