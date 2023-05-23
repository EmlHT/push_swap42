/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:09:50 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 10:37:26 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_list **list)
{
	*list = (*list)->prev;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_list **list)
{
	*list = (*list)->prev;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rr(t_list **lista, t_list **listb)
{
	*lista = (*lista)->prev;
	*listb = (*listb)->prev;
	write(1, "rrr\n", 4);
}
