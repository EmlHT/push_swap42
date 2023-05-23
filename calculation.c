/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:29:45 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/25 14:20:48 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_list *list)
{
	int		len;
	int		med;

	len = ft_lstsize(&list);
	med = len / 2;
	return (med);
}

int	find_pos(t_list *list, t_list *pt)
{
	t_list	*tmp;
	int		pos;
	int		len;
	int		i;

	tmp = list;
	len = ft_lstsize(&list);
	pos = 1;
	i = 0;
	while (i < len)
	{
		if (tmp->index == pt->index)
			return (pos);
		i++;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_val_sup(t_list **lista, t_list **listb, int ptindex)
{
	int		i;
	int		len;
	int		count_valsup;
	int		pos;
	t_list	*tmp;

	tmp = *lista;
	i = 0;
	len = ft_lstsize(lista);
	count_valsup = len + ft_lstsize(listb);
	while (i < len)
	{
		if (tmp->index > ptindex && tmp->index < count_valsup)
			count_valsup = tmp->index;
		i++;
		tmp = tmp->next;
	}
	while (tmp->index != count_valsup)
		tmp = tmp->next;
	pos = find_pos(*lista, tmp);
	if (pos < find_median(*lista))
		count_valsup = pos - 1;
	else
		count_valsup = len - pos + 1;
	return (count_valsup);
}

int	count_for_this_pt(t_list **lista, t_list **listb, t_list **pt, int median)
{
	int		pos_pt;
	int		len;
	int		count_valsup;
	int		median_a;
	t_list	*tmpb;

	tmpb = *listb;
	pos_pt = find_pos(tmpb, *pt);
	median_a = find_median(*lista);
	len = ft_lstsize(listb);
	count_valsup = find_val_sup(lista, listb, (*pt)->index);
	if (pos_pt < median)
		pos_pt = pos_pt - 1;
	else
		pos_pt = len - pos_pt + 1;
	pos_pt = count_valsup + pos_pt;
	return (pos_pt + 1);
}

t_list	*ft_calculate(t_list **lista, t_list **listb)
{
	int		i;
	int		cheapest;
	int		len;
	t_list	*minindex;
	t_list	*tmpb;

	minindex = *listb;
	tmpb = *listb;
	i = 0;
	len = ft_lstsize(listb);
	cheapest = count_for_this_pt(lista, listb, &tmpb, find_median(*listb));
	while (i < len && cheapest != 1)
	{
		tmpb = tmpb->next;
		if (cheapest
			> count_for_this_pt(lista, listb, &tmpb, find_median(*listb)))
		{
			cheapest
				= count_for_this_pt(lista, listb, &tmpb, find_median(*listb));
			minindex = tmpb;
		}
		i++;
	}
	return (minindex);
}
