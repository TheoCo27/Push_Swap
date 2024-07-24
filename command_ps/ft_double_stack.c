/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:16:51 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 19:57:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_2swap(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	ft_putstr("ss\n");
}

void	ft_2rotate(t_list *stack_a, t_list *stack_b)
{
	ft_rotate(stack_a, 's');
	ft_rotate(stack_b, 's');
	ft_putstr("rr\n");
}

void	ft_2reverse(t_list *stack_a, t_list *stack_b)
{
	ft_reverse_rotate(stack_a, 's');
	ft_reverse_rotate(stack_b, 's');
	ft_putstr("rrr\n");
}
