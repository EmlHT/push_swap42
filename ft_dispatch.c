/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:13:41 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 18:47:02 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **lista)
{
	ft_rotate_a(lista);
	return ;
}

void	ft_sort_three(t_list **lista, int indexmax)
{
	t_list	*tmp;

	tmp = *lista;
	if (tmp->index == indexmax - 2)
	{
		ft_swap_a(&tmp);
		ft_rotate_a(&tmp);
	}
	else if (tmp->index == indexmax - 1)
	{
		if (tmp->next->index == indexmax - 2)
			ft_swap_a(&tmp);
		else
			ft_reverse_rotate_a(&tmp);
	}
	else if (tmp->next->index == indexmax - 2)
		ft_rotate_a(&tmp);
	else if (tmp->index == indexmax && tmp->next->index == indexmax - 1)
	{
		ft_swap_a(&tmp);
		ft_reverse_rotate_a(&tmp);
	}
	*lista = tmp;
}

bool	ft_is_sort(t_list **lista)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*first;
	int		i;
	int		lstsize;

	i = 0;
	lstsize = ft_lstsize(lista);
	tmp = *lista;
	tmp2 = (*lista)->next;
	first = *lista;
	while (i < lstsize - 1)
	{
		if (tmp->index != (tmp2->index) - 1)
			return (false);
		i++;
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	return (true);
}

void	ft_dispatch(t_list	**lista, int indexmax)
{
	if (ft_is_sort(lista) == true)
		return ;
	if (ft_lstsize(lista) == 2)
		ft_sort_two(lista);
	if (ft_lstsize(lista) == 3)
		ft_sort_three(lista, indexmax);
	return ;
}
