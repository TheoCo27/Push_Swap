/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:43:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/21 12:35:07 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list *stack_a, char ab)
{
	long	temp;

	if (ft_lstone(stack_a) == 0 || !stack_a)
		return ;
	temp = stack_a->nb;
	stack_a->nb = stack_a->next->nb;
	stack_a->next->nb = temp;
	if (ab == 'a')
		ft_putstr("sa\n");
	else if (ab == 'b')
		ft_putstr("sb\n");
}

// 1st become last
void	ft_rotate(t_list *stack_a, char ab)
{
	t_list	*index;
	long	first_nb_temp;

	index = stack_a;
	first_nb_temp = index->nb;
	if (ft_lstsize(stack_a) <= 1)
		return ;
	while (index)
	{
		index->nb = index->next->nb;
		index = index->next;
		if (index->next == NULL)
			break ;
	}
	index->nb = first_nb_temp;
	if (ab == 'a')
		ft_putstr("ra\n");
	else if (ab == 'b')
		ft_putstr("rb\n");
}

// Last become 1st
void	ft_reverse_rotate(t_list *stack_a, char ab)
{
	t_list	*last_index;
	long	last_nb_temp;

	if (ft_lstsize(stack_a) <= 1)
		return ;
	last_index = ft_lstlast(stack_a);
	last_nb_temp = last_index->nb;
	while (last_index)
	{
		last_index->nb = last_index->prev->nb;
		last_index = last_index->prev;
		if (last_index->prev == NULL)
			break ;
	}
	last_index->nb = last_nb_temp;
	if (ab == 'a')
		ft_putstr("rra\n");
	else if (ab == 'b')
		ft_putstr("rrb\n");
}

static void	ft_push_one(t_list **stack_a, t_list **stack_b, char ab)
{
	t_list	*l1;
	t_list	*l2;

	l1 = *stack_a;
	l2 = NULL;
	ft_lstadd_front(stack_b, l1);
	*stack_a = NULL;
	if (ab == 'a')
		ft_putstr("pa\n");
	else if (ab == 'b')
		ft_putstr("pb\n");
}

void	ft_push(t_list **stack_a, t_list **stack_b, char ab)
{
	t_list	*l1;
	t_list	*l2;

	if (!*stack_a)
		return ;
	if (ft_lstone(*stack_a) == 0)
	{
		ft_push_one(stack_a, stack_b, ab);
	}
	else
	{
		l1 = *stack_a;
		l2 = l1->next;
		ft_lstadd_front(stack_b, l1);
		*stack_a = l2;
		l2->prev = NULL;
		if (ab == 'a')
			ft_putstr("pa\n");
		else if (ab == 'b')
			ft_putstr("pb\n");
	}
}
