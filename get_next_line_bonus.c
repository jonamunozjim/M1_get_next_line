/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:19:25 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/14 13:46:57 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
//	Calling get_next_line function returns file content pointed by 'fd' line
//	by line until EOF. It can manage multiple file descriptors.
//  BUFFER_SIZE is set as 42 by default. It can be modified during compilation 
//  with -D BUFFER_SIZE=n (where n = size). If the file pointed to by 'fd' is
//  modified between calls, the behavior of this function is undetermined.
//
// Input parameters:
//	fd, file descriptor to be read.
//
// Return value:
//	On success, >> line read (char *).
//	On failure or EOF >> NULL.

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_line(int fd, char *stor)
{
	char		*buf;
	int			rd_out;
	char		*tmp;

	buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	rd_out = read(fd, buf, BUFFER_SIZE);
	if (rd_out < 0)
		return (free(buf), free (stor), NULL);
	buf[rd_out] = '\0';
	while (rd_out > 0)
	{
		tmp = stor;
		stor = ft_strjoin (tmp, buf);
		free (tmp);
		if (ft_strchr(stor, '\n'))
			return (free(buf), stor);
		rd_out = read(fd, buf, BUFFER_SIZE);
		buf[rd_out] = '\0';
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
	if (stor[i] == '\0')
		return (free (stor), NULL);
	rest = ft_substr (stor, i + 1, len);
	return (free(stor), rest);
}

char	*get_next_line(int fd)
{
	static char	*stor[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!stor[fd])
	{
		stor[fd] = malloc (sizeof (char));
		stor[fd][0] = '\0';
	}
	stor[fd] = get_line (fd, stor[fd]);
	if (!stor[fd] || stor[fd][0] == '\0')
		return (free (stor[fd]), stor[fd] = NULL, NULL);
	else
	{
		line = extract_line (stor[fd]);
		stor[fd] = clean_line (stor[fd]);
		return (line);
	}
}
