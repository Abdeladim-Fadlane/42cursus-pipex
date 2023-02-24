/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.libft_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:26 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/24 11:20:39 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		return (s1);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = 0;
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	p = "";
	if (!s1)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	p = (char *)haystack;
	i = 0;
	if (!needle[i])
		return (p);
	if (!len || !p[i])
		return (NULL);
	while (p[i])
	{
		j = 0;
		while (p[i + j] == needle[j] && i + j < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return (&p[i]);
		i++;
	}
	return (NULL);
}
