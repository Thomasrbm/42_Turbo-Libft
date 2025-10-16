/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:30:39 by throbert          #+#    #+#             */
/*   Updated: 2025/10/16 21:28:18 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[a] && a < len)
	{
		if (big[a] == little[0])
		{
			b = 0;
			while (little[b] && (a + b) < len && big[a + b] == little[b])
			{
				b++;
			}
			if (little[b] == '\0')
				return ((char *)&big[a]);
		}
		a++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char big[] = "LILLE OSC";
// 	char little[] = "ILL";
// 	printf("%s\n", ft_strnstr(big, little, 4));
// 	return(0);
// }
