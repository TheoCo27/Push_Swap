/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:44:56 by tcohen            #+#    #+#             */
/*   Updated: 2024/07/23 15:10:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_make_inputs(int argc, char **argv)
{
	char	**inputs;

	inputs = NULL;
	if (argc == 2)
	{
		inputs = ft_split(argv[1], ' ');
		if (!inputs)
			return (NULL);
	}
	else
	{
		inputs = &argv[1];
	}
	return (inputs);
}

t_list	*ft_makelst(t_list *stack_a, int argc, char **argv, size_t lst_size)
{
	t_list	*new;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_make_inputs(argc, argv);
	if (!tab)
		return (NULL);
	if (argc == 2)
		lst_size = ft_wrdcount(argv[1], ' ');
	if (argc > 2)
		lst_size = argc -1;
	while (i < (int)lst_size)
	{
		new = ft_lstnew(ft_atol(tab[i]));
		ft_lstadd_back(&stack_a, new);
		if ((!new && argc == 2) || (argc == 2 && ft_check_input(tab[i]) == 1))
			return (ft_lstclear(&stack_a), ft_free_all(tab), NULL);
		if ((!new && argc > 2) || (argc > 2 && ft_check_input(tab[i]) == 1))
			return (ft_lstclear(&stack_a), NULL);
		i++;
	}
	if (argc == 2)
		ft_free_all(tab);
	return (stack_a);
}
