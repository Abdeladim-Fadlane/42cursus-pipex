/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:36:51 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/11 16:48:14 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error !\n", 8);
	exit(1);
}

char	*rasepath(char *p)
{
	while (*p != '/')
		p++;
	return (p);
}

int	check_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			return (i);
		i++;
	}
	return (0);
}

void	error(void)
{
	write(2, "command not found :\n", 20);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	char	**p;
	int		i;
	int		fd[2];
	int		pid2;
	int		pid;

	i = 0;
	if (ac < 5 || ac > 5)
		ft_error();
	if (check_env(env) == 0)
		error();
	p = ft_split(rasepath(env[check_env(env)]), ':');
	pipe(fd);
	pid = fork();
	if (pid == 0)
		first_proccess(av, ft_split(av[2], 32), p, fd);
	pid2 = fork();
	if (pid2 == 0)
		second_proccess(av, ft_split(av[3], 32), p, fd);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}
