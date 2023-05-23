/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:58:44 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 18:48:41 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_parse *parse)
{
	parse->i = 0;
	parse->nbr = 0;
}

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;
	t_list	*minindex;
	t_parse	parse;

	if (argc == 1)
		exit (0);
	lista = NULL;
	listb = NULL;
	initialize(&parse);
	if (argc >= 2)
		lista = parsing_str(argv, argc, &lista, &parse);
	if (ft_lstsize(&lista) <= 3)
		ft_dispatch(&lista, ft_lstsize(&lista) - 1);
	else
	{
		move_to_b(&lista, &listb);
		while (ft_lstsize_mod(listb) > 0)
		{
			minindex = ft_calculate(&lista, &listb);
			move_after_calculate(&lista, &listb, &minindex);
		}
		reorganize_a(&lista);
	}
	return (0);
}
