/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:37 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/17 14:18:10 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	move_forward(t_data	*d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy + d->cam->diry)] != '1')
		d->cam->posy += d->cam->diry;
	if (d->map->tab[(int)(d->cam->posx + d->cam->dirx)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += d->cam->dirx;
	draw(d, d->map);
}

void	move_backward(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy - d->cam->diry)] != '1')
		d->cam->posy += -d->cam->diry;
	if (d->map->tab[(int)(d->cam->posx - d->cam->dirx)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += -d->cam->dirx;
	draw(d, d->map);
}

void	move_left(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy + d->cam->dirx)] != '1')
		d->cam->posy += d->cam->dirx;
	if (d->map->tab[(int)(d->cam->posx - d->cam->diry)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += -d->cam->diry;
	draw(d, d->map);
}

void	move_right(t_data *d)
{
	if (d->map->tab[(int)d->cam->posx]
		[(int)(d->cam->posy - d->cam->dirx)] != '1')
		d->cam->posy += -d->cam->dirx;
	if (d->map->tab[(int)(d->cam->posx + d->cam->diry)]
		[(int)d->cam->posy] != '1')
		d->cam->posx += d->cam->diry;
	draw(d, d->map);
}
