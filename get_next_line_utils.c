/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:24:41 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 14:47:31 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include get_next_line.h

void	ft_putstr_fd(char *str, int fd)
{
	while(str[i])
		i++;
	write (fd, str, i);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}