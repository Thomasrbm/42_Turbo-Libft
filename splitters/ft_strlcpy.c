/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:47 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:29:52 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (src[b] != '\0')
		b++;
	if (size == 0)
		return (b);
	while (a < size - 1 && src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (b);
}
// int main(void)
// {
// 	char source[]="Lille OSC";
// 	char destination[10];
// 	printf("%zu\n", ft_strlcpy(destination, source, 30));
// 	return(0);
// }
