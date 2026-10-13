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

int	read_line(int fd, char **stor)
{
	char		*buf;
	char		*tmp;
	int			rd_out;

	buf = calloc ((BUFFER_SIZE + 1), sizeof (char));
	rd_out = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE + 1] = '\0';
	while (rd_out > 0)
	{
		tmp = ft_strjoin (*stor, buf);
		free (*stor);
		*stor = tmp;
		if (ft_strchr(*stor, '\n'))
			return (free(buf), rd_out);
		rd_out = read(fd, buf, BUFFER_SIZE);
	}
	/*
	tmp = ft_strjoin (*stor, buf);
	free (*stor);
	*stor = tmp;
	*/
	return (free(buf), rd_out);
}

char	*extract_line (char **stor)
{
	int	i;
	//int	len;
	char *line;
	char	*tmp;
	i = 0;
	//len = ft_strlen (*stor);
	while (*stor[i] && *stor[i] != '\n')
		i++;
	line = ft_substr (*stor, 0, i);
	tmp = ft_substr (*stor, 0, i);
	printf("%s-%s", line, tmp);
	free(*stor);
	stor = &tmp;
	free (tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stor;
	char		*line;
	int			rd_out;
	
	if (!stor)
		stor = calloc(3, sizeof (char));
	rd_out = read_line (fd, &stor);
	if (rd_out > 0)
	{
		line = extract_line (&stor);
		return (line);
	}
	else
		return (NULL);
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
		printf(">%s<", str);
		free (str);
	}
	close (fd);
	return (0);
}
