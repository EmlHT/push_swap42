/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:45:28 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/04 20:56:08 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list	*new)
{
	t_list	*old_last;

	if (*lst == NULL)
	{
		new->prev = new;
		new->next = new;
		*lst = new;
		return ;
	}
	old_last = (*lst)->prev;
	new->next = *lst;
	new->prev = old_last;
	(*lst)->prev = new;
	old_last->next = new;
}
