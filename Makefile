# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:58:02 by afadlane          #+#    #+#              #
#    Updated: 2023/02/14 16:38:22 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = pipex
CFLAGS = -Wall -Werror -Wextra 

SRC = pipex.c ft_split.c libft_utils.c main.c
SRC2 = bonus/bonus.pipex.c bonus/bonus.ft_split.c bonus/bonus.libft_utils.c bonus/bonus.main.c

cc = gcc
OBJ = ${SRC:.c=.o}
OBJ2 = ${SRC2:.c=.o}

all :${NAME}

${NAME}: ${OBJ} 
	 	${cc} ${CFLAGS} ${OBJ} -o ${NAME}
bonus:${OBJ2}
	 	${cc} ${CFLAGS} ${OBJ2} -o ${NAME}
clean :
		rm -f ${OBJ} ${OBJ2}

fclean : clean
		rm -f ${NAME} 

nor:
	norminette

re : fclean all bonus