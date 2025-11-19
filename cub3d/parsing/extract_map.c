/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:02:58 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/19 14:21:52 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

char	**ft_realloc_map(char **map_tab, int *size)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) *(*size + 1));
	if (!new_map)
	{
		while (map_tab[i])
		{
			free(map_tab[i]);
			i++;
		}
		free(map_tab);
		return (NULL);
	}
	while (i < *size)
	{
		new_map[i] = ft_strdup(map_tab[i]);
		free(map_tab[i]);
		i++;
	}
	free(map_tab);
	new_map[*size] = NULL;
	*size += 1;
	return (new_map);
}

void	extract_map(t_map **map, char *line)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (line)
	{
		(*map)->tab = ft_realloc_map((*map)->tab, &(*map)->size);
		if (!(*map)->tab)
		{
			ft_error('m');
			return ;
		}
		(*map)->tab[i] = ft_strdup(line);
		free(line);
		line = get_next_line((*map)->fd);
		i++;
	}
	if (!check_map(*map))
	{
		ft_error('t');
		free_map(map);
	}
}
