/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:44:26 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/20 19:57:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->prev == NULL)
			return (temp);
		temp = temp->prev;
	}
	return (temp);
}
