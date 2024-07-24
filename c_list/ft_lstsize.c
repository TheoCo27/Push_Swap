/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:42:12 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 20:02:24 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
