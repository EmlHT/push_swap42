/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:20:51 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 10:21:55 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_mod(t_list *lst)
{
	int		size;
	t_list	*tmp;
	t_list	*first;

	size = 0;
	if (lst == NULL)
		return (0);
	first = lst;
	tmp = lst->next;
	if (tmp == first)
		return (1);
	while (tmp != first)
	{
		size++;
		tmp = tmp->next;
	}
	return (size + 1);
}
