/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 05:11:59 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:24:42 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long int	ft_atol(char *nptr)
{
	int			a;
	long int	convert;
	int			min;

	convert = 0;
	a = 0;
	while ((nptr[a] > 8 && nptr[a] < 14) || (nptr[a] == 32))
		a++;
	min = 0;
	if (nptr[a] == '-' || nptr[a] == '+')
	{
		if (nptr[a] == '-')
			min++;
		a++;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		convert *= 10;
		convert += nptr[a] - '0';
		a++;
	}
	if (min % 2 == 1)
		convert *= -1;
	return (convert);
}

int	ft_atoi(char *nptr)
{
	int	a;
	int	convert;
	int	min;

	convert = 0;
	a = 0;
	while ((nptr[a] > 8 && nptr[a] < 14) || (nptr[a] == 32))
		a++;
	min = 0;
	if (nptr[a] == '-' || nptr[a] == '+')
	{
		if (nptr[a] == '-')
			min++;
		a++;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		convert *= 10;
		convert += nptr[a] - '0';
		a++;
	}
	if (min % 2 == 1)
		convert *= -1;
	return (convert);
}
