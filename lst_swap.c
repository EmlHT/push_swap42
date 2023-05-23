/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:45:58 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 10:36:58 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*prev;
	t_list	*next;

	tmp1 = *list;
	tmp2 = (*list)->next;
	prev = (*list)->prev;
	next = tmp2->next;
	if (next == tmp1)
	{
		*list = tmp2;
		write(1, "sa\n", 3);
		return ;
	}
	prev->next = tmp2;
	next->prev = tmp1;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	tmp2->prev = prev;
	tmp1->next = next;
	*list = tmp2;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*prev;
	t_list	*next;

	tmp1 = *list;
	tmp2 = (*list)->next;
	prev = (*list)->prev;
	next = (*list)->next->next;
	if (next == tmp1)
	{
		*list = tmp2;
		write(1, "sb\n", 3);
		return ;
	}
	tmp2->prev = prev;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = next;
	*list = tmp2;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list **lista, t_list **listb)
{
	ft_swap_a(lista);
	ft_swap_b(listb);
	write(1, "ss\n", 3);
}
