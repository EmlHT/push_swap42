/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:28:47 by ehouot            #+#    #+#             */
/*   Updated: 2023/03/28 19:15:03 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_min(t_list **list)
{
	int		valmin;
	t_list	*tmp;
	t_list	*first;

	tmp = *list;
	first = *list;
	valmin = tmp->content;
	tmp = tmp->next;
	while (tmp != first)
	{
		if (tmp->content < valmin)
			valmin = tmp->content;
		tmp = tmp->next;
	}
	return (valmin);
}

int	val_max(t_list **list)
{
	t_list	*tmp;
	t_list	*first;
	int		valmax;

	tmp = *list;
	first = *list;
	tmp = tmp->next;
	valmax = INT_MIN;
	while (tmp != first)
	{
		if (tmp->content > valmax)
			valmax = tmp->content;
		tmp = tmp->next;
	}
	return (valmax);
}

static int	val_min(t_list **list, int currentmin)
{
	int		valmin;
	int		valmax;
	t_list	*tmp;
	t_list	*first;

	tmp = *list;
	first = *list;
	valmax = val_max(list);
	valmin = INT_MAX;
	tmp = tmp->next;
	while (tmp != first)
	{
		if (tmp->content < valmin && tmp->content > currentmin)
			valmin = tmp->content;
		tmp = tmp->next;
	}
	return (valmin);
}

void	indexation(t_list **list)
{
	int		i;
	int		valmin;
	int		lst_size;
	t_list	*tmp;
	t_list	*first;

	i = 0;
	tmp = *list;
	lst_size = ft_lstsize(list);
	first = *list;
	tmp = tmp->next;
	valmin = first_min(list);
	while (i < lst_size)
	{
		if (tmp->content == valmin)
		{
			tmp->index = i;
			i++;
			if (i == lst_size)
				break ;
			valmin = val_min(&tmp, valmin);
		}
		tmp = tmp->next;
	}
}
