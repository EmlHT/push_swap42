/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:56:58 by ehouot            #+#    #+#             */
/*   Updated: 2023/04/26 13:29:27 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_val(t_list **lista, t_list **listb, int ptindex)
{
	int		i;
	int		len;
	int		count_valsup;
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
	return (tmp);
}

int	count_opti_b(t_list **listb, t_list **minindex, int *coup_b)
{
	t_list	*tmp;

	tmp = *listb;
	while (tmp->index != (*minindex)->index)
	{
		(*coup_b)++;
		tmp = tmp->next;
	}
	if (*coup_b <= find_median(*listb))
		return (0);
	else
	{
		*coup_b = (ft_lstsize(listb) - (*coup_b));
		return (1);
	}
}

int	count_opti_a(t_list **lista, t_list **valsup, int *coup_a)
{
	t_list	*tmp;

	tmp = *lista;
	while (tmp != *valsup)
	{
		(*coup_a)++;
		tmp = tmp->next;
	}
	if ((*coup_a) <= find_median(*lista))
		return (0);
	else
	{
		*coup_a = (ft_lstsize(lista) - (*coup_a));
		return (1);
	}
}

void	calculate_opti(t_calcul *calcul)
{
	if (calcul->coup_b > calcul->coup_a)
	{
		calcul->nbr_coup = calcul->coup_a;
		calcul->coup_b = calcul->coup_b - calcul->coup_a;
		calcul->coup_a = 0;
	}
	else
	{
		calcul->nbr_coup = calcul->coup_b;
		calcul->coup_a = calcul->coup_a - calcul->coup_b;
		calcul->coup_b = 0;
	}
}

void	opti_rr_rrr(t_list **lista, t_list **listb, t_calcul *calcul)
{
	if (calcul->direction == 0)
	{
		while (calcul->nbr_coup-- > 0)
			ft_rotate_rr(lista, listb);
		while (calcul->coup_a-- > 0)
			ft_rotate_a(lista);
		while (calcul->coup_b-- > 0)
			ft_rotate_b(listb);
	}
	else
	{
		while (calcul->nbr_coup-- > 0)
			ft_reverse_rotate_rr(lista, listb);
		while (calcul->coup_a-- > 0)
			ft_reverse_rotate_a(lista);
		while (calcul->coup_b-- > 0)
			ft_reverse_rotate_b(listb);
	}
}
