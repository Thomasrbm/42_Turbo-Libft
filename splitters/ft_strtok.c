/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:58 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:29:56 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtok(char *s, const char *delim)
{
	static char	*next;
	char		*start;

	if (s != NULL)
		next = s;
	if (next == NULL)
		return (NULL);
	while (*next && ft_strchr((char *)delim, *next))
		next++;
	if (*next == '\0')
		return (NULL);
	start = next;
	while (*next && !ft_strchr((char *)delim, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	else
		next = NULL;
	return (start);
}
