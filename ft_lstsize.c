/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:53:40 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/11 14:16:56 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list **lst)
{
	int		size;
	t_list	*tmp;
	t_list	*first;

	size = 0;
	if (lst == NULL)
		return (0);
	first = *lst;
	tmp = (*lst)->next;
	while (tmp != first)
	{
		size++;
		tmp = tmp->next;
	}
	return (size + 1);
}
