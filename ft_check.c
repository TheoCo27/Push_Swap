/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:28:40 by theog             #+#    #+#             */
/*   Updated: 2024/07/20 19:57:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_is_sign(char c)
{
	if ((c == '-') || (c == '+'))
		return (1);
	return (0);
}

int	ft_check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && ft_is_sign(str[i]) == 1 && ft_is_sign(str[i + 1]) == 1)
			return (1);
		if (i == 0 && ft_is_sign(str[i]) == 1)
			i++;
		if (ft_isdigit((int)str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_list(t_list *list)
{
	t_list	*index_1;
	t_list	*index_2;

	index_1 = list;
	if (!list)
		return (0);
	while (index_1)
	{
		if (index_1->nb > 2147483647 || index_1->nb < -2147483648)
			return (1);
		index_2 = index_1->next;
		while (index_2)
		{
			if (index_1->nb == index_2->nb)
				return (1);
			index_2 = index_2->next;
		}
		index_1 = index_1->next;
	}
	return (0);
}

int	ft_check_if_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->nb > temp->next->nb)
			return (1);
		temp = temp->next;
		if (temp->next == NULL)
			break ;
	}
	return (0);
}
