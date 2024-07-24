/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:50:06 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 14:51:39 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	long	i;

	i = 0;
	sign = 1;
	result = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

long	*ft_insert_sort(long *tab, size_t size)
{
	long	i;
	long	j;
	long	key;

	i = 1;
	while (i < (long)size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
	return (tab);
}

long	*ft_list2tab(t_list *stack_a, long *tab, size_t lst_size)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = stack_a;
	while (i < lst_size)
	{
		tab[i] = temp->nb;
		i++;
		temp = temp->next;
	}
	return (tab);
}

long	ft_median(t_list *stack_a, size_t lst_size)
{
	long	median;
	long	*tab;

	median = 0;
	tab = (long *)malloc(sizeof(long) * (lst_size + 1));
	if (!tab)
		return (9999999999);
	tab = ft_list2tab(stack_a, tab, lst_size);
	tab = ft_insert_sort(tab, lst_size);
	if (lst_size % 2 != 0)
		median = tab[((lst_size + 1) / 2) - 1];
	else
	{
		median = tab[(lst_size / 2) - 1] + tab[((lst_size + 1) / 2) - 1];
		median = median / 2;
	}
	free (tab);
	return (median);
}

void	ft_exit(t_list **stack_a, t_list **stack_b, int mode)
{
	if (mode == 1)
	{
		ft_lstclear(stack_a);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		exit(EXIT_FAILURE);
	}
}
