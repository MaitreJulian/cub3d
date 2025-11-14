/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:37 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 16:45:24 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	move_forward(t_data	*d)
{
	if (d->cam->dirx == 0)
		d->cam->posy += d->cam->diry;
	else
		d->cam->posx += d->cam->dirx;
	draw(d, d->map);
}

void	move_backward(t_data	*d)
{
	if (d->cam->dirx == 0)
		d->cam->posy += -d->cam->diry;
	else
		d->cam->posx += -d->cam->dirx;
	draw(d, d->map);
}

void	move_left(t_data	*d)
{
	if (d->cam->diry == 0)
		d->cam->posy += d->cam->dirx;
	else
		d->cam->posx += -d->cam->diry;
	draw(d, d->map);
}

void	move_right(t_data	*d)
{
	if (d->cam->diry == 0)
		d->cam->posy += -d->cam->dirx;
	else
		d->cam->posx += d->cam->diry;
	draw(d, d->map);
}
