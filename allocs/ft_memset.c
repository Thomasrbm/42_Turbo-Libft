/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:49:06 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:25:55 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char unsigned	*str;
	size_t			a;

	str = (char unsigned *) s;
	a = 0;
	while (n != 0)
	{
		str[a] = c;
		str++;
		n--;
	}
	return (s);
}
