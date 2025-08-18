/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:46:53 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/18 20:43:50 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	cpy = malloc(ft_strlen((const char *)src) + 1);
	if (!cpy || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	ptr = newstring;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[j + i] = s2[j];
		j++;
	}
	ptr[j + i] = '\0';
	free(s1);
	return (newstring);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			newlen;
	unsigned int	size_s;
	char			*strsub;
	unsigned int	i;

	size_s = ft_strlen(s);
	if (start > size_s)
		return (NULL);
	newlen = size_s - start;
	if (len > newlen)
		len = newlen;
	strsub = malloc((len + 1) * sizeof(char));
	if (strsub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		strsub[i] = s[start];
		i++;
		start++;
	}
	strsub[i] = '\0';
	return (strsub);
}
