/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:36:31 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/10 18:52:46 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char **ptr, char **p)
{
	int		l;
	int		i;
	int		k;
	char	*buff;

	i = 0;
	l = 0;
	buff = "";
	while (p[l])
		l++;
	while (i < l)
	{
		buff = ft_strjoin(p[i], "/");
		buff = ft_strjoin(buff, ptr[0]);
		k = access(buff, F_OK);
		if (k == 0)
			break ;
		i++;
	}
	if (k == -1)
		exit(0);
	return (buff);
}

void	first_proccess(char **av, char **ptr, char **p, int *fd)
{
	int	fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror(av[1]);
		exit(1);
	}
	dup2(fd1, 0);
	close(fd[0]);
	dup2(fd[1], 1);
	execve(get_cmd(ptr, p), ptr, NULL);
}

void	second_proccess(char **av, char **ptr2, char **p, int *fd)
{
	int	fd2;

	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
		perror(av[4]);
	dup2(fd2, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	execve(get_cmd(ptr2, p), ptr2, NULL);
}
