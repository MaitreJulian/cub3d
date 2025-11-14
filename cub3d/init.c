/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:12:48 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 15:55:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"
#include "stdio.h"

static void	get_map_pos(t_camera *cam, char pos)
{
	if (pos == 'S') // regarde au Sud
	{
		cam->dirx = -1;
		cam->diry = 0;
		cam->planey = 0.66;
	}
	else if (pos == 'N') // regarde au Nord
	{
		cam->dirx = 1;
		cam->diry = 0;
		cam->planey = -0.66;
	}
	else if (pos == 'E') // regarde a l'Est
	{
		cam->dirx = 0;
		cam->diry = 1;
		cam->planex = 0.66;
	}
	else // regarde a l'Ouest
	{
		cam->dirx = 0;
		cam->diry = -1;
		cam->planex = -0.66;
	}
}

t_camera	*get_start_pos(t_camera *cam, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'N' || map->tab[i][j] == 'S'
				|| map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
			{
				get_map_pos(cam, map->tab[i][j]);
				map->tab[i][j] = '0';
				cam->posx = i + 0.5;
				cam->posy = j + 0.5;
				return (cam);
			}
			j++;
		}
		i++;
	}
	return (cam);
}

t_camera	*init_cam(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (ft_putendl_fd("Malloc cam failed", 2), NULL);
	cam->posx = 0;
	cam->posy = 0;
	cam->planex = 0;
	cam->planey = 0;
	cam->hit = 0;
	return (cam);
}
