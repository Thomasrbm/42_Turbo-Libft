/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:14:16 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:24:50 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbr(int n)
{
	int	a;

	a = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		a++;
	while (n != 0)
	{
		n /= 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int			longueur;
	char		*str;
	int			sign;

	sign = 1;
	longueur = ft_nbr(n);
	str = malloc(sizeof(char) * (longueur + 1));
	if (!str)
		return (NULL);
	str[longueur] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		sign *= -1;
	}
	while (n != 0)
	{
		longueur--;
		str[longueur] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	return (str);
}
