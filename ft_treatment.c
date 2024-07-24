/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:31:23 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 19:57:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_treat_a(t_list *a, t_list **h_a, size_t lst_size)
{
	long	i;
	long	rest;

	rest = ft_cost_to_top(a, lst_size);
	i = 0;
	if (a->index > lst_size / 2)
	{
		while (i < rest)
		{
			ft_reverse_rotate(*h_a, 'a');
			i++;
		}
	}
	else if (a->index <= lst_size / 2)
	{
		while (i < rest)
		{
			ft_rotate(*h_a, 'a');
			i++;
		}
	}
}

void	ft_treat_b(t_list *b, t_list **h_b, t_list **h_a, size_t lst_size)
{
	long	i;
	long	rest;

	rest = ft_cost_to_top(b, lst_size);
	i = 0;
	if (b->index > lst_size / 2)
	{
		while (i < rest)
		{
			ft_reverse_rotate(*h_b, 'b');
			i++;
		}
	}
	else if (b->index <= lst_size / 2)
	{
		while (i < rest)
		{
			ft_rotate(*h_b, 'b');
			i++;
		}
	}
	ft_set_index(*h_b, *h_b);
	ft_push(h_b, h_a, 'a');
}
