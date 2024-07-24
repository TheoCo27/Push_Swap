/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:29:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 14:48:32 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	long			nb;
	long			target;
	size_t			index;
	long			index_target;
	long			cost;
	struct s_list	*prev;
	struct s_list	*next;	
	struct s_list	*target_add;
}					t_list;

// ft_split.c
char	**ft_split(const char *s, char c);
size_t	ft_wrdcount(const char *str, char c);
void	*ft_free_all(char **tab);
// ft_nbr.c
long	ft_atol(const char *str);
long	*ft_insert_sort(long *tab, size_t size);
long	*ft_list2tab(t_list *stack_a, long *tab, size_t lst_size);
long	ft_median(t_list *stack_a, size_t lst_size);
void	ft_exit(t_list **stack_a, t_list **stack_b, int mode);
//ft_str.c
void	ft_putstr(char *s);
void	ft_puterror(char *s);
//ft_check.c
int		ft_isdigit(int c);
int		ft_is_sign(char c);
int		ft_check_input(char *str);
int		ft_check_list(t_list *list);
int		ft_check_if_sorted(t_list *stack_a);
// t_list
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(long nb);
size_t	ft_lstsize(t_list *lst);
char	**ft_make_inputs(int argc, char **argv);
t_list	*ft_makelst(t_list *stack_a, int argc, char **argv, size_t lst_size);
t_list	*ft_lstfirst(t_list *lst);
int		ft_lstone(t_list *lst);
//command_ps
void	ft_swap(t_list *stack_a, char ab);
void	ft_rotate(t_list *stack_a, char ab);
void	ft_reverse_rotate(t_list *stack_a, char ab);
void	ft_push(t_list **stack_a, t_list **stack_b, char ab);
void	ft_2swap(t_list *stack_a, t_list *stack_b);
void	ft_2rotate(t_list *stack_a, t_list *stack_b);
void	ft_2reverse(t_list *stack_a, t_list *stack_b);
// ft_small_sort
t_list	*ft_min(t_list *stack_a);
void	ft_small_sort(t_list *stack_a, size_t lst_size);
long	ft_max(t_list *stack_a);
//everything tested up till here
//ft_target.c
void	ft_set_index(t_list *stack_a, t_list *stack_b);
long	ft_find_target(long nb, t_list *stack_a, t_list *el);
void	ft_set_targets(t_list *stack_a, t_list *stack_b); // all good here
//ft_cost.c
long	ft_cost_to_top(t_list *el, size_t lst_size);
long	ft_c_min(long n1, long n2);
long	ft_c_max(long n1, long n2);
long	ft_common_cost(t_list *el_a, t_list *el_b, size_t sa, size_t sb);
t_list	*ft_best_cost(t_list *stack_a, t_list *stack_b);
//ft_treatment.c
void	ft_treat_a(t_list *a, t_list **h_a, size_t lst_size);
void	ft_treat_b(t_list *b, t_list **h_b, t_list **h_a, size_t lst_size);
//ft_big_sort.c
void	ft_fill_b(t_list **stack_a, t_list **stack_b);
void	ft_fill_a(t_list **stack_a);//problem here
void	ft_big_sort(t_list **stack_a, size_t i, size_t lst_size);

#endif