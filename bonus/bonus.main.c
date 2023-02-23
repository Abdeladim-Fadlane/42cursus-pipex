/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:36:51 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/23 16:34:15 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error you put less than forth args !\n", 36);
	exit(0);
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
	int			track_fd;

	lst = malloc(sizeof(t_object));
	lst->envp = env;
	i = 0;
	if (check_env(lst->envp) == 0)
		ft_error1();
	lst->p = ft_split(rasepath(lst->envp[check_env(lst->envp)]), ':');
	if (ac > 4)
	{
		if (pipe(lst->fd) < 0)
			ft_error();
		first_proccess(av, ft_split(av[2], 32), lst);
		close(lst->fd[1]);
		track_fd = lst->fd[0];
		i += 3;
		while (ac - 2 > i)
		{
			if (pipe(lst->fd) < 0)
				ft_error();
			if (i < ac - 2)
				midlle_proccess(av, ft_split(av[i], 32), lst, i, track_fd);
			close(lst->fd[1]);
			close(track_fd);
			track_fd = lst->fd[0];
			i++;
		}
		second_proccess(av, ft_split(av[ac - 2], 32), lst, track_fd, ac - 1);
		close(track_fd);
	}
	else
		ft_error();
	while (wait(NULL) != -1)
		;
}
