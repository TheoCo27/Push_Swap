/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:01:17 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 13:38:57 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_cost_to_top(t_list *el, size_t lst_size)
{
	long	cost;

	cost = 0;
	if (el->index > lst_size / 2)
		cost = lst_size - el->index;
	else
		cost = el->index;
	return (cost);
}

long	ft_c_min(long n1, long n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

long	ft_c_max(long n1, long n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

long	ft_common_cost(t_list *el_a, t_list *el_b, size_t sa, size_t sb)
{
	if (el_a->index > sa / 2)
	{		
		return ((sa - el_a->index) + ft_c_min(ft_c_max(0, (sb - el_b->index)
					- (sa - el_a->index)), el_b->index));
	}
	else
	{
		return (el_a->index + ft_c_min(ft_c_max(0, el_b->index - el_a->index),
				sb - el_b->index));
	}
}

t_list	*ft_best_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	t_list	*best_cost;
	size_t	sa;
	size_t	sb;

	sa = ft_lstsize(stack_a);
	sb = ft_lstsize(stack_b);
	temp = stack_b;
	best_cost = NULL;
	ft_set_targets(stack_a, stack_b);
	while (temp)
	{
		temp->cost = ft_common_cost(temp->target_add, temp, sa, sb);
		if (best_cost == NULL)
			best_cost = temp;
		if (temp->cost < best_cost->cost)
			best_cost = temp;
		if (temp->cost == 0)
			return (temp);
		temp = temp->next;
	}
	return (best_cost);
}
