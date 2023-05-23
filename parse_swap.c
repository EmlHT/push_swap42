/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:09:54 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 18:24:52 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free((void *)splited[i++]);
	free((void *)splited);
	return (true);
}

bool	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	int		len;

	if (!lst)
		return (true);
	tmp = *lst;
	len = ft_lstsize_mod(*lst);
	while (len > 0)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		len--;
	}
	free(lst);
	return (true);
}

bool	check_error(char **res_split)
{
	int	i;
	int	j;

	i = 0;
	while (res_split[i])
	{
		j = 0;
		while (res_split[i][j])
		{
			if (ft_isdigit(res_split[i][j]) == 0
			&& !(res_split[i][j] == '-' || res_split[i][j] == '+'))
				return (ft_free_split(res_split));
			if (ft_isdigit(res_split[i][j]) == 1 && res_split[i][j + 1] != '\0'
			&& (res_split[i][j + 1] == '-' || res_split[i][j + 1] == '+'))
				return (ft_free_split(res_split));
			if (res_split[i][j] == '-' || res_split[i][j] == '+')
				if (res_split[i][j + 1] != '\0'
				&& ft_isdigit(res_split[i][j + 1]) == 0)
					return (ft_free_split(res_split));
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_double(t_list **list)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*first;

	i = ft_lstsize(list);
	first = *list;
	tmp = *list;
	tmp2 = (*list)->next;
	while (i >= 0)
	{
		while (tmp2 != tmp)
		{
			if (tmp->content == tmp2->content)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		i--;
		tmp = tmp->next;
	}
	return (false);
}

t_list	*parsing_str(char **argv, int argc, t_list **list, t_parse *parse)
{
	char	**res_split;
	t_list	*new;

	while (++parse->i < argc)
	{
		res_split = ft_split(argv[parse->i], ' ');
		if (check_error(res_split) == true)
			exit(write(2, "Error\n", 6));
		parse->j = -1;
		while (res_split[++parse->j])
		{
			if (ft_atoi(res_split[parse->j], &parse->nbr) != 0)
			{
				ft_free_split(res_split);
				exit (1);
			}
			new = ft_lstnew(parse->nbr);
			ft_lstadd_back(list, new);
		}
		ft_free_split(res_split);
	}
	if (check_double(list) == true)
		exit(1);
	indexation(list);
	return (*list);
}
