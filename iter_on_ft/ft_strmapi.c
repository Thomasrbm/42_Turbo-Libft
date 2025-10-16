/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 07:18:45 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:26:21 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strleng(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	int				longueur;
	char			*str;

	a = 0;
	longueur = ft_strleng(s);
	str = malloc(sizeof(char) * (longueur + 1));
	if (!str)
		return (NULL);
	while (longueur != 0)
	{
		str[a] = (*f)(a, s[a]);
		a++;
		longueur--;
	}
	str[a] = '\0';
	return (str);
}
