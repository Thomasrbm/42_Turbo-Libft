/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 03:03:35 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:29:47 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len])
		dest_len++;
	while (i < nb && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	a = 0;
	b = 0;
	c = 0;
	while (dest[a] != '\0' && a < size)
		a++;
	while (src[b] != '\0')
		b++;
	if (size <= a)
		return (a + b);
	d = a;
	while (src[c] != '\0' && (d + 1) < size)
	{
		dest[d] = src[c];
		d++;
		c++;
	}
	dest[d] = '\0';
	return (a + b);
}
