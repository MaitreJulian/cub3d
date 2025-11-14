/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:02:53 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/14 13:52:04 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

int	ft_error(char c)
{
	if (c == 'n')
		printf("Wrong name of file. Usage : map.cub");
	if (c == 'a')
		printf("Wrong RGB.");
	if (c == 'm')
		printf("Error malloc.");
	if (c == 'o')
		printf("Error open.");
	if (c == 't')
		printf("Error map.");
	if (c == 'p')
		printf("Error amount of player.");
	exit (1);
}
