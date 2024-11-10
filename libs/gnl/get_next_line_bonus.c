/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:01:03 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/05 10:01:07 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	int		byte;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	byte = 1;
	while (!ft_strchr(buffer, '\n') && byte > 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!ft_strlen(buffer[fd]))
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_bufferupdt(buffer[fd]);
	return (line);
}
