/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:41:03 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/19 13:01:49 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

void	pos_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tab[++i])
	{
		j = 0;
		while ((map->tab[i][j] == '0' || map->tab[i][j] == '1'
			|| map->tab[i][j] == ' ')
			&& map->tab[i][j])
			j++;
		if (map->tab[i][j] == 'N' || map->tab[i][j] == 'W'
			|| map->tab[i][j] == 'E' || map->tab[i][j] == 'S')
		{
			map->pos_p_x = j;
			map->pos_p_y = i;
			return ;
		}
	}
}

int	flood_fill(char **map, int i, int j)
{
	if (!map[i][j] || map[i][j] == ' ')
		return (0);
	if (map[i][j] == '1' || map[i][j] == 'Y')
		return (1);
	if (map[i][j] == '0' || map[i][j] == 'E'
		|| map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'N')
	{
		map[i][j] = 'Y';
		if (!flood_fill(map, i + 1, j))
			return (0);
		if (!flood_fill(map, i - 1, j))
			return (0);
		if (!flood_fill(map, i, j + 1))
			return (0);
		if (!flood_fill(map, i, j - 1))
			return (0);
	}
	return (1);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (map[++i] && p < 2)
	{
		j = 0;
		while (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ')
			j++;
		if (map[i][j] == '\0')
			continue ;
		if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
			|| map[i][j] == 'S')
		{
			p++;
		}
		else
			return (ft_error('t'));
	}
	if (p == 0 || p >= 2)
		return (ft_error('p'));
	return (1);
}

int	check_map(t_map *map)
{
	char	**map_copy;

	map_copy = copy_map (map->tab);
	if (check_player(map->tab) == -1)
		return (0);
	pos_player(map);
	if (!flood_fill(map_copy, map->pos_p_y, map->pos_p_x))
	{
		free_tab(map_copy);
		return (0);
	}
	return (1);
}