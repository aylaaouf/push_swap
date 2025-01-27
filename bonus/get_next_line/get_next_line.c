/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 02:46:59 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/27 23:15:42 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	char	*new;
	int		bytes_read;

	temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		new = buffer;
		buffer = ft_strjoin(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
		free(new);
	}
	free(temp_buffer);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	char	*new_line_pos;
	size_t	len;
	size_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	new_line_pos = ft_strchr(buffer, '\n');
	if (new_line_pos)
		len = new_line_pos - buffer + 1;
	else
		len = ft_strlen(buffer);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*new_line_pos;

	new_line_pos = ft_strchr(buffer, '\n');
	if (!new_line_pos)
		return (NULL);
	new_buffer = ft_strdup(new_line_pos + 1);
	if (!new_buffer)
		return (NULL);
	free(buffer);
	return (new_buffer);
}

char	*helper(int fd, char *buffer)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer != NULL)
			free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*new_buffer;

	helper(fd, buffer);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	new_buffer = update_buffer(buffer);
	if (!new_buffer)
	{
		return (NULL);
		buffer = NULL;
	}
	else
		buffer = new_buffer;
	return (line);
}
