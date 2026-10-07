/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:28:54 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 14:47:46 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h> //for testing only

char    *get_next_line(int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif
