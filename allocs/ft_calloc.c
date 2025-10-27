/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:13:42 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:25:43 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_zero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n != 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (size == 0 || nmemb == 0)
	{
		str = malloc(0);
		if (!str)
			return (NULL);
		return (str);
	}
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_zero(str, nmemb * size);
	return (str);
}
