/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainju.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:46:08 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/14 14:42:18 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

int	check_name(char *file)
{
	int		fd;
	char	*temp;

	fd = 0;
	temp = file;
	while (*temp && *temp != '.')
		temp++;
	if (*temp != '.')
		return (ft_error('n'));
	if (ft_strcmp(temp, ".cub"))
		return (ft_error('n'));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Open error");
		return (0);
	}
	return (fd);
}

t_map	*parse_map(char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	init_map(map, argv[1]);
	print_textures(map->texture);
	print_map(map->tab);
	return (map);
}
