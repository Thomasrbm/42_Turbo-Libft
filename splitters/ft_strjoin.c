/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:45:34 by throbert          #+#    #+#             */
/*   Updated: 2025/10/17 03:07:15 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strleng(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_subjoin(char *s1, char *s2, char *s3)
{
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (s1[c] != '\0')
	{
		s3[c + d] = s1[c];
		c++;
	}
	while (s2[d] != '\0')
	{
		s3[c + d] = s2[d];
		d++;
	}
	s3[c + d] = '\0';
	return (s3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		a;
	int		b;

	a = ft_strleng((char *)s1);
	b = ft_strleng((char *)s2);
	if (s1 == 0 || s2 == 0)
		return (NULL);
	s3 = malloc(sizeof(char) * (a + b + 1));
	if (!s3)
		return (NULL);
	s3 = ft_subjoin(s1, s2, s3);
	return (s3);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*str_part1;
	char	*str_final;

	str_part1 = ft_strjoin(s1, s2);
	str_final = ft_strjoin(str_part1, s3);
	free(str_part1);
	return (str_final);
}
