/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:18:13 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 14:49:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_b(t_list **stack_a, t_list **stack_b)
{
	long	median;
	size_t	lst_size;
	size_t	i;

	lst_size = ft_lstsize(*stack_a);
	i = 0;
	median = ft_median(*stack_a, lst_size);
	if (median == 9999999999)
		ft_exit(stack_a, stack_b, 1);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->nb > median)
		{
			ft_rotate(*stack_a, 'a');
		}
		else
		{
			ft_push(stack_a, stack_b, 'b');
			median = ft_median(*stack_a, ft_lstsize(*stack_a));
			if (median == 9999999999)
				ft_exit(stack_a, stack_b, 2);
		}
		i++;
	}
	ft_small_sort(*stack_a, ft_lstsize(*stack_a));
}

void	ft_fill_a(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*best_move;

	stack_b = NULL;
	ft_fill_b(stack_a, &stack_b);
	while (stack_b)
	{
		best_move = ft_best_cost(*stack_a, stack_b);
		ft_treat_a(best_move->target_add, stack_a, ft_lstsize(*stack_a));
		ft_treat_b(best_move, &stack_b, stack_a, ft_lstsize(stack_b));
	}
}

void	ft_big_sort(t_list **stack_a, size_t i, size_t lst_size)
{	
	t_list	*min;

	ft_fill_a(stack_a);
	ft_set_index(*stack_a, *stack_a);
	min = ft_min(*stack_a);
	if (ft_check_if_sorted(*stack_a) == 0)
		return ;
	if (min->index > lst_size / 2)
	{
		while (i < ((long)lst_size - min->index))
		{
			ft_reverse_rotate(*stack_a, 'a');
			i++;
		}
	}
	else if (min->index <= lst_size / 2)
	{
		while (i < min->index)
		{
			ft_rotate(*stack_a, 'a');
			i++;
		}
	}
}
