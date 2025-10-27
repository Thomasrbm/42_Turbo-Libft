/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:15:59 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:25:25 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char unsigned	*sc1;
	char unsigned	*sc2;

	sc1 = (char unsigned *) s1;
	sc2 = (char unsigned *) s2;
	while (n != 0)
	{
		if (*sc1 != *sc2)
		{
			return (*sc1 - *sc2);
		}
		sc1++;
		sc2++;
		n--;
	}
	return (0);
}
