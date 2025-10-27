/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:18:07 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:27:15 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*create_node(void)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	return (new_node);
}

void	ft_lstadd_back2(t_list **lst_new, t_list *new_node)
{
	t_list	*ptr_temp;

	ptr_temp = *lst_new;
	if (!lst_new || !new_node)
		return ;
	if (*lst_new == NULL)
	{
		*lst_new = new_node;
		new_node->next = NULL;
		return ;
	}
	while (ptr_temp->next)
		ptr_temp = ptr_temp->next;
	ptr_temp->next = new_node;
	new_node->next = NULL;
}

void	free_cascade(t_list *lst_new, void (*del)(void *))
{
	t_list	*temp;

	while (lst_new)
	{
		temp = lst_new;
		lst_new = lst_new->next;
		del(temp->content);
		free(temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*new_node_ptr;

	lst_new = NULL;
	while (lst)
	{
		new_node_ptr = create_node();
		if (!new_node_ptr)
		{
			free_cascade(lst_new, del);
			return (NULL);
		}
		new_node_ptr->content = f(lst->content);
		new_node_ptr->next = NULL;
		ft_lstadd_back2(&lst_new, new_node_ptr);
		lst = lst->next;
	}
	return (lst_new);
}
