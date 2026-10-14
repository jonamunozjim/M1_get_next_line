/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:30:28 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/14 12:55:45 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Main.c for get_next_line.c & get_next_line_bonus.c testing
// It reads the file.txt file in the same directory than gnl_main.c

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line_bonus.h"
//#include "get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("big_line_no_nl", O_RDONLY);
	str = get_next_line (fd);
	while (str != NULL)
	{
		printf("%s", str);
		free (str);
		str = get_next_line (fd);
		if (!str)
			printf("%s", str);
	}
	close (fd);
	return (0);
}
