/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:30:05 by rbardet-          #+#    #+#             */
/*   Updated: 2025/03/23 16:08:43 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_putstr_fd_int(char *s, int fd)
{
	while (s && *s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
	return (1);
}

// int main(void)
// {
// 	char str[] = "Lille OSC";
// 	ft_putstr_fd(str, 1);
// 	return(0);
// }
