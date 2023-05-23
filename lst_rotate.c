/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:11:32 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 10:37:14 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **list)
{
	*list = (*list)->next;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **list)
{
	*list = (*list)->next;
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_list **lista, t_list **listb)
{
	*lista = (*lista)->next;
	*listb = (*listb)->next;
	write(1, "rr\n", 3);
}
