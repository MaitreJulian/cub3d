/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:44:32 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 13:42:16 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"

int	display_error(char *s, int return_value, int fd)
{
	ft_putendl_fd(s, fd);
	return (return_value);
}