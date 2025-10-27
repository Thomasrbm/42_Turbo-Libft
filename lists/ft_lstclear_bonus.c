/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:46:53 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:26:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst1;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst1 = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lst1;
	}
	*lst = NULL;
	return ;
}
