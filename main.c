/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:36:51 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/24 11:20:18 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error check if you  enter 5 arg !\n", 34);
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

void	ft_error1(void)
{
	write(2, "command not found :\n", 20);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int			i;
	t_object	*lst;

	lst = malloc(sizeof(t_object));
	lst->envp = env;
	i = 0;
	if (ac != 5)
		ft_error();
	if (check_env(lst->envp) == 0)
		ft_error1();
	lst->p = ft_split(rasepath(lst->envp[check_env(lst->envp)]), ':');
	pipe(lst->fd);
	lst->pid = fork();
	if (lst->pid == 0)
		first_proccess(av, ft_split(av[2], 32), lst);
	lst->pid2 = fork();
	if (lst->pid2 == 0)
		second_proccess(av, ft_split(av[3], 32), lst);
	close(lst->fd[1]);
	close(lst->fd[0]);
	waitpid(lst->pid, NULL, 0);
	waitpid(lst->pid2, NULL, 0);
}
