/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:01:01 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 17:17:55 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int *nbr)
{
	int		i;
	long	nb;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '\0'))
			return (write(2, "Error\n", 6));
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if ((nb > 2147483647 && sign == 1) || (nb > 2147483648 && sign == -1))
			return (write(2, "Error\n", 6));
		i++;
	}
	*nbr = ((int)nb * sign);
	return (0);
}
