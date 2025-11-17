/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:54:21 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/17 10:55:22 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	look_left(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->cam->dirx;
	d->cam->dirx = d->cam->dirx * cos(-d->cam->rot_speed)
		- d->cam->diry * sin(-d->cam->rot_speed);
	d->cam->diry = old_dir_x * sin(-d->cam->rot_speed)
		+ d->cam->diry * cos(-d->cam->rot_speed);
	old_plane_x = d->cam->planex;
	d->cam->planex = d->cam->planex * cos(-d->cam->rot_speed)
		- d->cam->planey * sin(-d->cam->rot_speed);
	d->cam->planey = old_plane_x * sin(-d->cam->rot_speed)
		+ d->cam->planey * cos(-d->cam->rot_speed);
	draw(d, d->map);
}

void	look_right(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->cam->dirx;
	d->cam->dirx = d->cam->dirx * cos(d->cam->rot_speed)
		- d->cam->diry * sin(d->cam->rot_speed);
	d->cam->diry = old_dir_x * sin(d->cam->rot_speed)
		+ d->cam->diry * cos(d->cam->rot_speed);
	old_plane_x = d->cam->planex;
	d->cam->planex = d->cam->planex * cos(d->cam->rot_speed)
		- d->cam->planey * sin(d->cam->rot_speed);
	d->cam->planey = old_plane_x * sin(d->cam->rot_speed)
		+ d->cam->planey * cos(d->cam->rot_speed);
	draw(d, d->map);
}
