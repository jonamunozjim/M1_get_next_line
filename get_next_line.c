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

char	*get_line(int fd, char *stor)
{
	char		*buf;
	int			rd_out;

	buf = ft_calloc ((BUFFER_SIZE + 1), sizeof (char));
	rd_out = read(fd, buf, BUFFER_SIZE);
	while (rd_out > 0)
	{
		stor = ft_strjoin (stor, buf);
		if (ft_strchr(stor, '\n'))
			return (free(buf), stor);
		rd_out = read(fd, buf, BUFFER_SIZE);
	}
	return (free(buf), stor);
}

char	*extract_line(char *stor)
{
	int		i;
	char	*line;

	i = 0;
	while (stor[i] && stor[i] != '\n')
		i++;
	if (stor[i] == '\n')
		i++;
	line = ft_substr (stor, 0, i);
	return (line);
}

char	*clean_line(char *stor)
{
	int		i;
	int		len;
	char	*rest;

	i = 0;
	len = ft_strlen (stor);
	while (stor[i] && stor[i] != '\n')
		i++;
	rest = ft_substr (stor, i + 1, len);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stor;
	char		*line;

	if (!stor)
		stor = calloc(3, sizeof (char));
	stor = get_line (fd, stor);
	if (!stor || stor[0] == '\0')
		return (free (stor), NULL);
	else
	{
		line = extract_line (stor);
		stor = clean_line (stor);
		return (line);
	}
}

int	main(void)
{
	int		fd;
	char	*str;

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
