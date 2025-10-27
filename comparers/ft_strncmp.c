/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:49:45 by throbert          #+#    #+#             */
/*   Updated: 2025/10/27 17:05:24 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	a;

	a = 0;
	while (s1[a] && s2[a] && s1[a] == s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] && s2[a] && a < n - 1 && s1[a] == s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
