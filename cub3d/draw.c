/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:42:08 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/19 16:13:48 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"

unsigned int	get_text_color(t_imgs *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

static void	do_landscape(t_data *d)
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
				my_mlx_pixel_put(d, i, j, d->map->texture->ceiling);
			else
				my_mlx_pixel_put(d, i, j, d->map->texture->floor);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

// // SIMPLE COLOR
// static void	draw_to_screen(t_data *d, t_map *map, int i)
// {
// 	while (d->cam->draw_start < d->cam->draw_end)
// 	{
// 		if (map->tab[d->cam->mapx][d->cam->mapy] > 0)
// 		{
// 			if (d->cam->side == 0)
// 			{
// 				if (d->cam->raydirx > 0)
// 					my_mlx_pixel_put(d, i, d->cam->draw_start, 0xDB6C3B);
// 				else
// 					my_mlx_pixel_put(d, i, d->cam->draw_start, 0xABDB3B);
// 			}
// 			else
// 			{
// 				if (d->cam->raydiry > 0)
// 					my_mlx_pixel_put(d, i, d->cam->draw_start, 0x3BABDB);
// 				else
// 					my_mlx_pixel_put(d, i, d->cam->draw_start, 0x6B3BDB);
// 			}
// 		}
// 		d->cam->draw_start++;
// 	}
// }

// TEXTURED WALL
static t_imgs	*get_text_img(t_data *d)
{
	t_imgs	*im;
	double	wall_x;

	if (!d->cam->side && d->cam->raydirx < 0)
		im = &d->imgs[0];
	else if (!d->cam->side && d->cam->raydirx > 0)
		im = &d->imgs[1];
	else if (d->cam->side && d->cam->raydiry < 0)
		im = &d->imgs[2];
	else
		im = &d->imgs[3];
	if (!d->cam->side)
		wall_x = d->cam->posy + d->cam->perpwalldist * d->cam->raydiry;
	else
		wall_x = d->cam->posx + d->cam->perpwalldist * d->cam->raydirx;
	wall_x -= floor(wall_x);
	d->cam->tex_x = (int)(wall_x * (double)im->width);
	if (!d->cam->side && d->cam->raydirx > 0)
		d->cam->tex_x = im->width - d->cam->tex_x - 1;
	else if (d->cam->side && d->cam->raydiry < 0)
		d->cam->tex_x = im->width - d->cam->tex_x - 1;
	return (im);
}

static void	draw_tex(t_data *d, int i, t_imgs *im)
{
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	step = 1.0 * im->height / d->cam->lineheight;
	tex_pos = (d->cam->draw_start - WIN_HEIGHT / 2
			+ d->cam->lineheight / 2) * step;
	while (d->cam->draw_start < d->cam->draw_end)
	{
		tex_y = (int)tex_pos % (im->height - 1);
		tex_pos += step;
		color = get_text_color(im, d->cam->tex_x, tex_y);
		my_mlx_pixel_put(d, i, d->cam->draw_start, color);
		d->cam->draw_start++;
	}
}

void	draw(t_data *d, t_map *map)
{
	int		i;
	t_imgs	*im;

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
		d->cam->mapx = (int)d->cam->posx;
		d->cam->mapy = (int)d->cam->posy;
		d->cam->deltadistx = fabs(1 / d->cam->raydirx);
		d->cam->deltadisty = fabs(1 / d->cam->raydiry);
		side_dist(d);
		detect_wall(d, map);
		size_wall(d);
		im = get_text_img(d);
		draw_tex(d, i, im);
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

// printf("posX : %f\n", d->cam->posx);
// printf("posY : %f\n", d->cam->posy);
// printf("dirX : %f\n", d->cam->dirx);
// printf("diry : %f\n\n", d->cam->diry);
