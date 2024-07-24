/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:03:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 20:02:49 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstone(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (i <= 2)
	{
		if (temp == NULL)
			break ;
		temp = temp->next;
		i++;
	}
	if (i == 1)
		return (0);
	else
		return (1);
}
