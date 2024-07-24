/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:44 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 19:57:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	long	i;

	i = 0;
	temp = stack_a;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	i = 0;
	temp = stack_b;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

long	ft_find_target(long nb, t_list *stack_a, t_list *el)
{
	t_list	*temp;
	long	target;

	temp = stack_a;
	target = 999999999999999;
	while (temp)
	{
		if (temp->nb > nb && temp->nb < target)
		{
			target = temp->nb;
			el->index_target = temp->index;
			el->target_add = temp;
		}
		temp = temp->next;
	}
	return (target);
}

void	ft_set_targets(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	temp = stack_b;
	ft_set_index(stack_a, stack_b);
	while (temp)
	{
		temp->target = ft_find_target(temp->nb, stack_a, temp);
		temp = temp->next;
	}
}
