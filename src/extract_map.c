/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:02:58 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/13 16:45:54 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i] && p < 2)
	{
		j = 0;
		while (map[i][j] || map[i][j] == '0'
			|| map[i][j] == '1' || map[i][j] == ' ')
			j++;
		if (map[i][j] || map[i][j] != 'N'
			|| map[i][j] != 'W' || map[i][j] != 'E'
			|| map[i][j] != 'S')
			return (ft_error('t'), -1);
		else
			p++;
		i++;
	}
	if (p >= 2)
		return (ft_error('p'), -1);
	return (1);
}
int	check_map(t_map *map)
{
	if (!check_player(map->tab))
		//|| flood_fill(map->pos_p_x, map->pos_p_y) == -1)
		return (-1);
	return(1);
}

char **ft_realloc_map(char **map_tab, int *size)
{
	char **new_map;
	int i;

	i = 0;
	new_map = malloc(sizeof(char *) *(*size + 1));
	while (i < *size)
	{
		new_map[i] = ft_strdup(map_tab[i]);
		free(map_tab[i]);
		i++;
	}
	free(map_tab);
	new_map[*size] = NULL;
	*size += 1;
	return(new_map);
} 

void	extract_map(t_map *map, char *line)
{
	int		i;

	i = 0;
	while (line)
	{
		map->tab = ft_realloc_map(map->tab, &map->size);
		map->tab[i] = ft_strdup(line);
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	check_map(map);
	
}