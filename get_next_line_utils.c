/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraji <abraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:57:03 by abraji            #+#    #+#             */
/*   Updated: 2024/12/10 23:57:05 by abraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lentdst;
	size_t	lentsrc;
	size_t	copy_len;
	size_t	i;

	lentdst = ft_strlen(dst);
	lentsrc = ft_strlen(src);
	if (size <= lentdst)
		return (size + lentsrc);
	copy_len = size - lentdst - 1;
	i = 0;
	while (i < copy_len && src[i] != '\0')
	{
		dst[lentdst + i] = src[i];
		i++;
	}
	dst[lentdst + i] = '\0';
	return (lentdst + lentsrc);
}

char	*ft_strdup(const char *s)
{
	size_t	slenght;
	char	*x;
	int		i;

	slenght = ft_strlen(s) + 1;
	x = malloc(slenght * sizeof(char));
	if (x == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	x = malloc((len1 + len2) * sizeof(char) + 1);
	if (x == NULL)
		return (NULL);
	x[0] = 0;
	ft_strlcat(x, s1, len1 + 1);
	ft_strlcat(x, s2, len1 + len2 + 1);
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;

	x = (unsigned char)c;
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;
	unsigned int	i;
	size_t			j;
	size_t			slenght;

	j = 0;
	i = start;
	slenght = ft_strlen(s);
	if (start >= slenght)
		return (ft_strdup(""));
	if ((slenght - start) < len)
		len = (slenght - start);
	x = malloc(len * sizeof(char) + 1);
	if (x == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		x[j] = s[i];
		i++;
		j++;
	}
	x[j] = '\0';
	return (x);
}
