/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:58:55 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 16:08:43 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void free_split(char **to_clean)
{
	int i;

	i = 0;
	if (!to_clean)
		return;
	while(to_clean[i])
	{
		free(to_clean[i]);
		i++;
	}
	free(to_clean); 
}
