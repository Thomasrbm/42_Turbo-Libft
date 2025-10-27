/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:32:28 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:26:31 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst1;

	if (!new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	lst1 = (*lst);
	while (lst1->next)
		lst1 = lst1->next;
	lst1->next = new;
	return ;
}
