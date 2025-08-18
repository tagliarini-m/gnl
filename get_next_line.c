/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:51:07 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/18 20:40:59 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *stash, char *buffer)
{
	free(stash);
	stash = NULL;
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*read_fd(char *stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!(ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_all(stash, buffer));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free_all(stash, buffer));
	}
	free(buffer);
	return (stash);
}

char	*next_line(char **line, char *stash)
{
	int		i;
	char	*leftover;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	*line = ft_substr(stash, 0, i + 1);
	if (!*line)
		return (free_all(*line, stash));
	leftover = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	if (!leftover)
		return (free_all(leftover, stash));
	free(stash);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_fd(stash, fd);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = next_line(&line, stash);
	return (line);
}

// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("teste.txt", O_RDONLY);

// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return 0;
// }
