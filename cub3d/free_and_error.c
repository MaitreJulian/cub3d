/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:44:32 by gcauchy           #+#    #+#             */
/*   Updated: 2025/12/09 10:41:13 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"

int	display_error(char *s, int return_value, int fd)
{
	ft_putendl_fd(s, fd);
	return (return_value);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	close(data->map->fd);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->imgs[0].img);
	mlx_destroy_image(data->mlx, data->imgs[1].img);
	mlx_destroy_image(data->mlx, data->imgs[2].img);
	mlx_destroy_image(data->mlx, data->imgs[3].img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(&(data->map));
	free(data->cam);
	free(data);
	exit (0);
	return (0);
}
