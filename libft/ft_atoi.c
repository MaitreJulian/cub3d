/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:25:58 by jvenkata          #+#    #+#             */
/*   Updated: 2024/11/12 09:25:58 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
		if (nbr < 0 && sign == 1)
			return (-1);
		if (nbr < 0 && sign == -1)
			return (-1);
	}
	return (nbr * sign);
}

// #include <stdio.h>

// int main()
// {
// 	printf("vr : %d\n", atoi("\010 9"));
// 	printf("ft : %d\n", ft_atoi("\010 9"));
// 	return (0);
// }