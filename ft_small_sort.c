/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:35 by theog             #+#    #+#             */
/*   Updated: 2024/07/20 20:08:19 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_min(t_list *stack_a)
{
	t_list	*temp;
	t_list	*min;

	temp = stack_a;
	min = stack_a;
	if (!stack_a)
		return (NULL);
	if (ft_lstone(stack_a) == 0)
		return (stack_a);
	while (temp)
	{
		if (min->nb > temp->next->nb)
			min = temp->next;
		temp = temp->next;
		if (temp->next == NULL)
			break ;
	}
	return (min);
}

long	ft_max(t_list *stack_a)
{
	t_list	*temp;
	int		max;

	temp = stack_a;
	max = stack_a->nb;
	while (temp)
	{
		if (max < temp->nb)
			max = temp->nb;
		temp = temp->next;
	}
	return (max);
}

void	ft_small_sort(t_list *stack_a, size_t lst_size)
{
	t_list	*temp;

	temp = stack_a;
	if (lst_size == 2)
	{
		if (temp->nb > temp->next->nb)
			ft_swap(stack_a, 'a');
	}
	if (lst_size == 3)
	{
		if (temp->nb == ft_max(stack_a))
			ft_rotate(stack_a, 'a');
		if (temp->next->nb == ft_max(stack_a))
			ft_reverse_rotate(stack_a, 'a');
		if (temp->nb > temp->next->nb)
			ft_swap(stack_a, 'a');
	}
}
