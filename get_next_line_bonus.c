/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraji <abraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:08:56 by abraji            #+#    #+#             */
/*   Updated: 2024/12/19 21:50:28 by abraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

static char	*get_line_with_data(int fd, char *data, char *remainder)
{
	ssize_t	read_bytes;
	char	*temp;

	while (1)
	{
		read_bytes = read(fd, data, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(remainder), free(data), NULL);
		else if (read_bytes == 0)
			break ;
		data[read_bytes] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = ft_strjoin(remainder, data);
		free(remainder);
		remainder = temp;
		if (ft_strchr(data, '\n'))
			break ;
	}
	free(data);
	return (remainder);
}

static char	*extracted_line(char *remainder, char *line)
{
	int		counter;

	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	if (line[counter] == '\0')
		return (NULL);
	remainder = ft_substr(line, counter + 1, ft_strlen(line) - counter);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[counter + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*data;
	static char	*remainder[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = malloc((size_t)BUFFER_SIZE + 1);
	if (!data)
		return (NULL);
	line = get_line_with_data(fd, data, remainder[fd]);
	if (!line)
		return (free(line), NULL);
	remainder[fd] = extracted_line(remainder[fd], line);
	return (line);
}
