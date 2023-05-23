/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:06:19 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 18:46:04 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **lista, t_list **listb)
{
	int		i;
	int		len;

	if (ft_is_sort(lista) == (true))
		return ;
	i = 0;
	len = ft_lstsize(lista) - 1;
	while (i <= len)
	{
		if ((*lista)->index == len || (*lista)->index == len - 1
			|| (*lista)->index == len - 2)
			ft_rotate_a(lista);
		else if ((*lista)->index > len / 2)
		{
			ft_push_b(listb, lista);
			ft_rotate_b(listb);
		}
		else
			ft_push_b(listb, lista);
		i++;
	}
	ft_dispatch(lista, len);
}

void	move_up_to_a(t_list **listb, t_list **minindex)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *listb;
	while (tmp->index != (*minindex)->index)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < find_median(*listb))
		while (i-- > 0)
			ft_rotate_b(listb);
	else
	{
		i = (ft_lstsize_mod(*listb) - i);
		while (i-- > 0)
			ft_reverse_rotate_b(listb);
	}
}

void	organize_a(t_list **lista, t_list **valsup)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lista;
	while (tmp != *valsup)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < find_median(*lista))
		while (i-- > 0)
			ft_rotate_a(lista);
	else
	{
		i = (ft_lstsize_mod(*lista) - i);
		while (i-- > 0)
			ft_reverse_rotate_a(lista);
	}
}

void	move_after_calculate(t_list **lista, t_list **listb, t_list **minindex)
{
	t_calcul	calcul;

	calcul.coup_a = 0;
	calcul.coup_b = 0;
	calcul.median = find_median(*lista);
	calcul.valsup = find_val(lista, listb, (*minindex)->index);
	calcul.direction = count_opti_b(listb, minindex, &calcul.coup_b);
	if (calcul.direction == count_opti_a(lista, &calcul.valsup, &calcul.coup_a))
	{
		calculate_opti(&calcul);
		opti_rr_rrr(lista, listb, &calcul);
	}
	else
	{
		move_up_to_a(listb, minindex);
		organize_a(lista, &calcul.valsup);
	}
	ft_push_a(lista, listb);
}

void	reorganize_a(t_list **lista)
{
	int		median;
	t_list	*tmp;
	int		pos;

	tmp = *lista;
	median = find_median(*lista);
	while ((tmp)->index != 0)
		tmp = (tmp)->next;
	pos = find_pos(*lista, tmp);
	while (ft_is_sort(lista) != true)
	{
		if (pos < median)
		{
			pos = pos - 1;
			while (pos-- > 0)
				ft_rotate_a(lista);
		}
		else
		{
			pos = (ft_lstsize_mod(*lista) - pos + 1);
			while (pos-- > 0)
				ft_reverse_rotate_a(lista);
		}
	}
}
