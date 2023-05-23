/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:44:49 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/03 18:49:19 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_calcul
{
	int		median;
	t_list	*valsup;
	int		coup_a;
	int		coup_b;
	int		direction;
	int		nbr_coup;
}	t_calcul;

typedef struct s_parse
{
	int	i;
	int	j;
	int	nbr;
}	t_parse;

int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *nbr);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **lst);
int		ft_lstsize_mod(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_swap_a(t_list **list);
void	ft_swap_b(t_list **list);
void	ft_swap_ss(t_list **lista, t_list **listb);
void	ft_push_a(t_list **lista, t_list **listb);
void	ft_push_b(t_list **listb, t_list **lista);
void	ft_rotate_a(t_list **list);
void	ft_rotate_b(t_list **list);
void	ft_rotate_rr(t_list **lista, t_list **listb);
void	ft_reverse_rotate_a(t_list **list);
void	ft_reverse_rotate_b(t_list **list);
void	ft_reverse_rotate_rr(t_list **lista, t_list **listb);
bool	ft_is_sort(t_list **lista);
void	ft_dispatch(t_list	**lista, int len);
t_list	*parsing_str(char **argv, int argc, t_list **list, t_parse *parse);
void	indexation(t_list **list);
void	ft_sort_three(t_list **lista, int indexmax);
void	move_to_b(t_list **lista, t_list **listb);
int		count_for_this_pt(t_list **lista,
			t_list **listb, t_list **pt, int median);
t_list	*ft_calculate(t_list **lista, t_list **listb);
void	move_after_calculate(t_list **lista,
			t_list **listb, t_list **minindex);
void	reorganize_a(t_list **lista);
int		find_median(t_list *list);
int		find_pos(t_list *list, t_list *pt);
int		find_val_sup(t_list **lista, t_list **listb, int ptindex);
t_list	*find_val(t_list **lista, t_list **listb, int ptindex);
int		count_opti_b(t_list **listb, t_list **minindex, int *coup_b);
int		count_opti_a(t_list **lista, t_list **valsup, int *coup_a);
void	calculate_opti(t_calcul *calcul);
void	opti_rr_rrr(t_list **lista, t_list **listb, t_calcul *calcul);
bool	ft_lstclear(t_list **lst);

#endif