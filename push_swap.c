/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:04:34 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 15:26:45 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	lst_size;
	t_list	*stack_a;

	if (argc == 1 || argv[1][0] == '\0')
		exit(0);
	stack_a = NULL;
	lst_size = 0;
	stack_a = ft_makelst(stack_a, argc, argv, lst_size);
	if (!stack_a)
		return (ft_puterror("Error\n"), 0);
	if (ft_check_list(stack_a) == 1)
		return (ft_puterror("Error\n"), ft_lstclear(&stack_a), 0);
	if (ft_check_if_sorted(stack_a) == 0)
		return (ft_lstclear(&stack_a), 0);
	if (ft_lstsize(stack_a) <= 3)
		ft_small_sort(stack_a, ft_lstsize(stack_a));
	else
	{
		ft_big_sort(&stack_a, 0, ft_lstsize(stack_a));
	}
	ft_lstclear(&stack_a);
	return (0);
}
