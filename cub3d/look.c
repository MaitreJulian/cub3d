/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:54:21 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 17:14:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/raycast.h"

void	look_right(t_data *d)
{
	d->cam->dirx += 0.5 * d->cam->planex;
	draw(d, d->map);
}

void	look_left(t_data *d)
{
	d->cam->dirx -= 0.5 * d->cam->planex;
	draw(d, d->map);
}
