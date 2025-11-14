/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:46:08 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/13 14:36:19 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		printf("Wrong usage: ./cub3d map.cub\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	game = malloc(sizeof(t_game));
	init_map(map, argv[1]);
	print_textures(map->texture);
	print_map(map->tab);
	return (0);
}
