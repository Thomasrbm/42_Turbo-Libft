/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 05:53:32 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:26:57 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((!lst) || !(f))
		return ;
	while (lst != NULL)
	{
		f(lst ->content);
		lst = lst -> next;
	}
	return ;
}
