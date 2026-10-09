/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:26:52 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/08 13:20:42 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//BUFFER_SIZE is added during compliation with -D BUFFER_SIZE=n (n = size)

#include "get_next_line.h"

int	read_line(int fd, char *buf, char *stor)
{
	int	i;
	int	j;
	int	rd_out;

	i = 0;
	j = 0;
	rd_out = read(fd, buf, BUFFER_SIZE);
	while (rd_out > 0)
	{
		while (i < BUFFER_SIZE)
		{
			stor[j] = buf[i];
			if (buf[i] == '\n')
			{
				while (i < BUFFER_SIZE)
				{
					stor[j] = buf[i + j];
					i++;
				}
				return (rd_out);
			}
			j++;
			i++;
		}
		i = 0;
		rd_out = read(fd, buf, BUFFER_SIZE);
	}
	return (rd_out);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stor;
	char		*line;
	int	rd_out;

	buf = malloc (BUFFER_SIZE * sizeof (char));
	line = malloc (BUFFER_SIZE + 1 * sizeof (char));
	read_line (fd, )
	if (rd_out <= 0)
		return (NULL);
	return (free (buf), line);
//	return (free (buf), line); //I need to free TMP also. To check when!
}

int main(void)
{
	int	    fd;
    char    *str;
    
	str = malloc (300 * sizeof (char));
	str = "Ho";
	fd = open("file.txt", O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line (fd);
		printf("%s", str);
		free (str);
	}
	close (fd);
	return (0);
}
