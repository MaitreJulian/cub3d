/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:42:08 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/18 11:53:23 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"

unsigned int	get_text_color(t_imgs *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

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
				my_mlx_pixel_put(d, i, j, 0xAFDAE0);
			else
				my_mlx_pixel_put(d, i, j, 0x756C66);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw(t_data *d, t_map *map)
{
	int		i;
	int		drawstart;
	int		drawend;

	do_landscape(d);
	if (d->cam->posx == -1 && d->cam->posy == -1)
		d->cam = get_start_pos(d->cam, map);
	i = 0;
	while (i < WIN_LENGTH)
	{
		d->cam->hit = 0;
		d->cam->camerax = 2 * i / ((double)WIN_LENGTH - 1) - 1;
		d->cam->raydirx = d->cam->dirx + d->cam->planex * d->cam->camerax;
		d->cam->raydiry = d->cam->diry + d->cam->planey * d->cam->camerax;
		// case de depars
		d->cam->mapx = (int)d->cam->posx;
		d->cam->mapy = (int)d->cam->posy;
		// calcule du delta
		d->cam->deltadistx = fabs(1 / d->cam->raydirx);
		d->cam->deltadisty = fabs(1 / d->cam->raydiry);
		// calcule de la distance jusque la permiere grille -> side dist
		if (d->cam->raydirx < 0)
		{
			d->cam->stepx = -1;
			d->cam->sidedistx = (d->cam->posx - d->cam->mapx) * d->cam->deltadistx;
		}
		else
		{
			d->cam->stepx = 1;
			d->cam->sidedistx = (d->cam->mapx + 1.0 - d->cam->posx) * d->cam->deltadistx;
		}
		if (d->cam->raydiry < 0)
		{
			d->cam->stepy = -1;
			d->cam->sidedisty = (d->cam->posy - d->cam->mapy) * d->cam->deltadisty;
		}
		else
		{
			d->cam->stepy = 1;
			d->cam->sidedisty = (d->cam->mapy + 1.0 - d->cam->posy) * d->cam->deltadisty;
		}
		// boucle tant qu'on a pas touche de mur
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
		
		if (d->cam->side == 0)
			d->cam->perpwalldist = (d->cam->sidedistx - d->cam->deltadistx);
		else
			d->cam->perpwalldist = (d->cam->sidedisty - d->cam->deltadisty);
			
		d->cam->lineheight = (int)(WIN_LENGTH / d->cam->perpwalldist);
		
		drawstart = -d->cam->lineheight / 2 + WIN_LENGTH / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = d->cam->lineheight / 2 + WIN_LENGTH / 2;
		if (drawend >= WIN_LENGTH)
			drawend = WIN_LENGTH - 1;
		
		while (drawstart < drawend)
		{
			if (map->tab[d->cam->mapx][d->cam->mapy] > 0)
			{
				if (d->cam->side == 0)
				{
					if (d->cam->raydirx > 0)
						my_mlx_pixel_put(d, i, drawstart, 0xDB6C3B);
					else
						my_mlx_pixel_put(d, i, drawstart, 0xABDB3B);
				}
				else
				{
					if (d->cam->raydiry > 0)
						my_mlx_pixel_put(d, i, drawstart, 0x3BABDB);
					else
						my_mlx_pixel_put(d, i, drawstart, 0x6B3BDB);
				}
			}
			drawstart++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	printf("posX : %f\n", d->cam->posx);
	printf("posY : %f\n", d->cam->posy);
	printf("dirX : %f\n", d->cam->dirx);
	printf("diry : %f\n\n", d->cam->diry);
}
