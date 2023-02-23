/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:24 by afadlane          #+#    #+#             */
/*   Updated: 2023/02/23 15:08:30 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct object
{
	char	**envp;
	int		pid2;
	int		pid3;
	int		pid;
	char	**p;
	int		fd[2];
}			t_object;

char		**ft_split(char *s, char c);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		first_proccess(char **av, char **ptr, t_object *lst);
void		second_proccess(char **av, char **ptr2, t_object *lst, int track,
				int k);
void		midlle_proccess(char **av, char **ptr2, t_object *lst, int k,
				int track);
char		*get_cmd(char **ptr, char **p);
#endif
