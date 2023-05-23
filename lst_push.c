/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:57:19 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 10:37:54 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **lista, t_list **listb)
{
	t_list	*tmp;

	if (listb == NULL)
		return ;
	tmp = *listb;
	if (ft_lstsize_mod(*listb) == 1)
		*listb = NULL;
	else
	{
		(*listb)->next->prev = (*listb)->prev;
		(*listb)->prev->next = (*listb)->next;
		*listb = (*listb)->next;
	}
	tmp->next = *lista;
	tmp->prev = (*lista)->prev;
	(*lista)->prev->next = tmp;
	(*lista)->prev = tmp;
	*lista = tmp;
	write (1, "pa\n", 3);
}

void	ft_push_b(t_list **listb, t_list **lista)
{
	t_list	*tmp;

	if ((*lista) == NULL)
		return ;
	tmp = *lista;
	(*lista)->next->prev = (*lista)->prev;
	(*lista)->prev->next = (*lista)->next;
	*lista = (*lista)->next;
	if ((*listb) == NULL)
	{
		*listb = tmp;
		(*listb)->next = tmp;
		(*listb)->prev = tmp;
		write(1, "pb\n", 3);
		return ;
	}
	tmp->next = *listb;
	tmp->prev = (*listb)->prev;
	(*listb)->prev->next = tmp;
	(*listb)->prev = tmp;
	*listb = tmp;
	write (1, "pb\n", 3);
}
